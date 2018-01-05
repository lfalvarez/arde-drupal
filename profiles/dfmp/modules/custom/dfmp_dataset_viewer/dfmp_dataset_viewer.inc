<?php
/**
 * @file
 * Dataset viewer inc file.
 */
require_once DRUPAL_ROOT . "/profiles/dfmp/libraries/markdown_michelf/Markdown.inc.php";
use \Michelf\Markdown;
define('IMAGES_PER_PAGE_MINI', 8);
define('IMAGES_PER_PAGE', 24);

function dfmp_dataset_viewer_all_table() {

  global $user;

  $user = user_load($user->uid);

  $options = array(
    'api_key' => $user->field_user_api_key[LANGUAGE_NONE][0]['value'],
  );

  $dataset = CkanApi::getInstance()->action('user_get_assets', $options);
  $ckan_licenses = CkanApi::getInstance()->action('license_list', $options);
  $licenses = array();
  foreach ($ckan_licenses as $item) {
    $licenses[$item->id] = $item->title;
  }

  $header = array(
    t('Thumbnail'),
    t('Name'),
    t('Owner'),
    t('License'),
    t('Size'),
    t('Details')
  );

  $rows = array();
  foreach ($dataset->resources as $res) {
    $type = explode('/', $res->mimetype);
    if ($type[0] == 'video') {
      $url = preg_replace('#^https?://#', '', $res->url);
      $media = '<video width="500" height="300">
   <source src="/' . $url . '">
</video>';
    }
    else {
      $media =  isset($res->thumb) && $res->thumb ? theme('image', array('path' => $res->thumb)) : '';
    }

      $rows[] = array($media,
        $res->name,
        $res->owner_name,
        $licenses[$res->license_id],
        round($res->size / 1024) . 'KB',
        l(t('Details'), 'asset/' . $res->id),
      );
  }

  return theme('dfmp_dataset_viewer_user_resources', array('header' => $header, 'rows' => $rows));
}


function dfmp_dataset_viewer_asset_details($id) {
  if (!$id) {
    return t('Asset not found.');
  }

  $asset = CkanApi::getInstance()->action('resource_show', array(
    'data' => array(
      'id' => $id
    ),
  ));

  if ($asset->state != 'active') {
    return t('Asset has been removed.');
  }

  return theme('dfmp_dataset_viewer_asset_details', array('asset' => $asset));
}

function _dfmp_dataset_viewer_asset_gallery_prepare($query) {
  $assets = CkanApi::getInstance()->action('dfmp_all_assets', array(
    'data' => $query
  ));

  // Generate path alias if not exists
  foreach ($assets as $asset) {
    $real_path = 'gallery/view/' . $asset->asset->id;
    if (empty($asset->asset->name) && !empty($asset->title)) {
      $asset->asset->name = $asset->title;
    }
    elseif (empty($asset->asset->name) && !empty($asset->name)) {
      $asset->asset->name = $asset->name;
    }
    if (!empty($asset->asset->name) && !drupal_lookup_path('alias', $real_path)) {
      $name_inc = $name = str_replace('#', '', $asset->asset->name);
      $i = 0;
      while (TRUE) {
        $name_inc = $i > 0 ? $name . '-' . $i : $name;
        if (!drupal_lookup_path('source', 'gallery/' . $name_inc)) {
          break;
        }
        $i++;
      }
      $alias = array('source' => $real_path, 'alias' => 'gallery/' . $name_inc);
      path_save($alias);
    }
  }

  // Prepear gallery for rendering
  $gallery = array();

  $class = 1;
  foreach ($assets as $item) {
    if ($item->dfmp_total && $item->private == false && $item->state == 'active') {
      $gallery[] = theme('dfmp_dataset_viewer_image_render', array(
          'item' => $item,
          'class' => $class,
      ));
      if ($class == 4) {
        $class = 1;
      }
      else {
        $class++;
      }
    }
  }
  return array('gallery' => $gallery, 'assets' => $assets);
}

function dfmp_dataset_viewer_assets_gallery($query) {
  $data = _dfmp_dataset_viewer_asset_gallery_prepare($query);
  $gallery = $data['gallery'];
  $assets = $data['assets'];

  if (isset($_GET['callback'])) {
    drupal_json_output($gallery);
    exit();
  }

  if (!empty($assets[0]->dfmp_site_resources_ammount)) {
    $max_pages = ceil($assets[0]->dfmp_site_resources_ammount/GALLERY_IMAGES_LIMIT);
    drupal_add_js(array('infinity_scroll' => array('max_pages' => $max_pages)), 'setting');
  }

  drupal_add_js(drupal_get_path('module', 'dfmp_dataset_viewer') . '/theme/js/inf-scroll.js');
  drupal_add_js(drupal_get_path('module', 'dfmp_dataset_viewer') . '/theme/js/imagesLoaded.js');
  drupal_add_css(drupal_get_path('module', 'dfmp_dataset_viewer') . '/theme/css/custom.css');

  return theme('dfmp_dataset_viewer_assets_gallery', array('gallery' => $gallery, 'count' => isset($assets->count) ? $assets->count : 0));
}

/**
 * Formats coordinates so that degrees, minutes and seconds are shown
 *
 * @param $dec
 * @return array
 */
function __dfmp_dataset_viewer_location_coordinates_format($latitude, $longitude) {

  $latitude_direction = $latitude < 0 ? 'S' : 'N';
  $longitude_direction = $longitude < 0 ? 'W' : 'E';

  $latitude_notation = $latitude < 0 ? '-' : '';
  $longitude_notation = $longitude < 0 ? '-' : '';

  $latitude_in_degrees = floor(abs($latitude));
  $longitude_in_degrees = floor(abs($longitude));

  $latitude_decimal = abs($latitude) - $latitude_in_degrees;
  $longitude_decimal = abs($longitude) - $longitude_in_degrees;

  $_precision = 3;
  $latitude_minutes = round($latitude_decimal * 60, $_precision);
  $longitude_minutes = round($longitude_decimal * 60, $_precision);

  return sprintf('%s%s° %s %s %s%s° %s %s',
    $latitude_notation,
    $latitude_in_degrees,
    $latitude_minutes,
    $latitude_direction,
    $longitude_notation,
    $longitude_in_degrees,
    $longitude_minutes,
    $longitude_direction
  );

}

function __dfmp_dataset_viewer_mime_type($type) {
  $mime = explode('/', $type);
  if ($mime[0] == 'video') {
    return TRUE;
  }
}

function dfmp_dataset_viewer_gallery_view($id, $query, $show_pager = TRUE) {
  $get = $_GET;
  unset($get['q'], $get['callback']);
  $cbr_collection = drupal_get_path_alias(current_path());
  $cbr_collection = explode('/', $cbr_collection);
  $get['col_title'] = $cbr_collection[1] ? $cbr_collection[1] : 'collection';
  $offset = 0;
  $pager = '';
  $check_local = '';
  $local_btn_msg = t("Download displayed images");
  if ($show_pager) {
    $offset = isset($_GET['page']) && is_numeric($_GET['page']) ? (int)$_GET['page'] * IMAGES_PER_PAGE : 0;
  }

  $assets = CkanApi::getInstance()->action('search_item', array(
    'api_key' => $api_key,
    'data' => array(
      'id' => $id,
      'query_string' => array(
        'name' => $_GET['search_title'],
        'tags' => isset($_GET['search_tags']) ? strtolower($_GET['search_tags']) : NULL,
        'date' => isset($_GET['search_date']) ? $_GET['search_date'] : NULL,
        'type' => $_GET['search_type'],
        'licence' => $_GET['licence'],
        'include_description' => (bool)$_GET['include_description'],
      ),
      'limit' => IMAGES_PER_PAGE,
      'offset' => $offset,
    )
  ));

  // PHP Markdown library
  $markdown = new Markdown();

  // Converting markdown to html format
  $assets->description = $markdown->defaultTransform($assets->description);
  $assets->description = strip_tags($assets->description, '<a><br><em><strong>');

  if (module_exists('dfmp_file_uploader')) {
    $check_local = dfmp_file_uploader_check_local_files($assets);
    if (empty($check_local)) {
      $local_btn_msg = t("This page has only images from Flickr or Twitter, which can't be downloaded in a zip file. View each image individually to download.");
    }
  }

  if ($show_pager) {
    $current_page = pager_default_initialize($assets->count, IMAGES_PER_PAGE);
    $pager = theme('pager', array('tags' => array('« First', 'Previous', '...', 'Next', 'Last »')));
  }

  if (!isset($assets->title) || !$assets->title) {
    return __dfmp_dataset_viewer_not_found_block(t('Gallery not found'));
  }

  if (!empty($assets->count)) {
    $max_pages = ceil($assets->count/IMAGES_PER_PAGE);
    drupal_add_js(array('infinity_scroll' => array('max_pages' => $max_pages)), 'setting');
  }

  drupal_add_js(drupal_get_path('module', 'dfmp_dataset_viewer') . '/theme/js/masonry.js');
  drupal_add_js(drupal_get_path('module', 'dfmp_dataset_viewer') . '/theme/js/inf-scroll.js');
  drupal_add_js(drupal_get_path('module', 'dfmp_dataset_viewer') . '/theme/js/imagesLoaded.js');
  drupal_add_js(drupal_get_path('module', 'dfmp_dataset_viewer') . '/theme/js/custom.js');
  drupal_add_css(drupal_get_path('module', 'dfmp_dataset_viewer') . '/theme/css/custom.css');

  $pages = ceil(count($assets->records)/IMAGES_PER_PAGE) - 1;
  $gallery = array_slice($assets->records, 0, IMAGES_PER_PAGE);
  $images = _dfmp_dataset_viewer_prepare_gallery_view($gallery, $id);
  $form = drupal_get_form('dfmp_search_result_filter_form');
  $dwn_form = drupal_get_form('dfmp_file_uploader_dwn_collection', $check_local, $get);

  drupal_set_title($assets->title);

  return theme('dfmp_dataset_viewer_gallery_view', array(
    'gallery' => $images,
    'dataset_id' => $id,
    'backlink' => $assets->backlink,
    'item_count' => $assets->count,
    'pages' => $pages,
    'assets' => $assets,
    'offset' => $offset,
    'form' => $form,
    'get_query' => $get,
    'count_local_files' => count($check_local),
    'dwn_form' => $dwn_form,
    'dwn_btn_msg' => $local_btn_msg
  )) . $pager;
}

function _dfmp_dataset_viewer_prepare_gallery_view($gallery, $dataset_id = NULL) {
  $images = array();

  $class = 1;

  foreach ($gallery as $item) {
    $item = __dfmp_dataset_viewer_check_file($item);

    $item->cclass = $class;

    $dataset_id = !$dataset_id ? $item->id : $dataset_id;
    if (!empty($item->path)) {
      $images[] = theme('dfmp_dataset_viewer_asset_list_item', array(
        'item' => $item,
        'dataset_id' => $dataset_id,
      ));

      if ($class == 4) {
        $class = 1;
      }
      else {
        $class++;
      }
    }
  }
  return $images;
}

function __dfmp_dataset_viewer_check_file(&$item) {
  $external = FALSE;
  $source = '';
  $path = '';

  if (strpos($item->url, 'http') !== FALSE) {
    $req_res = drupal_http_request($item->url, array('method' => 'HEAD'));

    if ($req_res->code == 200) {
      $external = TRUE;
    }
  }

  if ($external) {
    $source = 'imagecache_external';
    $path = $item->url;
  }
  elseif (file_exists(DRUPAL_ROOT . urldecode($item->url))) {
    $source = 'image_style';
    $path = str_replace('/sites/default/files', 'public://', urldecode($item->url));
  }
  $item->source = $source;
  $item->path = $path;

  return $item;
}

function dfmp_dataset_viewer_gallery_single_asset($dataset_id, $asset_id, $query) {
  $gallery = CkanApi::getInstance()->action('resource_items', array(
    'data' => array(
      'id' => $dataset_id,
      'item' => $asset_id,
    )
  ));

  if (!isset($gallery->records) || !$gallery->records) {
    //return t('Asset not found');
    return __dfmp_dataset_viewer_not_found_block(t('Asset not found'));
  }

  drupal_add_library('system', 'ui.dialog');
  drupal_add_js(drupal_get_path('module', 'dfmp_dataset_viewer') . '/theme/js/mark_inappropriate.js');

  $item = reset($gallery->records);

  // We need to show "Twitter License" for twitter items.
  if (isset($item->metadata->source) && $item->metadata->source == 'twitter') {
    $item->metadata->license_name = t('Twitter Licence');
  }

  drupal_set_title($item->name);

  drupal_add_js(drupal_get_path('module', 'dfmp_dataset_viewer') . '/theme/js/custom.js');

  return theme('dfmp_dataset_viewer_gallery_single_view', array(
    'asset' => __dfmp_dataset_viewer_check_file($item),
    'backlink' => 'gallery/view/' . $dataset_id,
    'dataset_id' => arg(2),
    'group_name' => $gallery,
    'group_url' => $dataset_id
  ));
}

/**
 * Page Not Found block content
 */
function dfmp_dataset_viewer_page_not_found() {
  return __dfmp_dataset_viewer_not_found_block(t('Page not found'));
}

function __dfmp_dataset_viewer_not_found_block($error_message, $query = array(), $form = '') {
  $data = _dfmp_dataset_viewer_asset_gallery_prepare($query);
  $gallery = $data['gallery'];

  if (isset($_GET['callback'])) {
    drupal_json_output($gallery);
    exit();
  }

  drupal_add_js(drupal_get_path('module', 'dfmp_dataset_viewer') . '/theme/js/imagesLoaded.js');
  drupal_add_css(drupal_get_path('module', 'dfmp_dataset_viewer') . '/theme/css/custom.css');

  return theme('dfmp_dataset_viewer_not_found_block', array(
    'errormessage' => $error_message,
    'gallery' => $gallery,
    'form' => $form,
  ));
}

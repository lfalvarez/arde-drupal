<?php
/**
 * @file
 * dfmp_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dfmp_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function dfmp_page_image_default_styles() {
  $styles = array();

  // Exported image style: 300x300.
  $styles['300x300'] = array(
    'label' => '300X300',
    'effects' => array(),
  );

  // Exported image style: 300x300crop.
  $styles['300x300crop'] = array(
    'label' => '300x300Crop',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: asset.
  $styles['asset'] = array(
    'label' => 'Asset',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 672,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: gallery.
  $styles['gallery'] = array(
    'label' => 'Gallery',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 358,
          'height' => 220,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: original.
  $styles['original'] = array(
    'label' => 'Original',
    'effects' => array(),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function dfmp_page_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

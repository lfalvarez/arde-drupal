<?php
/*
  Preprocess
*/

define('SECONDS_IN_HOUR', 3600);

function dfmp_preprocess_html(&$vars) {
  //  kpr($vars['content']);
  $font_css = array(
    '#tag' => 'link',
    '#attributes' => array(
      'rel' => 'stylesheet',
      'href' => 'http://fonts.googleapis.com/css?family=Open+Sans:400italic,600',
      'type' => 'text/css',
    ),
    '#weight' => '88',
  );
  drupal_add_html_head($font_css, 'font_css');
}

function dfmp_preprocess_page(&$vars,$hook) {
  //typekit
  //drupal_add_js('http://use.typekit.com/XXX.js', 'external');
  //drupal_add_js('try{Typekit.load();}catch(e){}', array('type' => 'inline'));

  //webfont
  //drupal_add_css('http://cloud.webtype.com/css/CXXXX.css','external');

  //googlefont
  //  drupal_add_css('http://fonts.googleapis.com/css?family=Bree+Serif','external');

  // If this is a panel page, add template suggestions.
  // Must have Ctools Page Manager enabled. Uncomment to use.
  if (module_exists('page_manager')) {
    if($panel_page = page_manager_get_current_page()) {
      // add a generic suggestion for all panel pages
      $vars['theme_hook_suggestions'][] = 'page__panel';

      // add the panel page machine name to the template suggestions
      $vars['theme_hook_suggestions'][] = 'page__' . $panel_page['name'];

      //add a body class for good measure
      $body_classes[] = 'page-panel';
    }
  }
}

function dfmp_preprocess_region(&$vars,$hook) {
  //  kpr($vars['content']);
}

function dfmp_preprocess_block(&$vars, $hook) {
  //  kpr($vars['content']);

  //lets look for unique block in a region $region-$blockcreator-$delta
   $block =
   $vars['elements']['#block']->region .'-'.
   $vars['elements']['#block']->module .'-'.
   $vars['elements']['#block']->delta;

  // print $block .' ';
   switch ($block) {
     case 'header-menu_block-2':
       $vars['classes_array'][] = '';
       break;
     case 'sidebar-system-navigation':
       $vars['classes_array'][] = '';
       break;
    default:

    break;

   }


  switch ($vars['elements']['#block']->region) {
    case 'header':
      $vars['classes_array'][] = '';
      break;
    case 'sidebar':
      $vars['classes_array'][] = '';
      $vars['classes_array'][] = '';
      break;
    default:

      break;
  }

}

function dfmp_preprocess_node(&$vars,$hook) {
  //  kpr($vars['content']);
}

function dfmp_preprocess_comment(&$vars,$hook) {
  //  kpr($vars['content']);
}

function dfmp_preprocess_field(&$vars,$hook) {
  //  kpr($vars['content']);
  //add class to a specific field
  switch ($vars['element']['#field_name']) {
    case 'field_ROCK':
      $vars['classes_array'][] = 'classname1';
    case 'field_ROLL':
      $vars['classes_array'][] = 'classname1';
      $vars['classes_array'][] = 'classname2';
      $vars['classes_array'][] = 'classname1';
    case 'field_FOO':
      $vars['classes_array'][] = 'classname1';
    case 'field_BAR':
      $vars['classes_array'][] = 'classname1';
    case 'field_BAR':
      $vars['classes_array'][] = 'classname1';
    default:
      break;
  }
}

function dfmp_process_field(&$variables, $hook) {
  // The default theme implementation is a function, so template_process() does
  // not automatically run, so we need to flatten the classes and attributes
  // here. For best performance, only call drupal_attributes() when needed, and
  // note that template_preprocess_field() does not initialize the
  // *_attributes_array variables.
  
  $variables['classes_array'][] = $variables['element']['#field_name'];
  
  $variables['classes'] = implode(' ', $variables['classes_array']);
  $variables['attributes'] = empty($variables['attributes_array']) ? '' : drupal_attributes($variables['attributes_array']);
  $variables['title_attributes'] = empty($variables['title_attributes_array']) ? '' : drupal_attributes($variables['title_attributes_array']);
  $variables['content_attributes'] = empty($variables['content_attributes_array']) ? '' : drupal_attributes($variables['content_attributes_array']);
  foreach ($variables['items'] as $delta => $item) {
    $variables['item_attributes'][$delta] = empty($variables['item_attributes_array'][$delta]) ? '' : drupal_attributes($variables['item_attributes_array'][$delta]);
  }
}

function dfmp_preprocess_maintenance_page(){
  //  kpr($vars['content']);
}


/**
 * Process variables for entity.tpl.php.
 */
function dfmp_preprocess_entity(&$variables) {

  //For beans on home page
  if($variables['entity_type'] == variable_get('bean_type','bean')){
    if($variables['view_mode'] == variable_get('bean_view_mode_image_and_link','image_and_link')){

      $bean_entity = $variables['elements']['#entity'];
      $resource_id_field = $bean_entity->field_resource_id;

      $resource_id = isset($bean_entity->field_resource_id[LANGUAGE_NONE][0]['value']) ? $bean_entity->field_resource_id[LANGUAGE_NONE][0]['value'] : '';

      if ($resource_id_field) {
        $variables['content']['field_link']['#items'][0]['url'] = 'gallery/view/' . $resource_id;
      }

      $variables['link'] = array(
        'url' => $variables['content']['field_link']['#items'][0]['url'],
        'query' => $variables['content']['field_link']['#items'][0]['query'],
      );

      $variables['elements']['#entity'] = $bean_entity;

      $cache_count = cache_get('bid_' . $bean_entity->bid . '_ckan_request_cache');

      $variables['elements']['#entity']->asset_count = 0;
      if($cache_count && $cache_count->data){

        $variables['elements']['#entity']->asset_count = $cache_count->data;
      }
      else{
        if($resource_id_field){

          $assets = CkanApi::getInstance()->action('resource_items', array(
            'data' => array(
              'id' => $resource_id_field[LANGUAGE_NONE][0]['value'],
              'offset' => 0,
              'limit' => 0,
            )
          ));
        }
        else {
          $value = $bean_entity->field_link[LANGUAGE_NONE][0]['query'];

          $assets = CkanApi::getInstance()->action('search_item', array(
            'data' => array(
              'query_string' => array(
                'name' => isset($value['search_title']) ? $value['search_title'] : NULL,
                'tags' => isset($value['search_tags']) ? $value['search_tags'] : NULL,
                'date' => isset($value['search_date']) ? $value['search_date'] : NULL,
                'type' => isset($value['search_type']) ? $value['search_type'] : NULL,
                'licence' => isset($value['licence']) ? $value['licence'] : NULL,
                'include_description' => isset($value['include_description']) ? (bool)$value['include_description'] : FALSE,
              ),
              'limit' => 8,
              'offset' => 0,
            )
          ));

        }

        $assets_number = isset($assets->count) ? $assets->count : 0;

        cache_set('bid_' . $bean_entity->bid . '_ckan_request_cache', $assets_number, $bin = 'cache', SECONDS_IN_HOUR);

        $variables['elements']['#entity']->asset_count = $assets_number;

      }
    }
  }

  $variables['view_mode'] = $variables['elements']['#view_mode'];
  $entity_type = $variables['elements']['#entity_type'];
  $variables['entity_type'] = $entity_type;
  $entity = $variables['elements']['#entity'];
  $variables[$variables['elements']['#entity_type']] = $entity;
  $info = entity_get_info($entity_type);

  $variables['title'] = check_plain(entity_label($entity_type, $entity));

  $uri = entity_uri($entity_type, $entity);
  $variables['url'] = $uri ? url($uri['path'], $uri['options']) : FALSE;

  if (isset($variables['elements']['#page'])) {
    // If set by the caller, respect the page property.
    $variables['page'] = $variables['elements']['#page'];
  }
  else {
    // Else, try to automatically detect it.
    $variables['page'] = $uri && $uri['path'] == $_GET['q'];
  }

  // Helpful $content variable for templates.
  $variables['content'] = array();
  foreach (element_children($variables['elements']) as $key) {
    $variables['content'][$key] = $variables['elements'][$key];
  }

  if (!empty($info['fieldable'])) {
    // Make the field variables available with the appropriate language.
    field_attach_preprocess($entity_type, $entity, $variables['content'], $variables);
  }
  list(, , $bundle) = entity_extract_ids($entity_type, $entity);

  // Gather css classes.
  $variables['classes_array'][] = drupal_html_class('entity-' . $entity_type);
  $variables['classes_array'][] = drupal_html_class($entity_type . '-' . $bundle);
  $variables['classes_array'][] = drupal_html_class($variables['view_mode']);

  // Add RDF type and about URI.
  if (module_exists('rdf')) {
    $variables['attributes_array']['about'] = empty($uri['path']) ? NULL: url($uri['path']);
    $variables['attributes_array']['typeof'] = empty($entity->rdf_mapping['rdftype']) ? NULL : $entity->rdf_mapping['rdftype'];
  }

  // Add suggestions.
  $variables['theme_hook_suggestions'][] = $entity_type;
  $variables['theme_hook_suggestions'][] = $entity_type . '__' . $bundle;
  $variables['theme_hook_suggestions'][] = $entity_type . '__' . $bundle . '__' . $variables['view_mode'];
  if ($id = entity_id($entity_type, $entity)) {
    $variables['theme_hook_suggestions'][] = $entity_type . '__' . $id;
  }
}

function dfmp_preprocess_panels_pane(&$vars) {  
  if (isset($vars['pane']->type) && $vars['pane']->type == 'page_title' && arg(0) == "user") {
    if (!user_is_logged_in()) {
      $vars['title'] = t('Login');
    }
    if (arg(1) == "register") {
      $vars['title'] = t('Register');
    }
  }

  if ($vars['pane']->type == 'page_title' && (arg(0) == 'user' && is_numeric(arg(1)))) {
    $vars['title'] = t('My account');
  }
  
}

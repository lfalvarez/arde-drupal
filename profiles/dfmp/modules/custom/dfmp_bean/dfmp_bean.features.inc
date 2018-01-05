<?php
/**
 * @file
 * dfmp_bean.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dfmp_bean_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function dfmp_bean_image_default_styles() {
  $styles = array();

  // Exported image style: banner_mobile.
  $styles['banner_mobile'] = array(
    'label' => 'Banner Mobile',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 320,
          'height' => 260,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

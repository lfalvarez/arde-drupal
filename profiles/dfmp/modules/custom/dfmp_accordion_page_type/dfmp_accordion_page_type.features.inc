<?php
/**
 * @file
 * dfmp_accordion_page_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dfmp_accordion_page_type_ctools_plugin_api($module = NULL, $api = NULL) {
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
 * Implements hook_node_info().
 */
function dfmp_accordion_page_type_node_info() {
  $items = array(
    'accordion_page' => array(
      'name' => t('Accordion Page'),
      'base' => 'node_content',
      'description' => t('Pages that are primary using accordions for their output'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

<?php
/**
 * @file
 * dfmp_accordion_page_type.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function dfmp_accordion_page_type_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_accodrion|full';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_accodrion';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_accordion_title',
        1 => 'field_accordion_body',
      ),
    ),
    'fields' => array(
      'field_accordion_title' => 'ds_content',
      'field_accordion_body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['field_collection_item|field_accodrion|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|accordion_page|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'accordion_page';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_content',
        1 => 'body',
        2 => 'group_accordion_wrapper',
        3 => 'field_accodrion',
      ),
    ),
    'fields' => array(
      'group_content' => 'ds_content',
      'body' => 'ds_content',
      'group_accordion_wrapper' => 'ds_content',
      'field_accodrion' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|accordion_page|full'] = $ds_layout;

  return $export;
}

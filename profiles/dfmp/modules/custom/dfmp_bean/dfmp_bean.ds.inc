<?php
/**
 * @file
 * dfmp_bean.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function dfmp_bean_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|call_to_action_block|default';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'call_to_action_block';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'panels-one_mp';
  $ds_layout->settings = array(
    'regions' => array(
      'minipanel_one_main' => array(
        0 => 'title',
        1 => 'field_image',
        2 => 'field_link',
        3 => 'field_resource_id',
      ),
    ),
    'fields' => array(
      'title' => 'minipanel_one_main',
      'field_image' => 'minipanel_one_main',
      'field_link' => 'minipanel_one_main',
      'field_resource_id' => 'minipanel_one_main',
    ),
    'classes' => array(),
    'wrappers' => array(
      'minipanel_one_main' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['bean|call_to_action_block|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'bean|call_to_action_block|image_form_tips';
  $ds_layout->entity_type = 'bean';
  $ds_layout->bundle = 'call_to_action_block';
  $ds_layout->view_mode = 'image_form_tips';
  $ds_layout->layout = 'panels-two_50_mp';
  $ds_layout->settings = array(
    'regions' => array(
      'minipanel_two_50_top' => array(
        0 => 'field_image',
        1 => 'field_image_mobile',
      ),
      'minipanel_two_50_bottom' => array(
        2 => 'field_form_id',
      ),
    ),
    'fields' => array(
      'field_image' => 'minipanel_two_50_top',
      'field_image_mobile' => 'minipanel_two_50_top',
      'field_form_id' => 'minipanel_two_50_bottom',
    ),
    'classes' => array(),
    'wrappers' => array(
      'minipanel_two_50_top' => 'div',
      'minipanel_two_50_first' => 'div',
      'minipanel_two_50_second' => 'div',
      'minipanel_two_50_bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['bean|call_to_action_block|image_form_tips'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function dfmp_bean_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'image_and_link';
  $ds_view_mode->label = 'Image and Link';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
  );
  $export['image_and_link'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'image_form_tips';
  $ds_view_mode->label = 'Image Form Tips';
  $ds_view_mode->entities = array(
    'bean' => 'bean',
  );
  $export['image_form_tips'] = $ds_view_mode;

  return $export;
}

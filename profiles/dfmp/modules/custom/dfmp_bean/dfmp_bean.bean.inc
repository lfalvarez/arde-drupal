<?php
/**
 * @file
 * dfmp_bean.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function dfmp_bean_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'call_to_action_block';
  $bean_type->label = 'Call To Action Block';
  $bean_type->options = '';
  $bean_type->description = 'Call To Action Block';
  $export['call_to_action_block'] = $bean_type;

  return $export;
}

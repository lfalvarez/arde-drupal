<?php
/**
 * @file
 * dfmp_bean.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dfmp_bean_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_bean__call_to_action_block';
  $strongarm->value = array(
    'view_modes' => array(
      'image_and_link' => array(
        'custom_settings' => TRUE,
      ),
      'image_form_tips' => array(
        'custom_settings' => TRUE,
      ),
      'default' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'label' => array(
          'weight' => '-10',
        ),
        'title' => array(
          'weight' => '-9',
        ),
        'revision' => array(
          'weight' => '10',
        ),
        'view_mode' => array(
          'weight' => '10',
        ),
      ),
      'display' => array(
        'title' => array(
          'default' => array(
            'weight' => '-9',
            'visible' => TRUE,
          ),
          'image_and_link' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'image_form_tips' => array(
            'weight' => '-9',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_bean__call_to_action_block'] = $strongarm;

  return $export;
}

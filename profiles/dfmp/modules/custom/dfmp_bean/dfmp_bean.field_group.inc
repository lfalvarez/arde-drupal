<?php
/**
 * @file
 * dfmp_bean.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dfmp_bean_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tip|bean|call_to_action_block|form';
  $field_group->group_name = 'group_tip';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'call_to_action_block';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tip',
    'weight' => '5',
    'children' => array(
      0 => 'field_tip_link',
      1 => 'field_tip_text',
      2 => 'field_tip_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Tip',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-tip field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_tip|bean|call_to_action_block|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tip|bean|call_to_action_block|image_form_tips';
  $field_group->group_name = 'group_tip';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'call_to_action_block';
  $field_group->mode = 'image_form_tips';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '3',
    'children' => array(
      0 => 'field_tip_link',
      1 => 'field_tip_text',
      2 => 'field_tip_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-tip field-group-fieldset',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_tip|bean|call_to_action_block|image_form_tips'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Tip');

  return $field_groups;
}

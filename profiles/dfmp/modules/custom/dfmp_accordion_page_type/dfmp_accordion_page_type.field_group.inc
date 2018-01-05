<?php
/**
 * @file
 * dfmp_accordion_page_type.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function dfmp_accordion_page_type_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion_wrapper|node|accordion_page|full';
  $field_group->group_name = 'group_accordion_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'accordion_page';
  $field_group->mode = 'full';
  $field_group->parent_name = 'group_content';
  $field_group->data = array(
    'label' => 'Accordion wrapper',
    'weight' => '2',
    'children' => array(
      0 => 'field_accodrion',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Accordion wrapper',
      'instance_settings' => array(
        'id' => 'accordion',
        'classes' => 'group-accordion-wrapper field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_accordion_wrapper|node|accordion_page|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|node|accordion_page|full';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'accordion_page';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'group_accordion_wrapper',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'content group-content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_content|node|accordion_page|full'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Accordion wrapper');
  t('Content');

  return $field_groups;
}

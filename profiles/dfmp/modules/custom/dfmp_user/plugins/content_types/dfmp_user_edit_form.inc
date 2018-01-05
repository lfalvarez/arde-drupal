<?php
/**
 * @file
 * Promotion request content type
 */

$plugin = array(
  'category' => t('DFMP'),
  'title' => t('DFMP user edit form'),
  'description' => t('DFMP user edit form'),
  'render callback' => 'dfmp_user_edit_form_render',
);


/**
 * Outputs request promotion
 */
function dfmp_user_edit_form_render($subtype, $conf, $panel_args, $context) {
  global $user;
  $user = user_load($user->uid);
  module_load_include('inc', 'user', 'user.pages');
  $user_form = drupal_get_form('user_profile_form', $user);
  $form = drupal_render($user_form);
  $block = new stdClass();
  $block->content = $form;
  return $block;
}

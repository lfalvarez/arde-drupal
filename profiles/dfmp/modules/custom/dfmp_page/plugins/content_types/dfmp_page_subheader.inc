<?php
/**
 * @file
 * Subheader content type
 */

$plugin = array(
  'category' => t('DFMP'),
  'title' => t('DFMP homepage subheader'),
  'description' => t('DFMP homepage subheader'),
  'render callback' => 'dfmp_homepage_subheader_render',
);


/**
 * Outputs request promotion
 */
function dfmp_homepage_subheader_render($subtype, $conf, $panel_args, $context) {
  global $user;

  $block = new stdClass();
  $form = drupal_get_form('search_form');
  if ($user->uid) {
    $login_form = '';
  }
  else {
    $login_form = drupal_get_form('user_login');
    $login_form = drupal_render($login_form);
  }
  $block->content = theme('dfmp_homepage_subheader', array(
    'search_form' => $form,
    'login_form' => $login_form,
  ));
  return $block;
}
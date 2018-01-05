<?php
/**
 * @file
 * User resources content type
 */
$plugin = array(
  'category' => t('DFMP'),
  'title' => t('DFMP user resources'),
  'description' => t('DFMP user resources'),
  'render callback' => 'dfmp_dataset_viewer_dfmp_user_resources_render',
);


/**
 * Outputs request promotion
 */
function dfmp_dataset_viewer_dfmp_user_resources_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $block->content = dfmp_dataset_viewer_all_table();
  return $block;
}
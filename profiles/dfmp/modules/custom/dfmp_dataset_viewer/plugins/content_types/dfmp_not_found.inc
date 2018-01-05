<?php
/**
 * @file
 * Dataset not found content type
 */

$plugin = array(
  'category' => t('DFMP'),
  'title' => t('DFMP Not Found'),
  'description' => t('DFMP Not Found block'),
  'render callback' => 'dfmp_dataset_viewer_dfmp_not_found_render',
);


/**
 * Outputs request promotion
 */
function dfmp_dataset_viewer_dfmp_not_found_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();

  $block->content = dfmp_dataset_viewer_page_not_found();
  return $block;
}
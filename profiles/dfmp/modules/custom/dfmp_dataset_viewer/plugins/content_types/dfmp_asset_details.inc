<?php
/**
 * @file
 * Asset details content type
 */
$plugin = array(
  'category' => t('DFMP'),
  'title' => t('DFMP asset details'),
  'description' => t('DFMP asset details'),
  'render callback' => 'dfmp_dataset_viewer_dfmp_assset_details_render',
);


/**
 * Outputs request promotion
 */
function dfmp_dataset_viewer_dfmp_assset_details_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $id = arg(1);

  $block->content = dfmp_dataset_viewer_asset_details($id);
  return $block;
}
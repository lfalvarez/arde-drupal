<?php
/**
 * @file
 * Single asset content type
 */
$plugin = array(
  'category' => t('DFMP'),
  'title' => t('DFMP gallery single item'),
  'description' => t('DFMP gallery single item'),
  'render callback' => 'dfmp_dataset_viewer_dfmp_gallery_single_item_render',
);


/**
 * Outputs request promotion
 */
function dfmp_dataset_viewer_dfmp_gallery_single_item_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $gallery_id = arg(2);
  $asset_id = arg(3);
  $query = array(
    'limit' => 4,
  );

  $block->content = dfmp_dataset_viewer_gallery_single_asset($gallery_id, $asset_id, $query);
  return $block;
}
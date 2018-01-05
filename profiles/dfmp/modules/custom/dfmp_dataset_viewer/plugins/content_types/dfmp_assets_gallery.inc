<?php
/**
 * @file
 * Dallery assets content type
 */
const GALLERY_IMAGES_LIMIT = 4;

$plugin = array(
  'category' => t('DFMP'),
  'title' => t('DFMP assets gallery'),
  'description' => t('DFMP assets gallery'),
  'render callback' => 'dfmp_dataset_viewer_dfmp_asssets_gallery_render',
);


/**
 * Outputs request promotion
 */
function dfmp_dataset_viewer_dfmp_asssets_gallery_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $query = array(
    // 'limit' => GALLERY_IMAGES_LIMIT,
    'offset' => isset($_GET['page']) && is_numeric($_GET['page']) ? $_GET['page'] * GALLERY_IMAGES_LIMIT : 0,
  );

  $block->content = dfmp_dataset_viewer_assets_gallery($query);
  return $block; 
}

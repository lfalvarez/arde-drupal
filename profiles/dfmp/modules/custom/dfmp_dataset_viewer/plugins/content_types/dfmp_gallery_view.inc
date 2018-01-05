<?php
/**
 * @file
 * Gallery content type
 */
$plugin = array(
  'category' => t('DFMP'),
  'title' => t('DFMP gallery view'),
  'description' => t('DFMP gallery view'),
  'render callback' => 'dfmp_dataset_viewer_dfmp_gallery_view_render',
);


/**
 * Outputs request promotion
 */
function dfmp_dataset_viewer_dfmp_gallery_view_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();

  $gallery_id = arg(2);

  $query = array(
    'limit' => 4,
  );
  /*
  Disable infinity scroll for galleries
  */
//  if (isset($_GET['page']) && is_numeric($_GET['page'])) {
//    dfmp_dataset_viewer_gallery_view_scroll($gallery_id);
//  }
  $block->content = dfmp_dataset_viewer_gallery_view($gallery_id, $query);
  return $block;
}

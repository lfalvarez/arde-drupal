<?php

$plugin = array(
  'category' => t('DFMP'),
  'title' => t('DFMP search page'),
  'description' => t('DFMP search page'),
  'render callback' => 'dfmp_search_page_render',
);

/**
 * Outputs request promotion
 */
function dfmp_search_page_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = dfmp_dataset_viewer_gallery_search_view();
  return $block;
}


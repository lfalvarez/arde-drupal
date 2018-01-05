<?php
/**
 * @file
 * bottom Browse Collection Block
 */

$plugin = array(
  'category' => t('DFMP'),
  'title' => t('DFMP Browse Collection Block'),
  'description' => t('DFMP Browse Collection Block'),
  'render callback' => 'dfmp_page_browse_collection_render',
);


/**
 * Outputs request promotion
 */
function dfmp_page_browse_collection_render($subtype, $conf, $panel_args, $context) {
  $block = new stdClass();
  $block->content = dfmp_page_browse_collection_block();

  return $block;
}
<?php
/**
 * @file
 * bottom Browse Collection Block
 */

$plugin = array(
  'category' => t('DFMP'),
  'title' => t('DFMP Browse Group Block'),
  'description' => t('DFMP Browse Group Block'),
  'render callback' => 'dfmp_page_browse_group_render',
);


/**
 * Outputs request promotion
 */
function dfmp_page_browse_group_render($subtype, $conf, $panel_args, $context) {
  $id = reset($panel_args);
  $block = new stdClass();
  $block->content = dfmp_page_browse_group_block($id);

  return $block;
}
<?php
/**
 * @file
 * Header content type
 */

$plugin = array(
  'category' => t('DFMP'),
  'title' => t('DFMP page header'),
  'description' => t('DFMP page header'),
  'render callback' => 'dfmp_page_header_render',
);


/**
 * Outputs request promotion
 */
function dfmp_page_header_render($subtype, $conf, $panel_args, $context) {

  $block = new stdClass();
  $block->content = theme('dfmp_page_header');
  return $block;
}
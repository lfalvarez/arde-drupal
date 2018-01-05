<?php
/**
 * @file
 * dfmp_dataset_viewer.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function dfmp_dataset_viewer_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'mediaelement_sitewide';
  $strongarm->value = 1;
  $export['mediaelement_sitewide'] = $strongarm;

  return $export;
}

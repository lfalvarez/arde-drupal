<?php
/**
 * @file
 * dfmp_dataset_viewer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dfmp_dataset_viewer_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

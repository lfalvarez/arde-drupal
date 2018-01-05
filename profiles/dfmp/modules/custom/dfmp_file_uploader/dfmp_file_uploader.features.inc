<?php
/**
 * @file
 * dfmp_file_uploader.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function dfmp_file_uploader_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

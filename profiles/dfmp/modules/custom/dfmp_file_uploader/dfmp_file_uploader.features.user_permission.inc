<?php
/**
 * @file
 * dfmp_file_uploader.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dfmp_file_uploader_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access_file_uploading_page'.
  $permissions['access_file_uploading_page'] = array(
    'name' => 'access_file_uploading_page',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'dfmp_file_uploader',
  );

  return $permissions;
}

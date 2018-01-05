<?php
/**
 * @file
 * dfmp_user.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dfmp_user_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access dataset keywords'.
  $permissions['access dataset keywords'] = array(
    'name' => 'access dataset keywords',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'dfmp_user',
  );

  // Exported permission: 'create users'.
  $permissions['create users'] = array(
    'name' => 'create users',
    'roles' => array(
      'Data administrator' => 'Data administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  return $permissions;
}

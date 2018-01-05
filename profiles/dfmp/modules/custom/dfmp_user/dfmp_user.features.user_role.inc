<?php
/**
 * @file
 * dfmp_user.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function dfmp_user_user_default_roles() {
  $roles = array();

  // Exported role: Data administrator.
  $roles['Data administrator'] = array(
    'name' => 'Data administrator',
    'weight' => 11,
  );

  // Exported role: Territory Content manager.
  $roles['Territory Content manager'] = array(
    'name' => 'Territory Content manager',
    'weight' => 10,
  );

  return $roles;
}

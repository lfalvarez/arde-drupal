<?php
/**
 * @file
 * dfmp_bean.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function dfmp_bean_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view any call_to_action_block bean'.
  $permissions['view any call_to_action_block bean'] = array(
    'name' => 'view any call_to_action_block bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}

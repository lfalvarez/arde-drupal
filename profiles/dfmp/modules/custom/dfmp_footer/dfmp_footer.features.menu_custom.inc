<?php
/**
 * @file
 * dfmp_footer.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function dfmp_footer_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-explore-the-website.
  $menus['menu-explore-the-website'] = array(
    'menu_name' => 'menu-explore-the-website',
    'title' => 'Useful Links',
    'description' => '',
  );
  // Exported menu: menu-other-admin-links.
  $menus['menu-other-admin-links'] = array(
    'menu_name' => 'menu-other-admin-links',
    'title' => 'Other admin links',
    'description' => '',
  );
  // Exported menu: menu-popular-tags.
  $menus['menu-popular-tags'] = array(
    'menu_name' => 'menu-popular-tags',
    'title' => 'Popular tags',
    'description' => '',
  );
  // Exported menu: user-menu.
  $menus['user-menu'] = array(
    'menu_name' => 'user-menu',
    'title' => 'User menu',
    'description' => 'The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Other admin links');
  t('Popular tags');
  t('The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.');
  t('Useful Links');
  t('User menu');

  return $menus;
}

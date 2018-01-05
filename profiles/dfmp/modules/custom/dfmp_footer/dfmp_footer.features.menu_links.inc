<?php
/**
 * @file
 * dfmp_footer.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function dfmp_footer_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-explore-the-website_browse:browse/images.
  $menu_links['menu-explore-the-website_browse:browse/images'] = array(
    'menu_name' => 'menu-explore-the-website',
    'link_path' => 'browse/images',
    'router_path' => 'browse/images',
    'link_title' => 'Browse',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-explore-the-website_browse:browse/images',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-explore-the-website_visit-data-first-media-platform:data.
  $menu_links['menu-explore-the-website_visit-data-first-media-platform:data'] = array(
    'menu_name' => 'menu-explore-the-website',
    'link_path' => 'data',
    'router_path' => 'data',
    'link_title' => 'Visit data first media platform',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-explore-the-website_visit-data-first-media-platform:data',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-other-admin-links_copyright-2015:node.
  $menu_links['menu-other-admin-links_copyright-2015:node'] = array(
    'menu_name' => 'menu-other-admin-links',
    'link_path' => 'node',
    'router_path' => 'node',
    'link_title' => 'Copyright 2015',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-other-admin-links_copyright-2015:node',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-other-admin-links_creative-common-licenses:node/1.
  $menu_links['menu-other-admin-links_creative-common-licenses:node/1'] = array(
    'menu_name' => 'menu-other-admin-links',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Creative common licenses',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-other-admin-links_creative-common-licenses:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-other-admin-links_privacy-policy:node/1.
  $menu_links['menu-other-admin-links_privacy-policy:node/1'] = array(
    'menu_name' => 'menu-other-admin-links',
    'link_path' => 'node/1',
    'router_path' => 'node/%',
    'link_title' => 'Privacy policy',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-other-admin-links_privacy-policy:node/1',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-popular-tags_cbr:gallery/view/8a222719-ba9e-47f9-9af0-2e4356df2afb.
  $menu_links['menu-popular-tags_cbr:gallery/view/8a222719-ba9e-47f9-9af0-2e4356df2afb'] = array(
    'menu_name' => 'menu-popular-tags',
    'link_path' => 'gallery/view/8a222719-ba9e-47f9-9af0-2e4356df2afb',
    'router_path' => 'gallery/view/%',
    'link_title' => 'CBR',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-popular-tags_cbr:gallery/view/8a222719-ba9e-47f9-9af0-2e4356df2afb',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-popular-tags_weareckan:gallery/view/7d4a235b-4cf1-498b-925b-48373ed4b12a.
  $menu_links['menu-popular-tags_weareckan:gallery/view/7d4a235b-4cf1-498b-925b-48373ed4b12a'] = array(
    'menu_name' => 'menu-popular-tags',
    'link_path' => 'gallery/view/7d4a235b-4cf1-498b-925b-48373ed4b12a',
    'router_path' => 'gallery/view/%',
    'link_title' => 'WeAreCKAN',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'menu-popular-tags_weareckan:gallery/view/7d4a235b-4cf1-498b-925b-48373ed4b12a',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: user-menu_file-uploader:dfmp/file_uploader.
  $menu_links['user-menu_file-uploader:dfmp/file_uploader'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'dfmp/file_uploader',
    'router_path' => 'dfmp/file_uploader',
    'link_title' => 'File uploader',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'user-menu_file-uploader:dfmp/file_uploader',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: user-menu_log-out:user/logout.
  $menu_links['user-menu_log-out:user/logout'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user/logout',
    'router_path' => 'user/logout',
    'link_title' => 'Log out',
    'options' => array(
      'identifier' => 'user-menu_log-out:user/logout',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: user-menu_user-account:user.
  $menu_links['user-menu_user-account:user'] = array(
    'menu_name' => 'user-menu',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'User account',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'user-menu_user-account:user',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Browse');
  t('CBR');
  t('Copyright 2015');
  t('Creative common licenses');
  t('File uploader');
  t('Log out');
  t('Privacy policy');
  t('User account');
  t('Visit data first media platform');
  t('WeAreCKAN');

  return $menu_links;
}

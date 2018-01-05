<?php
/**
 * @file
 * dfmp_page.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function dfmp_page_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_browse:browse/images.
  $menu_links['main-menu_browse:browse/images'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'browse/images',
    'router_path' => 'browse/images',
    'link_title' => 'BROWSE',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_browse:browse/images',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: main-menu_cbr:gallery/view/8a222719-ba9e-47f9-9af0-2e4356df2afb.
  $menu_links['main-menu_cbr:gallery/view/8a222719-ba9e-47f9-9af0-2e4356df2afb'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'gallery/view/8a222719-ba9e-47f9-9af0-2e4356df2afb',
    'router_path' => 'gallery/view/%',
    'link_title' => '#CBR',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_cbr:gallery/view/8a222719-ba9e-47f9-9af0-2e4356df2afb',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: main-menu_visit-dfmp:data.
  $menu_links['main-menu_visit-dfmp:data'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'data',
    'router_path' => 'data',
    'link_title' => 'VISIT DFMP',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_visit-dfmp:data',
    ),
    'module' => 'menu',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('#CBR');
  t('BROWSE');
  t('VISIT DFMP');

  return $menu_links;
}

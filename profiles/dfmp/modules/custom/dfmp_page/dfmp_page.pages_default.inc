<?php
/**
 * @file
 * dfmp_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function dfmp_page_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'site_template_panel_context';
  $handler->task = 'site_template';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -29;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'two_66_33';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'four_25_top' => NULL,
      'four_25_first' => NULL,
      'four_25_second' => NULL,
      'four_25_third' => NULL,
      'four_25_fourth' => NULL,
      'four_25_bottom' => NULL,
      'three_25_50_25_top' => NULL,
      'three_25_50_25_first' => NULL,
      'three_25_50_25_second' => NULL,
      'three_25_50_25_third' => NULL,
      'three_25_50_25_bottom' => NULL,
      'two_33_66_top' => NULL,
      'two_33_66_first' => NULL,
      'two_33_66_second' => NULL,
      'two_33_66_bottom' => NULL,
      'two_66_33_top' => NULL,
      'two_66_33_first' => NULL,
      'two_66_33_second' => NULL,
      'two_66_33_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'bd189bb2-8755-447e-b3a6-f8c252af988f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f023446f-bd8f-4a46-a94b-e08184d08bc5';
    $pane->panel = 'two_66_33_bottom';
    $pane->type = 'panels_mini';
    $pane->subtype = 'dfmp_footer';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f023446f-bd8f-4a46-a94b-e08184d08bc5';
    $display->content['new-f023446f-bd8f-4a46-a94b-e08184d08bc5'] = $pane;
    $display->panels['two_66_33_bottom'][0] = 'new-f023446f-bd8f-4a46-a94b-e08184d08bc5';
    $pane = new stdClass();
    $pane->pid = 'new-12903ae1-0a61-478e-94cc-fab41be68633';
    $pane->panel = 'two_66_33_first';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '12903ae1-0a61-478e-94cc-fab41be68633';
    $display->content['new-12903ae1-0a61-478e-94cc-fab41be68633'] = $pane;
    $display->panels['two_66_33_first'][0] = 'new-12903ae1-0a61-478e-94cc-fab41be68633';
    $pane = new stdClass();
    $pane->pid = 'new-c81dd3fd-1256-46cf-88d8-e83b9ca46a0b';
    $pane->panel = 'two_66_33_first';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c81dd3fd-1256-46cf-88d8-e83b9ca46a0b';
    $display->content['new-c81dd3fd-1256-46cf-88d8-e83b9ca46a0b'] = $pane;
    $display->panels['two_66_33_first'][1] = 'new-c81dd3fd-1256-46cf-88d8-e83b9ca46a0b';
    $pane = new stdClass();
    $pane->pid = 'new-692a88e0-0a9f-4428-9064-668c571ea651';
    $pane->panel = 'two_66_33_first';
    $pane->type = 'page_tabs';
    $pane->subtype = 'page_tabs';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'type' => 'both',
      'id' => 'tabs',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '692a88e0-0a9f-4428-9064-668c571ea651';
    $display->content['new-692a88e0-0a9f-4428-9064-668c571ea651'] = $pane;
    $display->panels['two_66_33_first'][2] = 'new-692a88e0-0a9f-4428-9064-668c571ea651';
    $pane = new stdClass();
    $pane->pid = 'new-8010f02e-d8dc-43c8-9f43-03d25a500059';
    $pane->panel = 'two_66_33_first';
    $pane->type = 'page_content';
    $pane->subtype = 'page_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_page_content_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '8010f02e-d8dc-43c8-9f43-03d25a500059';
    $display->content['new-8010f02e-d8dc-43c8-9f43-03d25a500059'] = $pane;
    $display->panels['two_66_33_first'][3] = 'new-8010f02e-d8dc-43c8-9f43-03d25a500059';
    $pane = new stdClass();
    $pane->pid = 'new-8c185add-b8c9-4ec8-bd43-f281dceabb3e';
    $pane->panel = 'two_66_33_top';
    $pane->type = 'panels_mini';
    $pane->subtype = 'dfmp_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8c185add-b8c9-4ec8-bd43-f281dceabb3e';
    $display->content['new-8c185add-b8c9-4ec8-bd43-f281dceabb3e'] = $pane;
    $display->panels['two_66_33_top'][0] = 'new-8c185add-b8c9-4ec8-bd43-f281dceabb3e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['site_template_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'user_view_panel_context';
  $handler->task = 'user_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'mothership-html5page-page';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'top_mobile' => NULL,
      'middle' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ea01e417-6868-4e57-92e6-337609b9f420';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-0b8d7792-da1b-4983-bb62-69fde3586f8e';
    $pane->panel = 'middle';
    $pane->type = 'dfmp_user_edit_form';
    $pane->subtype = 'dfmp_user_edit_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0b8d7792-da1b-4983-bb62-69fde3586f8e';
    $display->content['new-0b8d7792-da1b-4983-bb62-69fde3586f8e'] = $pane;
    $display->panels['middle'][0] = 'new-0b8d7792-da1b-4983-bb62-69fde3586f8e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['user_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function dfmp_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'asset_details';
  $page->task = 'page';
  $page->admin_title = 'Asset Details';
  $page->admin_description = '';
  $page->path = 'asset/%id';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'id' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_asset_details_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'asset_details';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5f3e72fe-7598-48f8-a4d4-12f41d3f6ad2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c5d300eb-02e1-4429-9692-ef05fd13a998';
    $pane->panel = 'middle';
    $pane->type = 'dfmp_asset_details';
    $pane->subtype = 'dfmp_asset_details';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c5d300eb-02e1-4429-9692-ef05fd13a998';
    $display->content['new-c5d300eb-02e1-4429-9692-ef05fd13a998'] = $pane;
    $display->panels['middle'][0] = 'new-c5d300eb-02e1-4429-9692-ef05fd13a998';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['asset_details'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'assets_view';
  $page->task = 'page';
  $page->admin_title = 'Assets view';
  $page->admin_description = '';
  $page->path = 'assets/view';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_assets_view_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'assets_view';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'dfbaa6f7-5f4a-497d-b2d0-354ab6f976e9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d09f1bd0-7ff6-44a5-acf1-06743c274287';
    $pane->panel = 'middle';
    $pane->type = 'dfmp_user_resources';
    $pane->subtype = 'dfmp_user_resources';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd09f1bd0-7ff6-44a5-acf1-06743c274287';
    $display->content['new-d09f1bd0-7ff6-44a5-acf1-06743c274287'] = $pane;
    $display->panels['middle'][0] = 'new-d09f1bd0-7ff6-44a5-acf1-06743c274287';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['assets_view'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'browse_group';
  $page->task = 'page';
  $page->admin_title = 'Browse Group';
  $page->admin_description = '';
  $page->path = 'browse/group/%id';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'id' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_browse_group__panel_context_787e943a-c131-44b6-ac33-047cbf5a164c';
  $handler->task = 'page';
  $handler->subtask = 'browse_group';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Browse Gallery';
  $display->uuid = '033a2175-5b3c-4452-9bd9-41b41adb6e31';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-59cdd348-c8cb-497a-85f3-c42829f859db';
    $pane->panel = 'middle';
    $pane->type = 'dfmp_page_group';
    $pane->subtype = 'dfmp_page_group';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '59cdd348-c8cb-497a-85f3-c42829f859db';
    $display->content['new-59cdd348-c8cb-497a-85f3-c42829f859db'] = $pane;
    $display->panels['middle'][0] = 'new-59cdd348-c8cb-497a-85f3-c42829f859db';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['browse_group'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'browse_images';
  $page->task = 'page';
  $page->admin_title = 'Browse Images';
  $page->admin_description = '';
  $page->path = 'browse/images';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_browse_images_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'browse_images';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'one_fw';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'minipanel_one_main_fw' => NULL,
      'one_fw_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'cb3930d7-1023-4694-802b-3392f7b34580';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8ba446db-8f92-47ec-b3fb-322041d68e50';
    $pane->panel = 'one_fw_main';
    $pane->type = 'dfmp_assets_gallery';
    $pane->subtype = 'dfmp_assets_gallery';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8ba446db-8f92-47ec-b3fb-322041d68e50';
    $display->content['new-8ba446db-8f92-47ec-b3fb-322041d68e50'] = $pane;
    $display->panels['one_fw_main'][0] = 'new-8ba446db-8f92-47ec-b3fb-322041d68e50';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['browse_images'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'ckan_part';
  $page->task = 'page';
  $page->admin_title = 'Ckan part';
  $page->admin_description = '';
  $page->path = 'data';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_ckan_part__panel_context_6aeaa721-2abd-4e4b-9f60-e1751243d6f2';
  $handler->task = 'page';
  $handler->subtask = 'ckan_part';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '95287888-9662-4bf6-a7cf-8bb46b801a96';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['ckan_part'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'gallery_view';
  $page->task = 'page';
  $page->admin_title = 'Gallery view';
  $page->admin_description = '';
  $page->path = 'gallery/view/%id';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'id' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
      'keyword' => 'id',
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_gallery_view_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'gallery_view';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'one_fw';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_fw_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'affc3f35-2dbe-4ea1-a637-bf10e2f23a27';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b0c64125-f4d0-4297-ba2e-fe0233534d78';
    $pane->panel = 'one_fw_main';
    $pane->type = 'dfmp_gallery_view';
    $pane->subtype = 'dfmp_gallery_view';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b0c64125-f4d0-4297-ba2e-fe0233534d78';
    $display->content['new-b0c64125-f4d0-4297-ba2e-fe0233534d78'] = $pane;
    $display->panels['one_fw_main'][0] = 'new-b0c64125-f4d0-4297-ba2e-fe0233534d78';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['gallery_view'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home';
  $page->task = 'page';
  $page->admin_title = 'Home';
  $page->admin_description = '';
  $page->path = 'home';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'four_25';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_fw_main' => NULL,
      'four_25_top' => NULL,
      'four_25_first' => NULL,
      'four_25_second' => NULL,
      'four_25_third' => NULL,
      'four_25_fourth' => NULL,
      'four_25_bottom' => NULL,
    ),
    'four_25_top' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'fdb7710f-4c63-44c2-9c69-0dc4c43a6ec6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b2fbc53c-5fc2-42e7-9e83-322dece3b39a';
    $pane->panel = 'four_25_first';
    $pane->type = 'block';
    $pane->subtype = 'bean-cbr';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b2fbc53c-5fc2-42e7-9e83-322dece3b39a';
    $display->content['new-b2fbc53c-5fc2-42e7-9e83-322dece3b39a'] = $pane;
    $display->panels['four_25_first'][0] = 'new-b2fbc53c-5fc2-42e7-9e83-322dece3b39a';
    $pane = new stdClass();
    $pane->pid = 'new-73a60d5b-61fe-472d-ace0-830e052fe7e4';
    $pane->panel = 'four_25_fourth';
    $pane->type = 'block';
    $pane->subtype = 'bean-sports';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '73a60d5b-61fe-472d-ace0-830e052fe7e4';
    $display->content['new-73a60d5b-61fe-472d-ace0-830e052fe7e4'] = $pane;
    $display->panels['four_25_fourth'][0] = 'new-73a60d5b-61fe-472d-ace0-830e052fe7e4';
    $pane = new stdClass();
    $pane->pid = 'new-f1f4da0c-95e5-4820-882b-099938f11edc';
    $pane->panel = 'four_25_second';
    $pane->type = 'block';
    $pane->subtype = 'bean-events';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f1f4da0c-95e5-4820-882b-099938f11edc';
    $display->content['new-f1f4da0c-95e5-4820-882b-099938f11edc'] = $pane;
    $display->panels['four_25_second'][0] = 'new-f1f4da0c-95e5-4820-882b-099938f11edc';
    $pane = new stdClass();
    $pane->pid = 'new-867a75e2-d4ed-436d-b5dd-a88bce09d28d';
    $pane->panel = 'four_25_third';
    $pane->type = 'block';
    $pane->subtype = 'bean-flora';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '867a75e2-d4ed-436d-b5dd-a88bce09d28d';
    $display->content['new-867a75e2-d4ed-436d-b5dd-a88bce09d28d'] = $pane;
    $display->panels['four_25_third'][0] = 'new-867a75e2-d4ed-436d-b5dd-a88bce09d28d';
    $pane = new stdClass();
    $pane->pid = 'new-9047d611-ffe6-4e09-b06a-7e22d955e469';
    $pane->panel = 'four_25_top';
    $pane->type = 'block';
    $pane->subtype = 'bean-promo-banner';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9047d611-ffe6-4e09-b06a-7e22d955e469';
    $display->content['new-9047d611-ffe6-4e09-b06a-7e22d955e469'] = $pane;
    $display->panels['four_25_top'][0] = 'new-9047d611-ffe6-4e09-b06a-7e22d955e469';
    $pane = new stdClass();
    $pane->pid = 'new-90a4cdbc-3eba-4024-a8aa-5f609e97a8f8';
    $pane->panel = 'four_25_top';
    $pane->type = 'block';
    $pane->subtype = 'user-login';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'grid_width' => 'width-100',
        'left_margin' => '',
        'right_margin' => '',
        'float' => 'float-left',
        'custom_classes' => 'login-form',
        'custom_attrib' => '',
      ),
      'style' => 'parrot_styles',
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '90a4cdbc-3eba-4024-a8aa-5f609e97a8f8';
    $display->content['new-90a4cdbc-3eba-4024-a8aa-5f609e97a8f8'] = $pane;
    $display->panels['four_25_top'][1] = 'new-90a4cdbc-3eba-4024-a8aa-5f609e97a8f8';
    $pane = new stdClass();
    $pane->pid = 'new-d0aec801-b552-49a0-921e-59206260470e';
    $pane->panel = 'four_25_top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<div class="home-25-title"><span class="os-semibold">Browse</span> <span class="os-light">the collection</span></div>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd0aec801-b552-49a0-921e-59206260470e';
    $display->content['new-d0aec801-b552-49a0-921e-59206260470e'] = $pane;
    $display->panels['four_25_top'][2] = 'new-d0aec801-b552-49a0-921e-59206260470e';
    $pane = new stdClass();
    $pane->pid = 'new-30dcfe77-5da2-47f4-ba44-32b41b32d044';
    $pane->panel = 'four_25_top';
    $pane->type = 'dfmp_page_browse_collection';
    $pane->subtype = 'dfmp_page_browse_collection';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '30dcfe77-5da2-47f4-ba44-32b41b32d044';
    $display->content['new-30dcfe77-5da2-47f4-ba44-32b41b32d044'] = $pane;
    $display->panels['four_25_top'][3] = 'new-30dcfe77-5da2-47f4-ba44-32b41b32d044';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'not_found';
  $page->task = 'page';
  $page->admin_title = 'Not Found';
  $page->admin_description = '';
  $page->path = 'not-found';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_not_found_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'not_found';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'one_fw';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_fw_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'd47cd3ab-a3aa-4bac-b60b-6276eb85f05f';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-15009c9e-572c-4fb0-9a99-8927d72a0085';
    $pane->panel = 'one_fw_main';
    $pane->type = 'dfmp_not_found';
    $pane->subtype = 'dfmp_not_found';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '15009c9e-572c-4fb0-9a99-8927d72a0085';
    $display->content['new-15009c9e-572c-4fb0-9a99-8927d72a0085'] = $pane;
    $display->panels['one_fw_main'][0] = 'new-15009c9e-572c-4fb0-9a99-8927d72a0085';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['not_found'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'single_asset';
  $page->task = 'page';
  $page->admin_title = 'Single Asset';
  $page->admin_description = '';
  $page->path = 'gallery/item/%dataset/%id';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array(
    'dataset' => array(
      'id' => 2,
      'identifier' => 'String 2',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'id' => array(
      'id' => 1,
      'identifier' => 'String',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_single_asset_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'single_asset';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 1,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'one_fw';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'one_fw_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '53bbe0c4-0026-4e75-8261-1c63957ad838';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fa5ec883-4e42-4bcf-ada0-23e54ee32af3';
    $pane->panel = 'one_fw_main';
    $pane->type = 'dfmp_gallery_single';
    $pane->subtype = 'dfmp_gallery_single';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fa5ec883-4e42-4bcf-ada0-23e54ee32af3';
    $display->content['new-fa5ec883-4e42-4bcf-ada0-23e54ee32af3'] = $pane;
    $display->panels['one_fw_main'][0] = 'new-fa5ec883-4e42-4bcf-ada0-23e54ee32af3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['single_asset'] = $page;

  return $pages;

}

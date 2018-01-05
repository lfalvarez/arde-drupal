<?php
/**
 * @file
 * dfmp_header.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function dfmp_header_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'dfmp_header';
  $mini->category = '';
  $mini->admin_title = 'DFMP Header';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'three_33_mp_fw';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'minipanel_three_33_top_fw' => NULL,
      'minipanel_three_33_first_fw' => NULL,
      'minipanel_three_33_second_fw' => NULL,
      'minipanel_three_33_third_fw' => NULL,
      'minipanel_three_33_bottom_fw' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7e18d91c-dc31-472a-b206-22fd2f87f6cc';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-dd5d8df0-546b-4f0f-8f75-f0705443bf00';
    $pane->panel = 'minipanel_three_33_first_fw';
    $pane->type = 'page_logo';
    $pane->subtype = 'page_logo';
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
    $pane->uuid = 'dd5d8df0-546b-4f0f-8f75-f0705443bf00';
    $display->content['new-dd5d8df0-546b-4f0f-8f75-f0705443bf00'] = $pane;
    $display->panels['minipanel_three_33_first_fw'][0] = 'new-dd5d8df0-546b-4f0f-8f75-f0705443bf00';
    $pane = new stdClass();
    $pane->pid = 'new-3e66b40e-61c7-45ff-b042-41714e9de113';
    $pane->panel = 'minipanel_three_33_first_fw';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Text',
      'title' => '',
      'body' => '<div class="logo-title"><span class="os-semibold">ONLINE</span> <span class="os-light">PRECINCT</span></div>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3e66b40e-61c7-45ff-b042-41714e9de113';
    $display->content['new-3e66b40e-61c7-45ff-b042-41714e9de113'] = $pane;
    $display->panels['minipanel_three_33_first_fw'][1] = 'new-3e66b40e-61c7-45ff-b042-41714e9de113';
    $pane = new stdClass();
    $pane->pid = 'new-d870c6d7-1e38-4620-8ccf-a022baed2650';
    $pane->panel = 'minipanel_three_33_first_fw';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'Mobile menu toggler',
      'title' => '',
      'body' => '<p><a href="" id="navigation-toggle">toggle</a></p>
',
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
    $pane->uuid = 'd870c6d7-1e38-4620-8ccf-a022baed2650';
    $display->content['new-d870c6d7-1e38-4620-8ccf-a022baed2650'] = $pane;
    $display->panels['minipanel_three_33_first_fw'][2] = 'new-d870c6d7-1e38-4620-8ccf-a022baed2650';
    $pane = new stdClass();
    $pane->pid = 'new-eed462d3-3d0c-4a33-8200-931ba90121d8';
    $pane->panel = 'minipanel_three_33_second_fw';
    $pane->type = 'block';
    $pane->subtype = 'system-main-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'eed462d3-3d0c-4a33-8200-931ba90121d8';
    $display->content['new-eed462d3-3d0c-4a33-8200-931ba90121d8'] = $pane;
    $display->panels['minipanel_three_33_second_fw'][0] = 'new-eed462d3-3d0c-4a33-8200-931ba90121d8';
    $pane = new stdClass();
    $pane->pid = 'new-09f8622a-7b6f-4749-a2d0-d00bc0ac07ca';
    $pane->panel = 'minipanel_three_33_third_fw';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = FALSE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 1,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<a href="/user" class="header-login-btn">Login</a>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'grid_width' => 'width-100',
        'left_margin' => '',
        'right_margin' => '',
        'float' => 'float-right',
        'custom_classes' => '',
        'custom_attrib' => '',
      ),
      'style' => 'parrot_styles',
    );
    $pane->css = array(
      'css_id' => 'header-login-btn',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '09f8622a-7b6f-4749-a2d0-d00bc0ac07ca';
    $display->content['new-09f8622a-7b6f-4749-a2d0-d00bc0ac07ca'] = $pane;
    $display->panels['minipanel_three_33_third_fw'][0] = 'new-09f8622a-7b6f-4749-a2d0-d00bc0ac07ca';
    $pane = new stdClass();
    $pane->pid = 'new-b25e44de-c101-4064-87a3-6803be3b63af';
    $pane->panel = 'minipanel_three_33_third_fw';
    $pane->type = 'block';
    $pane->subtype = 'system-user-menu';
    $pane->shown = TRUE;
    $pane->access = array(
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
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'style' => 'parrot_styles',
      'settings' => array(
        'grid_width' => 'width-100',
        'left_margin' => '',
        'right_margin' => '',
        'float' => 'float-right',
        'custom_classes' => 'custom-css',
        'custom_attrib' => '',
      ),
    );
    $pane->css = array(
      'css_id' => 'header-user-menu',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b25e44de-c101-4064-87a3-6803be3b63af';
    $display->content['new-b25e44de-c101-4064-87a3-6803be3b63af'] = $pane;
    $display->panels['minipanel_three_33_third_fw'][1] = 'new-b25e44de-c101-4064-87a3-6803be3b63af';
    $pane = new stdClass();
    $pane->pid = 'new-57bf81ce-52c6-48fa-8c33-2b84f720f38c';
    $pane->panel = 'minipanel_three_33_third_fw';
    $pane->type = 'block';
    $pane->subtype = 'system-main-menu';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => array(
        'grid_width' => 'width-100',
        'left_margin' => '',
        'right_margin' => '',
        'float' => 'float-right',
        'custom_classes' => '',
        'custom_attrib' => '',
      ),
      'style' => 'parrot_styles',
    );
    $pane->css = array(
      'css_id' => 'header-main-menu',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '57bf81ce-52c6-48fa-8c33-2b84f720f38c';
    $display->content['new-57bf81ce-52c6-48fa-8c33-2b84f720f38c'] = $pane;
    $display->panels['minipanel_three_33_third_fw'][2] = 'new-57bf81ce-52c6-48fa-8c33-2b84f720f38c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-dd5d8df0-546b-4f0f-8f75-f0705443bf00';
  $mini->display = $display;
  $export['dfmp_header'] = $mini;

  return $export;
}

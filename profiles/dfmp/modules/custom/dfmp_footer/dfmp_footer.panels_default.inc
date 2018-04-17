<?php
/**
 * @file
 * dfmp_footer.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function dfmp_footer_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'dfmp_footer';
  $mini->category = '';
  $mini->admin_title = 'DFMP Footer';
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
  $display->uuid = '522411fa-d5a6-47e7-ae24-c4e74b3f0eba';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-405343e4-8c33-4a5f-adb9-28f800dd50e7';
    $pane->panel = 'minipanel_three_33_bottom_fw';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-other-admin-links';
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
    $pane->uuid = '405343e4-8c33-4a5f-adb9-28f800dd50e7';
    $display->content['new-405343e4-8c33-4a5f-adb9-28f800dd50e7'] = $pane;
    $display->panels['minipanel_three_33_bottom_fw'][0] = 'new-405343e4-8c33-4a5f-adb9-28f800dd50e7';
    $pane = new stdClass();
    $pane->pid = 'new-f74b5087-02a8-4979-8f82-457e1cebc1db';
    $pane->panel = 'minipanel_three_33_first_fw';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-explore-the-website';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
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
    $pane->uuid = 'f74b5087-02a8-4979-8f82-457e1cebc1db';
    $display->content['new-f74b5087-02a8-4979-8f82-457e1cebc1db'] = $pane;
    $display->panels['minipanel_three_33_first_fw'][0] = 'new-f74b5087-02a8-4979-8f82-457e1cebc1db';
    $pane = new stdClass();
    $pane->pid = 'new-5a80e845-5358-4dbc-b587-010ce1bcb241';
    $pane->panel = 'minipanel_three_33_second_fw';
    $pane->type = 'block';
    $pane->subtype = 'menu-menu-popular-tags';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
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
    $pane->uuid = '5a80e845-5358-4dbc-b587-010ce1bcb241';
    $display->content['new-5a80e845-5358-4dbc-b587-010ce1bcb241'] = $pane;
    $display->panels['minipanel_three_33_second_fw'][0] = 'new-5a80e845-5358-4dbc-b587-010ce1bcb241';
    $pane = new stdClass();
    $pane->pid = 'new-0865969f-3999-46e6-aa96-2171b6c25de7';
    $pane->panel = 'minipanel_three_33_third_fw';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Colectivo Arde',
      'body' => '<p>Arde está apoyado por el Fondart</p>',
      'format' => 'full_html',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0865969f-3999-46e6-aa96-2171b6c25de7';
    $display->content['new-0865969f-3999-46e6-aa96-2171b6c25de7'] = $pane;
    $display->panels['minipanel_three_33_third_fw'][0] = 'new-0865969f-3999-46e6-aa96-2171b6c25de7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['dfmp_footer'] = $mini;

  return $export;
}

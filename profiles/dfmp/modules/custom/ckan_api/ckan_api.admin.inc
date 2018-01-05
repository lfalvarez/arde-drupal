<?php
/**
 * @file
 * ckan_api.admin.inc
 */

/**
 * Page callback: CKAN config form
 */
function ckan_conf_form($form, &$form_state)
{
  global $base_url;

  $form['ckan_admin_key'] = array(
    '#type' => 'textfield',
    '#title' => t('CKAN admin\'s API-Key'),
    '#default_value' => variable_get('ckan_admin_key', ''),
    '#size' => 40,
    '#description' => t('The key which used in requests to CKAN API.'),
    '#required' => TRUE,
  );
  $form['ckan_url'] = array(
    '#type' => 'textfield',
    '#title' => t('CKAN URL'),
    '#default_value' => variable_get('ckan_url', $base_url.'/data'),
    '#size' => 40,
    '#description' => t('URL of CKAN instance.'),
    '#required' => TRUE,
  );
  $form['ckan_api_version'] = array(
    '#type' => 'textfield',
    '#title' => t('CKAN API version'),
    '#default_value' => variable_get('ckan_api_version', 3),
    '#size' => 40,
    '#description' => t('API\'s version for using in requests.'),
    '#required' => TRUE,
  );

  $form['ckan_act_organisation'] = array(
    '#type' => 'textfield',
    '#title' => t('CKAN ACT organisation'),
    '#default_value' => variable_get('ckan_act_organisation', 'act'),
    '#size' => 40,
    '#description' => t('Name of the CKAN government ACT organisation.'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}


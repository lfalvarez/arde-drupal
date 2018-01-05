<?php
/**
 * @file
 * Promotional requiest list content type
 */

$plugin = array(
  'category' => t('DFMP'),
  'title' => t('DFMP user request promotion list'),
  'description' => t('DFMP user request promotion list'),
  'render callback' => 'dfmp_user_request_promotion_list_render',
);


/**
 * Outputs request promotion list
 */
function dfmp_user_request_promotion_list_render($subtype, $conf, $panel_args, $context) {
  global $user;

  $current = dfmp_user_get_promotion($user->uid);

  $accepted_territories = array();
  foreach ($current as $user_record) {
    $accepted_territories[] = $user_record->territory;
  }

  $list = dfmp_user_get_promotion();
  $header = array('User', /*'Territory',*/ 'Action');
  $data = array();
  foreach ($list as $row) {
    if (!in_array($row->territory, $accepted_territories)) {
      continue;
    }
    $account = user_load($row->uid);
    try{
      $user_info = CkanApi::getInstance()->action('dfmp_user_info', array('data' => array('name' => $account->name)));

      $name = $account->name;
      $mail = $user_info->$name->email;
      $list_group = '';
      foreach ($user_info->$name->groups as $group) {
        $list_group .= ($group === end($user_info->$name->groups)) ? $group->title : $group->title . ', ';
      }
    } catch (Exception $e) {
      $mail = '';
      $list_group = '';
    }

    $actions = in_array('Data administrator', $account->roles) ? l(t('Accept'), 'promotion', array('query' => array('action' => 1, 'uid' => $row->uid, 'territory' => $row->territory))) . '</br>' . l(t('Cancel'), 'promotion', array('query' => array('action' => 0, 'uid' => $row->uid, 'territory' => $row->territory))) : t('You cannot perform any actions');
    $data[] = array(
      (isset($account->name)) ? $account->name .
          '</br>' .
          $mail .
          '</br>' .
          $list_group : '',
//      $row->territory,
      $actions,
    );
  }

  $output = theme('table',
    array('header' => $header,
      'rows' => $data ));

  $block = new stdClass();
  $block->content = $output;
  return $block;
}

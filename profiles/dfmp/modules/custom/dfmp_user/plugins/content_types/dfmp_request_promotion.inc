<?php
/**
 * @file
 * Promotion request content type
 */

$plugin = array(
  'category' => t('DFMP'),
  'title' => t('DFMP user request promotion'),
  'description' => t('DFMP user request promotion'),
  'render callback' => 'dfmp_user_request_promotion_render',
);


/**
 * Outputs request promotion
 */
function dfmp_user_request_promotion_render($subtype, $conf, $panel_args, $context) {
  $vid = taxonomy_vocabulary_machine_name_load('territory');
  $territory = taxonomy_get_tree($vid->vid, 0, NULL, TRUE);

  global $user;
  foreach ($territory as $key => $row) {
    // Should be ACT specific temporary.
    if ($row->name != 'ACT') {
      continue;
    }
    $t_name = drupal_strtolower($row->name);
    //Check Request
    $query = db_select('dfmp_user_request_promotion', 'durp')
        ->fields('durp', array('uid'))
        ->condition('durp.territory', $t_name, '=')
        ->condition('durp.uid', $user->uid);
    $result = $query->execute()->fetchObject();

    if ($result) {
      $territory[$key]->link = t('Request sent !name', array('!name' => $row->name));
    }
    else {
      $territory[$key]->link = l(t('Get promotion !name', array('!name' => $row->name)), 'promotion/' . drupal_strtolower($row->name));
    }
  }
  $block = new stdClass();
  $block->content = theme('dfmp_user_request_promotion', array('territory' => $territory));
  return $block;
}
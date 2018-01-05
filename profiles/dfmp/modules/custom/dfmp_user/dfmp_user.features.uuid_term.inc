<?php
/**
 * @file
 * dfmp_user.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function dfmp_user_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'NT',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '0cca7541-aa6b-4c95-9c6c-494b8f309d8a',
    'vocabulary_machine_name' => 'territory',
  );
  $terms[] = array(
    'name' => 'SA',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5408b5ee-afa7-44fd-be0a-f7d23588323f',
    'vocabulary_machine_name' => 'territory',
  );
  $terms[] = array(
    'name' => 'TAS',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '5fdfb021-422c-438b-a974-c287343f6132',
    'vocabulary_machine_name' => 'territory',
  );
  $terms[] = array(
    'name' => 'ACT',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '62f976f4-154c-44c0-89b5-07021801d04c',
    'vocabulary_machine_name' => 'territory',
  );
  $terms[] = array(
    'name' => 'WA',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '65162733-a436-4787-a547-e8b4dc9baa5a',
    'vocabulary_machine_name' => 'territory',
  );
  $terms[] = array(
    'name' => 'QLD',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => '9a22c332-6ea2-4702-b7da-4542b281dfdd',
    'vocabulary_machine_name' => 'territory',
  );
  $terms[] = array(
    'name' => 'VIC',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'df2ed6f5-dfba-4107-810c-b8d7dc944a2d',
    'vocabulary_machine_name' => 'territory',
  );
  $terms[] = array(
    'name' => 'NSW',
    'description' => '',
    'format' => 'plain_text',
    'weight' => 0,
    'uuid' => 'e2efb9b0-337d-489e-bd31-014f34283ef2',
    'vocabulary_machine_name' => 'territory',
  );
  return $terms;
}

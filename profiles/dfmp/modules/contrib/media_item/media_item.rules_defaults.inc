<?php
/**
 * @file
 * media_item.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function media_item_default_rules_configuration() {
  $items = array();
  $items['rules_new_media_item'] = entity_import('rules_config', '{ "rules_new_media_item" : {
      "LABEL" : "New Media Item",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "ckan_remote_post", "entityform" ],
      "ON" : { "entityform_insert" : [] },
      "IF" : [
        { "entity_is_of_type" : { "entity" : [ "entityform" ], "type" : "entityform" } }
      ],
      "DO" : [
        { "ckan_remote_post_rules_action_remote_post" : {
            "USING" : { "nid" : "[node:nid]", "sid" : "[entityform:entityform-id]" },
            "PROVIDE" : { "result" : { "result" : "Submission Result" } }
          }
        }
      ]
    }
  }');
  return $items;
}

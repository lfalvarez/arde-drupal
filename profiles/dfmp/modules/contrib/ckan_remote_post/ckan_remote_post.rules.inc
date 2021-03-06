<?php

/**
 * Implement hook_rules_action_info().
 */
function ckan_remote_post_rules_action_info() {

  return array(
	'ckan_remote_post_rules_action_remote_post' => array(
	  'label' => t('Post form/node content to remote CKAN'),
	  'group' => t('Custom'),
	  'parameter' => array(
		'nid' => array(
		  'type' => 'text',
		  'label' => t('Node ID'),
		  'description' => t('Enter a value for a string that will be hashed using the md5 hash-algorithm.'),
		),
		'sid' => array(
		  'type' => 'text',
		  'label' => t('Submission ID'),
		  'description' => t('Enter a value for a string that will be hashed using the md5 hash-algorithm.'),
		)
	  ),
	  'provides' => array(
		'result' => array(
		  'type' => 'text',
		  'label' => t('Submission Result'),
		),
	  ),
	  'callback' => 'ckan_remote_post_rules_action_remote_post',
	),
  );
}


// This callback creates the hashed string by using the parameters provided through rules' UI
function ckan_remote_post_rules_action_remote_post($nid, $sid) {

  $string = "";

  $node = node_load($nid);
  /*   if ($node && $node->type == 'webform') {
		$submission =  webform_get_submission($nid, $sid);
		// Skip draft forms:
		if ($submission->is_draft) {
			return;
		}

		// Create a map with webform component ID's and the component themselves,
		// handy later on.
		$component_map = array();
		foreach ($node->webform['components'] as $component) {
			$component_map[$component['cid']] = $component;
		}

		// Prepare the submission data for remote posting. Creating a two-dimensional
		// array of form field names and the data.
		$payload = array();
		$value = "";
		foreach ($submission->data as $cid => $component_data) {
			if (isset($component_data['value'])) {
				$value = implode('; ', $component_data['value']);
			} else {
				$value = implode('; ', $component_data);
			}

			if (!empty($value)) {
				$payload[$component_map[$cid]['form_key']] = $value;
			}

		}
		if (isset($_GET['project'])) {
			$project_id = $_GET['project'];
			$project = node_load($project_id);
			$payload['project'] = $project->title;
		} else if (isset($_POST['submitted']['project'])) {
			$project_id = $_POST['submitted']['project'];
			$project = node_load($project_id);
			$payload['project'] = $project->title;
		}
		submit_key_value($payload);

	} else if ($node && $node->type == 'project') {
		$payload = Array();
		//$data=field_info_instances("node",$node-type);
		//where $source_node_type is the type of the node (not its name).
		// https://api.drupal.org/api/drupal/modules%21field%21field.info.inc/function/field_info_fields/7
		foreach ($node as $field_name => $field) {
			if ($field_name == 'field_mid_project') {
				$project_id = $field['und'][0]['value'];
				$project = node_load($project_id);
				#TODO fix project title is null
				$payload['project'] = $project->title;
			} else if (strpos($field_name,"field_") !== false) {
				$field_name = str_replace("field_", "", $field_name);
				#TODO implementation partners field
				if ($field_name == 'rebaselined_total_budget' || $field_name == 'original_total_budget') {
foreach ($field['und'] as $row) {
	$payload[$field_name] = $row[0]['value'];
}
				} else if (isset($field['und'][0]['value'])) {
					$payload[$field_name] = $field['und'][0]['value'];
				} else if (isset($field['und'][0]['tid'])) {
					$term = taxonomy_term_load($field['und'][0]['tid']);
					$payload[$field_name] = $term->name;
				}
			}
		}
		submit_key_value($payload);
	} else */
  if ($nid == "") {
	$entityform_id = $sid; // entity form id
	$entityform = entityform_load($entityform_id);
	$entityform_wrapper = entity_metadata_wrapper('entityform', $entityform);
	$payload = Array();
	//$data=field_info_instances("node",$node-type);
	//where $source_node_type is the type of the node (not its name).
	// https://api.drupal.org/api/drupal/modules%21field%21field.info.inc/function/field_info_fields/7
	foreach ($entityform as $field_name => $field) {
	  if (strpos($field_name, "field_") !== FALSE) {
		$field_name = str_replace(array(
		  "field_",
		  "mid_",
		  'end_'
		), "", $field_name);
		if (isset($field['und'][0]['value'])) {
		  $payload[$field_name] = $field['und'][0]['value'];
		}
		else {
		  if (isset($field['und'][0]['tid'])) {
			$term = taxonomy_term_load($field['und'][0]['tid']);
			$payload[$field_name] = $term->name;
		  }
		  else {
			if (isset($field['und'][0]['geom'])) {
			  $payload['lat'] = $field['und'][0]['lat'];
			  $payload['lon'] = $field['und'][0]['lon'];
			}
		  }
		}
	  }
	}
	submit_key_value($payload);
  }

  return array(
	'result' => $string,
  );
}

<?php
/**
 * @file
 * ckan_api.singleton.inc
 */


class ckan_api_ValidateError extends Exception{}
class ckan_api_ActionNotExistsError extends Exception{}
class ckan_api_CKANSideError extends Exception{}


class CkanApi {
  private $api_key;
  private $base_url;

  private $post_actions = array(
      /**
       * Create new user
       *
       * @name
       * (string) – (required) the name of the new user, a string between 2 and 100 characters in length, containing only lowercase alphanumeric characters, - and _
       *
       * @email
       * (string) – (required) the email address for the new user
       *
       * @password
       * (string) – (required) the password of the new user, a string of at least 4 characters
       *
       * @id
       * (string) – (optional) the id of the new user
       *
       * @fullname
       * (string) – (optional) the full name of the new user
       *
       * @about
       * (string) – (optional) a description of the new user
       *
       * @openid
       * (string) – (optional)
       */
      'user_create'   => array( 'required'  => array('password', 'name', 'email') ),
      'user_create_with_dataset'   => array( 'required'  => array('password', 'name', 'email') ),
      'user_update_dataset'   => array( 'required'  => array('title', 'description', 'tags') ),

      /**
       * Create new package
       *
       * @ name
       * (string) – (required) the name of the new dataset, must be between 2 and 100 characters long and contain only lowercase alphanumeric characters, - and _
       *
       * @ title
       * (string) – (optional) the title of the dataset (default: same as name)
       *
       * @ author
       * (string) – (optional) the name of the dataset’s author
       *
       * @ author_email
       * (string) – (optional) the email address of the dataset’s author
       *
       * @ maintainer
       * (string) – (optional) the name of the dataset’s maintainer
       *
       * @ maintainer_email
       * (string) – (optional) the email address of the dataset’s maintainer
       *
       * @ license_id
       * (license id string) – (optional) the id of the dataset’s license
       *
       * @ notes
       * (string) – (optional) a description of the dataset
       *
       * @ url
       * (string) – (optional) a URL for the dataset’s source
       *
       * @ version
       * (string, no longer than 100 characters) – (optional)
       *
       * @ state
       * (string) – (optional) the current state of the dataset, e.g. 'active' or 'deleted', only active datasets show up in search results and other lists of datasets, this parameter will be ignored if you are not authorized to change the state of the dataset (default: 'active')
       *
       * @ type
       * (string) – (optional) the type of the dataset
       *
       * @ resources
       * (list of resource dictionaries) – (optional) the dataset’s resources
       *
       * @ tags
       * (list of tag dictionaries) – (optional) the dataset’s tags
       *
       * @ extras
       * (list of dataset extra dictionaries) – (optional) the dataset’s extras, extras are arbitrary (key: value) metadata items that can be added to datasets, each extra dictionary should have keys 'key' (a string), 'value' (a string)
       *
       * @ relationships_as_object
       * (list of relationship dictionaries) – (optional)
       *
       * @ relationships_as_subject
       * (list of relationship dictionaries) – (optional)
       *
       * @ groups
       * (list of dictionaries) – (optional) the groups to which the dataset belongs, each group dictionary should have one or more of the following keys which identify an existing group: 'id' (the id of the group, string), or 'name' (the name of the group, string)
       *
       * @ owner_org
       * (string) – (optional) the id of the dataset’s owning organization
       */
      'package_create'=> array( 'required'  => array('name') ),

     /**
      * Add new asset. Returns id of newly created CKAN resource
      *
      * @ url
      * (string) – (required)
      * @ name
      * (string) – (required)
      * @ size
      * (string) – (required)
      * @ type
      * (string) – (required)
      * @ license
      * (string) – (required)
      * @ thumbnailUrl
      * (string) – (required)
      */
      'user_show'                 => array( 'required'  => array('id') ),
      'user_add_asset'            => array( 'required'  => array('url', 'name', 'size', 'type', 'license', 'thumbnailUrl') ),
      'user_remove_asset'         => array( 'required'  => array() ),
      'search_item'               => array( 'required'  => array() ),
      'user_update_asset'         => array( 'required'  => array() ),
      'delete_user_test'          => array( 'required'  => array('user') ),
      'create_organization'       => array( 'required' => array('name') ),
      'organization_add_user'     => array( 'required' => array('organization', 'user') ),
      'organization_remove_user'  => array( 'required' => array('organization', 'user') ),
      'flag_asset'                => array( 'required' => array('id', 'assetID') ),
      'dfmp_user_info'            => array( 'required' => array('name') ),
      'dfmp_flickr_update'        => array( 'required' => array() ),
    );
  private $get_actions = array(
    /**
      * Returns dataset with all user's assets
      */
      'user_get_assets'=> array( 'required'  => array() ),
      'dfmp_tags' => array( 'required' => array() ),
      // ''=> array( 'required'  => array() ),
    /**
      * Return a list of the names of the site’s datasets (packages).
      *
      * @ limit
      * (int) – (optional) if given, the list of datasets will be broken into pages of at most limit datasets per page and only one page will be returned at a time
      * @ offset
      * (int) – (optional) when limit is given, the offset to start returning packages from
      */
      'package_list'  => array('required'=>array()),
     /**
      * Searches for packages satisfying a given search criteria.
      * This action accepts solr search query parameters (details below), and returns a dictionary of results, including dictized datasets that match the search criteria, a search count and also facet information.
      *
      * @ q
      * (string) – (optional) the solr query. Default: "*:*"
      * @ fq
      * (string) – (optional) any filter queries to apply. Note: +site_id:{ckan_site_id} is added to this string prior to the query being executed.
      * @ sort
      * (string) – (optional) sorting of the search results. Default: 'relevance asc, metadata_modified desc'. As per the solr documentation, this is a comma-separated string of field names and sort-orderings.
      * @ rows
      * (int) – (optional) the number of matching rows to return.
      * @ start
      * (int) – (optional) the offset in the complete result for where the set of returned datasets should begin.
      * @ facet
      * (string) – (optional) whether to enable faceted results. Default: True.
      * @ facet.mincount
      * (int) – (optional) the minimum counts for facet fields should be included in the results.
      * @ facet.limit
      * (int) – (optional) the maximum number of values the facet fields return. A negative value means unlimited. This can be set instance-wide with the search.facets.limit config option. Default is 50.
      * @ facet.field
      * (list of strings) – (optional) the fields to facet upon. Default empty. If empty, then the returned facet information is empty.
      */
      'package_search'=> array('required'=>array()),

      /**
      * Return a list of the site's datasets (packages) and their resources.
      *
      * @ limit
      * (int) – (optional) if given, the list of datasets will be broken into pages of at most limit datasets per page and only one page will be returned at a time
      * @ offset
      * (int) – (optional) when limit is given, the offset to start returning packages from
      */
      'current_package_list_with_resources'=> array( 'required'  => array() ),

     /**
      * Returns list of all available licenses
      */
      'license_list'=> array( 'required'  => array() ),
      'all_organization_list' => array( 'required' => array() ),
      'all_group_list' => array( 'required' => array() ),
      'all_member_list' => array( 'required' => array('id') ),
      'all_user_list' => array( 'required' => array() ),
      'user_get_organization' => array( 'required' => array( 'user' ) ),
      /**
      * Return the metadata of a dataset (package) and its resources.
      * @ id (string) – the id of the resource(parent id , not assetID)
      */
      'resource_show' => array( 'required' => array('id') ),
      /**
      * Searches for resources satisfying a given search criteria.
      * @ query - string or list of strings of the form {field}:{term1}
      */
      'resource_search' => array( 'required' => array('query', 'limit', 'offset') ),
      /**
      * Returns list of all available licenses
      */
      'resource_items' => array( 'required' => array('id') ),
      /**
      * Returns list of all available licenses
      */
      'dfmp_gallery' => array( 'required' => array() ),
      /**
      * Returns list of all available licenses
      */
      'dfmp_static_gallery' => array( 'required' => array() ),
      /**
      * Returns list of all available licenses
      */
      'static_gallery_reset' => array( 'required' => array() ),

      'dfmp_all_assets' => array( 'required' => array() ),
    );

  private $allowed_methods = array('GET', 'POST');

  private static $_instance = null;

  private function __construct() {
    $this -> set_base_url( variable_get('ckan_url'), variable_get('ckan_api_version', 3) );
  }

  private function set_base_url($base_url, $api_version) {
    $this->base_url = "{$base_url}/api/{$api_version}/action/";
  }

  private function validate($data, $info)  {
    foreach ($info['required'] as $num => $field) {
      if ( !array_key_exists($field, $data) ) throw new ckan_api_ValidateError("Field $field must be defined", 400);
    }
  }

  public function set_api_key($api_key) {
    $this->api_key = $api_key;
  }

    static public function getInstance() {
    if( is_null(self::$_instance) ){
      self::$_instance = new self();
    }
    return self::$_instance;
  }


  public function action($action, $params=array() ) {
    $data = array(
      'headers' => array(
          'Content-Type' => 'application/json; charset=UTF-8',
          'X-CKAN-API-Key' => array_key_exists('api_key', $params) ? $params['api_key'] : variable_get('ckan_admin_key')
      ),
    );
    $params += array('data'=>array());

    if ( array_key_exists($action, $this ->post_actions) ) {
      $this->validate( $params['data'], $this->post_actions[$action] );
      $data['method'] = 'POST';
      $data['data'] = json_encode($params['data']);
    }
    else if ( array_key_exists($action, $this ->get_actions ) ) {
      $this->validate( $params['data'], $this->get_actions[$action] );
      $data['method'] = 'GET';
      $action .=  '?'.http_build_query($params['data']);
    }

    if ( !isset($data['method']) ) throw new ckan_api_ActionNotExistsError('Invalid action');
    $req_res = drupal_http_request( $this->base_url.$action, $data);

    $rdata = json_decode( $req_res->data );
    if ($rdata->success){
      return $rdata->result;
    } else {
      watchdog('ckan_' . $action, serialize($rdata));
      return $rdata->error;
    }
  }

}



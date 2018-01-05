(function($){
  $(document).ready(function(){
    $('#table_org select').change(function(){
      var org = $(this).val();
      $(this).parents('tr').find('input').attr('data-org', org);
    });
  });

  $('#table_org input').live("click", function() {
    var file = {},
      id = $(this).attr('data-id'),
      org = $(this).attr('data-org')

    file['userUpdate'] = {
        id: id,
        org: org
    };

    var request = $.ajax({
      url: "/admin/settings/user-organizations/ajax",
      type: "POST",
      data: file
    });
    request.done(function(msg) {
      alert(Drupal.t('User has been updated.'));
    });
  });

})(jQuery);

Drupal.behaviors.actGovOrganisationUpdate = {
  attach: function(context) {
    jQuery('#edit-act-request', context).change(function() {
      var state = jQuery(this).is(':checked') ? 1 : 0;
      jQuery.ajax({
        url: '/promotion-update',
        data: {action: state}
      });
    });
  }
}



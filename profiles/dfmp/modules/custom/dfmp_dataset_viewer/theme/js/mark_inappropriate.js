
var flagAsset = function() {
    //dialog.dialog( "close" );
    var reason = jQuery('#reason-msg').val(),
        values = jQuery('.flag-asset').val().split('__'),
        dataset_id = values[0],
        asset_id = values[1];

    jQuery.ajax({
        url : '/js/asset/mark/' + dataset_id + '/' + asset_id,
        dataType : 'json',
        data: {reason: reason}
    })
        .done(function (response) {
            if (response.success) {
                jQuery('.flag-asset').replaceWith('<div class="flagged-asset">Resouce is flagged</div>');
            }
            else {
                jQuery('.flag-asset').replaceWith('<div class="status messages">Resouce has not been flagged.</div>');
            }
        })
        .fail(function () {
            jQuery('.flag-asset').replaceWith('<div class="status messages">There was a problem with marking this resource. Please try later.</div>');
        });
}

var dialog = jQuery( "#dialog-form" ).dialog({
    autoOpen: false,
    height: 300,
    width: 350,
    modal: true,
    buttons: {
        "Flag asset": flagAsset,
        Cancel: function() {
            dialog.dialog( "close" );
        }
    }
});

Drupal.behaviors.flagResourceDialog = {
    attach: function(context) {
        jQuery( ".flag-asset", context).on( "click", function() {
            //dialog.dialog( "open" );
            flagAsset();
        });
    }
}

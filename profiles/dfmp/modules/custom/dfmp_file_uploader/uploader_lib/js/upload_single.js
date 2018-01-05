
Drupal.behaviors.deleteAllUploaded = {
    attach: function(context) {
        jQuery(context).on('click', '.delete-all', function(){
            var answer = confirm("You are about to delete the selected images. Are you sure?")
            if (answer){
                deleteAllOrg();
            }
            else{
                return false;
            }
        });

        jQuery(context).on( 'click', '.delete', function () {
            var url = jQuery(this).attr('data-url');
            jQuery(this).parents('tr').remove();
            var request = jQuery.ajax({
                url: url,
                type: "DELETE"
            });
        });

        jQuery('.delete-selected-upload.btn', context).click(function(){
            jQuery('.template-upload input[type=checkbox]:checked').parents('.template-upload').remove();
        });
    }
}

Drupal.behaviors.updateAllUploaded = {
    attach: function(context) {
        jQuery(context).on('click', '.update-all', function() {
            var answer = confirm("You are about to update the selected images. Are you sure?")
            if (answer){
                updateAllOrg();
            }
            else{
                return false;
            }
        });
    }
}

Drupal.behaviors.selectCheckboxes = {
    attach: function(context) {
        jQuery(context).on('click', '.my-videos .box-dfmp input[type=checkbox]', function() {
            if (jQuery(this).hasClass('checked-dfmp')) {
                jQuery('.my-videos tr td:first-child input').prop('checked', false);
                jQuery(this).removeClass('checked-dfmp');
            } else {
                jQuery('.my-videos tr td:first-child input').prop('checked', true);
                jQuery(this).addClass('checked-dfmp');
            }
        });

        jQuery(context).on('click', '.table-striped .box-dfmp input[type=checkbox]', function() {
            if (jQuery(this).hasClass('checked-dfmp')) {
                jQuery('.table-striped .template-upload td:first-child input').prop('checked', false);
                jQuery(this).removeClass('checked-dfmp');
            } else {
                jQuery('.table-striped .template-upload td:first-child input').prop('checked', true);
                jQuery(this).addClass('checked-dfmp');
            }
        });
    }
}

function updateAllOrg() {
  var files = {};
  jQuery('table tr input[name=updated]').parents('tr').each(function(i, e) {
      var updated = jQuery(this).find('input[name=updated]').val();
      if (updated == "updated") {
        var name = jQuery(this).find('.asset-title').text(),
            license = jQuery(this).find('.license-cell .jqxWidget').jqxComboBox('getSelectedItem').originalItem.alias,
            id = jQuery(this).closest('tr').attr('id'),
            description = jQuery(this).find('.asset-description').text();
            tags = jQuery(this).find('.asset-tags').text();

        files[i] = {
            name: name,
            license: license,
            resource_id: id,
            description: description,
            tags: tags,
        };
      }
  });
  var request = jQuery.ajax({
      url: "/js/file_update",
      type: "POST",
      data: ({filesUpdate:files})
  });
  request.done(function(msg) {
      jQuery.ajax({
          type: "POST",
          data: {uploader_action:'refresh'}
      }).done(function (result) {
          jQuery('#my-files-list-wrapper').replaceWith(result);
          var context = jQuery('#my-files-list-wrapper');
          // Drupal.attachBehaviors(context);
          Drupal.behaviors.licenseCombobox.attach();
          Drupal.behaviors.selectCheckboxes.attach();
          Drupal.behaviors.markChanged.attach();
      });
      alert(Drupal.t('Files have been updated.'));
      window.onbeforeunload = null;
  });
}


function deleteAllOrg() {
  var files = {};
  jQuery('table tr input[type=checkbox]:checked').parents('tr').each(function(i, e) {
    var id = jQuery(this).closest('tr').attr('id');
    files[i] = {
      resource_id: id
    };
  });
  var request = jQuery.ajax({
    type: "POST",
    data: ({filesUpdate:files, uploader_action:'delete'})
  });
  request.done(function(result) {
      setTimeout(function(){
          jQuery.ajax({
              type: "POST",
              data: {uploader_action:'refresh'}
          }).done(function (result) {
              jQuery('#my-files-list-wrapper').replaceWith(result);
              var context = jQuery('#my-files-list-wrapper');
              // Drupal.attachBehaviors(context);
              Drupal.behaviors.licenseCombobox.attach();
              Drupal.behaviors.selectCheckboxes.attach();
              Drupal.behaviors.markChanged.attach();
          });
      }, 0);
      window.onbeforeunload = null;
  });
}

// Adds combobox to license field
function dfmpInitComboBox (el) {
    // Gets the list of options
    var license_json = JSON.parse(jQuery('#license_values').val());
        source = [];

    // assign required values for each item of the list
    jQuery.each(license_json, function (key, license) {
        source.push({
            alias: license.id,
            title: license.title,
            value: license.id + ', ' + license.title,
        });
    });

    // Adds comboboxes to all License fields contained in provided element
    el.find('.license-cell').each(function () {
        var license_value = null
            default_value = null;

        // current license value of asset
        if (jQuery(this).find('.license_initial').length) {
            license_value = jQuery(this).find('.license_initial').val();
        }

        // sets default value
        jQuery.each(source, function (key, license) {
            if (license_value == license.alias) {
                default_value = key;
            }
        });

        // inits combobox widget
        jQuery(this).find('.jqxWidget').jqxComboBox({
            source: source,
            selectedIndex: default_value || 0,
            width: '170px',
            height: '30px',
            dropDownWidth: '170px',
            autoComplete: true,
            searchMode: 'containsignorecase',
            renderer:  function (index, label, value) {
                var datarecord = source[index];
                return "<div style='padding: 0px; margin: 5px; float: left'><em style='text-decoration: underline;'>"
                    + datarecord.alias
                    + "</em><div overflow='hidden'>" + datarecord.title + "</div></div>"
            },
            renderSelectedItem: function(index, item) {
                if (item != null) {
                    var label = item.originalItem.alias;
                    return label;
                }
                return "";
            }
        });
    });
}

// renders license combobox
Drupal.behaviors.licenseCombobox = {
    attach: function (context, settings) {
        dfmpInitComboBox (jQuery('.my-videos'));
    }
};

// renders license combobox
Drupal.behaviors.markChanged = {
  attach: function (context, settings) {
    jQuery(context).on('change','table.my-videos tr input[type=text], table.my-videos tr input[type=textarea]', function () {
      jQuery(this).parents('tr').find('input[name="updated"]').val('updated');
    });
    jQuery('.jqxWidget').bind('select', function (event) {
      jQuery(this).parents('tr').find('input[name="updated"]').val('updated');
      window.onbeforeunload = function() {
        return 'This page is asking you to confirm that you want to leave - data you have entered may not be saved.';
      }
    });
  }
};


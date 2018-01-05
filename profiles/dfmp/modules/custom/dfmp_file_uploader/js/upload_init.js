(function($){
  $(document).ready(function(){

    $('.asset-title').live('click', function() {
      if (!$(this).find('input').length) {
        UpdateMeta($(this));
      }
    });
    $('.asset-description').live('click', function() {
      if (!$(this).find('input').length) {
        UpdateMeta($(this), 'desc');
      }
    });
    $('.asset-tags').live('click', function() {
      if (!$(this).find('input').length) {
        UpdateMeta($(this), 'tags');
      }
    });

    function UpdateMeta(element, id) {
      var text = element.text();
      
      escapeHtml = function(unsafe) {
          return unsafe
              .replace(/&/g, "&amp;")
              .replace(/</g, "&lt;")
              .replace(/>/g, "&gt;")
              .replace(/"/g, "&quot;")
              .replace(/'/g, "&#039;");
      }

      if ((text == 'Add a description...' && id == 'desc') || (text == 'Add tags...' && id == 'tags')) {
          text = '';
      }
      var input = $('<input id="attribute" type="text" value="' + escapeHtml(text) + '" />');
      element.text('').append(input);
      input.select();

      input.blur(function() {
        var text = $('#attribute').val();
        if (text.trim() == ''  && id == 'desc') {
            text = 'Add a description...';
        } else if (text.trim() == ''  && id == 'tags') {
            text = 'Add tags...';
        }
        $('#attribute').parent().text(text);
        $('#attribute').remove();
      });
    }
    
    $.Placeholder.init();
    // console.log(this.changedUploads);
    jQuery('body').on('change','#my-files-list-wrapper input', function(event) {
        window.onbeforeunload = function() {
          return 'This page is asking you to confirm that you want to leave - data you have entered may not be saved.';
        }
    });
  });

  Drupal.behaviors.goToPage = {
    attach: function(context, settings) {
      jQuery('.go-to-page', context).click(function(){
        var page = jQuery('.uploader-go-to-wrap input').val();
        if ((page - 0) == page && (''+page).trim().length > 0) {
          window.location.href = '/dfmp/file_uploader?page=' + (page - 1);
        }
        return false;
      });
    }
  }

  Drupal.behaviors.uploadsAjaxPager = {
    attach: function(context, settings) {
      jQuery(context).on('click','#file-uploader-pager .pager li a, .my-videos a.sort-ajax', function(event) {
        event.preventDefault();
        var link = $(this).attr('href'),
            getQuery = link.split('?'),
            query = getQuery[1] || '',
            isAjaxed = (query.indexOf('ajaxedPager') > -1) ? {} : {'ajaxedPager': true};

        $.ajax({
          method: 'GET',
          url: link,
          data: isAjaxed,
          success: function(result) {
            // alert('success');
            $('#my-files-list-wrapper').replaceWith(result);
            dfmpInitComboBox (jQuery('.my-videos'));
          }
        });
      });
    }
  }
})(jQuery);

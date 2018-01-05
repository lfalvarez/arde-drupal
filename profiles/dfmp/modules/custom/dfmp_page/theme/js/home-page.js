(function ($) {
    $(document).ready(function () {
      var setWidth = function(leftInit, widthInit) {
        if (widthInit) {
          $('#minipanel-two-50-middle-wrapper, #minipanel-two-50-bottom-wrapper').css('width', widthInit);
        }
        else {
          $('#minipanel-two-50-middle-wrapper, #minipanel-two-50-bottom-wrapper').width(jQuery('#minipanel-three-33-middle-fw-wrapper .container').width());
        }

        if (leftInit === 0) {
          $('#minipanel-two-50-middle-wrapper, #minipanel-two-50-bottom-wrapper').css('left', leftInit + 'px');
        }
        else {
          var offset = jQuery('#mini-panel-dfmp_header #minipanel-three-33-middle-fw-wrapper > .container')[0].offsetLeft;
          var left = offset + 35;
          $('#minipanel-two-50-middle-wrapper, #minipanel-two-50-bottom-wrapper').css('left', left + 'px');
        }
      }

      if ($(window).width() > 768) {
        setWidth();
      }
      else {
        setWidth(0, 'auto');
        $('#dfmp-search-result-form #edit-search-title').attr('placeholder', 'Search')
      };

      $(window).resize(function(){
        if ($(window).width() > 727) {
          setWidth();
          $('#dfmp-search-result-form #edit-search-title').attr('placeholder', 'Search for CBR images and videos');
        }
        else {
          setWidth(0, 'auto');
          $('#dfmp-search-result-form #edit-search-title').attr('placeholder', 'Search');
        }

      });

      // This script will work properly only with Hardcoded blocks that are dissabled because of the rework from ACTGXCDGD-77
      // var titleBlock = $('.home-25-title')
      // $('#four-25-middle-wrapper .four-25-first').before(titleBlock);

      selectParameters('edit-search-type', 'click-type', 'edit-search-licence');
      selectParameters('edit-search-licence', 'click-type-licence', 'edit-search-type');

      $('#click-type').click(function(){
        $('#edit-search-licence').hide();
        $('#edit-search-type').toggle();
      });

      $('#click-type-licence').click(function(){
        $('#edit-search-type').hide();
        $('#edit-search-licence').toggle();
      });

      function selectParameters(element, click, hide) {
        $('#' + element +' :radio').first().parent().addClass('selected');
        $('#' + element +' :radio').change(function () {
          $('#' + element +' :radio[name=' + this.name + ']').parent().removeClass('selected');
          $(this).parent().addClass('selected');
          var value = $(this).parent('label').text();
          $('#' + click).text(value);
          $('#' + element).hide();
        });
      }

    });
}(jQuery));

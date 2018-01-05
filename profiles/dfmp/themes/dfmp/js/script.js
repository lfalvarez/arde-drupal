Drupal.behaviors.dfmp_rotator = {
  attach: function (context, settings) {
    jQuery( ".dfmp_rotate" ).click(function() {
      jQuery(this).siblings('div.loader').show();
      var id = jQuery(this).attr('href');
      jQuery.ajax({
        type: 'GET',
        url: '/imagerotator/' + id + '?clock=1',
        dataType: 'json',
        success: function (data) {
          var src = jQuery("#" + id).attr('src');
          var href = jQuery("#" + id).parent().attr('href');
          jQuery("#" + id).parent().attr('href', href + '?' + Date.now());
          jQuery("#" + id).attr('src', src + '?' + Date.now());
          jQuery("#" + id).parent().siblings("div.loader").hide();
        }
      });
      return false;
    });

    jQuery( ".dfmp_rotate_unclock" ).click(function() {
      jQuery(this).siblings('div.loader').show();
      var id = jQuery(this).attr('href');
      jQuery.ajax({
        type: 'GET',
        url: '/imagerotator/' + id + '?clock=0',
        dataType: 'json',
        success: function (data) {
          var src = jQuery("#" + id).attr('src');
          var href = jQuery("#" + id).parent().attr('href');
          jQuery("#" + id).parent().attr('href', href + '?' + Date.now());
          jQuery("#" + id).attr('src', src + '?' + Date.now());
          jQuery("#" + id).parent().siblings('div.loader').hide();
        }
      });
      return false;
    });
  }
};

(function($) {
  $(document).ready(function () {
    function runSlideMenu(triggerClass) {
      $(triggerClass).slideReveal({
        trigger: $("#navigation-toggle"),
        position: "right"
      });
    }

    function headerWidth() {
      if ($(window).width() >= 909) {
        $("body").css('left', '0px');
        $('#mini-panel-dfmp_header .minipanel-three-33-first-fw').removeClass('prime-mobile');
        $('.slideReady').slideReveal("hide");
        $('#navigation-toggle').removeClass('active-toggle');
      }
      else {
        $('#mini-panel-dfmp_header .minipanel-three-33-first-fw').addClass('prime-mobile');
      }
    }

    headerWidth();
    $('body').on('click', '#navigation-toggle', function(e) {
      e.preventDefault();
      $(this).toggleClass('active-toggle');
    });

    $("#mini-panel-dfmp_header .minipanel-three-33-second-fw").addClass('slideReady');
    runSlideMenu('.slideReady');

    $(window).resize(function() {
      headerWidth();
    });

    // Images lazy loader
    $(".gallery-item a > img").lazyload({
      effect : "fadeIn"
    });

    $('.field-collection-item-field-accodrion:not(.active)').find('.field_accordion_body').hide();
    $('.field_accordion_title').click(function(e) {
       e.preventDefault(); // prevent the default action
       e.stopPropagation(); // stop the click from bubbling
       if (!$(this).parent().hasClass('active')) {
         $('.field-collection-item-field-accodrion').removeClass('active');
         $(this).parent().addClass('active');
         $('.field-collection-item-field-accodrion').find('.field_accordion_body').slideUp();
         $(this).next().slideDown();
       }
       else {
          $('.field-collection-item-field-accodrion').removeClass('active');
          $('.field-collection-item-field-accodrion').find('.field_accordion_body').slideUp();
       }
     });
  });
})(jQuery);

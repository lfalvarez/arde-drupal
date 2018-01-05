Drupal.behaviors.targetLinks = {
    attach: function(context, settings) {
        jQuery('#gallery-top .title-desc a').length && jQuery('#gallery-top .title-desc a').attr('target', '_blank');
    }
}

Drupal.behaviors.goBackLink = {
    attach: function(context, settings) {
        jQuery('.single-image-back').length && jQuery('.single-image-back').css('width', jQuery('.image-center .fancybox_gallery img').width() + 'px');
    }
}
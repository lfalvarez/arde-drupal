
var updateTags = function() {
    var tags = [];
    jQuery('.tags-list ul li').each(function(){
        tags.push(jQuery(this).find('span').text());
    });
    var tags_list = tags.join(',');
    jQuery('#edit-search-tags-hidden').val(tags_list);
}

var addTag = function(tag) {
    jQuery('.tags-list ul').append('<li><span>' + tag + '</span><span class="remove-tag" href="#"></span></li>');
}

Drupal.behaviors.addSearchTags = {
    attach: function(context, settings) {

        jQuery('.tag-plus-ico a').click(function(){
            var text = jQuery('#edit-search-tags').val();
            addTag(text);
            updateTags();
            jQuery('#edit-search-tags').val('');
            return false;
        });

    }
}

Drupal.behaviors.refineSearch = {
    attach: function(context, settings) {
        if (location.search) {
            var splitSearch = location.search.split('?'),
                splitQuery = splitSearch[1].split('&');
            if (splitQuery.length != 1) jQuery('.dfmp-serach-form').css('display', 'block');
        }
        jQuery('.dfmp-refine-search-btn a', context).click(function(){
            jQuery('.download-collection-box', context).hide(0, 'swing', function() {
                jQuery('.gallery-item a[data-fancybox-href^="http"] img').removeClass('external-image');
            });
            var form = jQuery('.dfmp-serach-form', context);
            form.slideToggle();
            return false;
        });
    }
}

Drupal.behaviors.downloadBox = {
    attach: function(context, settings) {
        if (jQuery('a.dwn-expend-box').hasClass('disabled_download')) {
            jQuery('a.disabled_download').tooltipster({
                trigger: 'click',
                touchDevices: true,
                timer: 5000
            });
        }
        jQuery('a.dwn-expend-box', context).click(function() {
            if (!jQuery('a.dwn-expend-box').hasClass('disabled_download')) {
                jQuery('.dfmp-serach-form', context).hide();
            }
            var box = jQuery('.download-collection-box', context);
            box.slideToggle(400, 'swing', function() {
                jQuery('.gallery-item a[data-fancybox-href^="http"] img').toggleClass('external-image');
            });
            return false;
        });
    }
}

Drupal.behaviors.customSelects = {
    attach: function(context) {
        jQuery('#edit-search-type-media, #edit-search-licence').selectbox();
        jQuery('.sbHolder').each(function(){
            jQuery(this).find('.sbOptions li').eq(0).addClass('checked');
        });
    }
}

Drupal.behaviors.relocateBlocks = {
    attach: function(context) {
        // Replace search form and download box into other div
        if (jQuery(window).width() <= 909 && jQuery('.dfmp-gallery-top-second > .dfmp-serach-form').length == 0) {
            jQuery('.dfmp-gallery-top-second').append(jQuery('.dfmp-serach-form'));
            jQuery('.download-collection-box').length != 0 && jQuery('.download-collection').append(jQuery('.download-collection-box'));
        }

        jQuery(window).resize(function() {
          if (jQuery(window).width() <= 909 && jQuery('.dfmp-gallery-top-second > .dfmp-serach-form').length == 0) {
            jQuery('.dfmp-gallery-top-second').append(jQuery('.dfmp-serach-form'));
            jQuery('.download-collection-box').length != 0 && jQuery('.download-collection').append(jQuery('.download-collection-box'));
          }
          else if (jQuery(window).width() >= 909) {
            jQuery('#popups-below').after(jQuery('.dfmp-serach-form'));
            jQuery('.dfmp-serach-form').after(jQuery('.download-collection-box'));
          }
        });
    }
}

jQuery(document).ready(function(){
    var text = jQuery('#edit-search-tags-hidden').val();
    if (text.length < 1) {
        return;
    }
    var tags = text.split(',');
    jQuery(tags).each(function(){
        addTag(this);
    });
});

jQuery('.tags-list .remove-tag').live('click', function(){
    jQuery(this).parent('li').remove();
    updateTags();
    return false;
});

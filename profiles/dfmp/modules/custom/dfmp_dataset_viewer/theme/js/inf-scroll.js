(function ($) {
    var flag_scroll = false;
    Drupal.settings.infinityScrollWhell = true;

    $(document).ready(function () {
        $('#two-66-33-bottom-wrapper').css('margin-top',
          $(document).height() 
          - ( $('#two-66-33-top-wrapper').height() + $('#two-66-33-middle-wrapper').height() ) 
          - $('#two-66-33-bottom-wrapper').height()
        );
        if ($('body').height() < $(window).height()) {
            $('#two-66-33-middle-wrapper').height($(window).height() - $('#two-66-33-top-wrapper').height() - $('#two-66-33-bottom-wrapper').height());
        }
        $("img").one("load", function() {
        }).each(function() {
            if ($('body').height() < $(window).height()) {
                $('#two-66-33-middle-wrapper').height($(window).height() - $('#two-66-33-top-wrapper').height() - $('#two-66-33-bottom-wrapper').height());
            }
        });

        /*
        Disable infinity scroll for galleries
        */
        //$(window).on('scroll', function(){
        //    if((!$('.gallery-holder').length && $(window).scrollTop() + $(window).height() == $(document).height()) ||
        //        ($('.gallery-holder').length && $(window).scrollTop() >= $('.gallery-holder').offset().top + $('.gallery-holder').outerHeight() - window.innerHeight)) {
        //        startScrollLoading();
        //    }
        //});
        //jQuery(document).bind("mousewheel", function (event,delta,nbr) {
        //    if (Drupal.settings.infinityScrollWhell && delta < 0 && jQuery(document).height() <= jQuery(window).height()) {
        //        startScrollLoading();
        //    }
        //})

    });

    function startScrollLoading() {
        if(flag_scroll){
            return false;
        }

        flag_scroll = true

        var g = $('#assetimimage');
        var loader = $('.dfmp-loader');
        var offset = g.data('page');
        offset++;
        if (typeof Drupal.settings.infinity_scroll.max_pages != 'undefined' && offset >= Drupal.settings.infinity_scroll.max_pages) {
            return false;
        }

        $('#assetimimage .pulse-wrap').slideDown(400);
        loader.css('display', 'block');
        $('#assetimimage').css('padding-bottom', 0)
        g.data('page', offset);
        url = window.location.pathname.replace(/\/+$/, '');
        var hashes = window.location.search.slice(window.location.search.indexOf('?') + 1).split('&'),
            params = {};
        jQuery(hashes).each(function(){
            var hash = this.split('=');
            if (hash.length < 2) {
                return;
            }
            params[hash[0]] = hash[1];
        });
        params['callback'] = true;
        params['page'] = offset;
        $.ajax({
            url: url,
            data: params,
            success: function (data) {
                jQuery('#two-66-33-middle-wrapper').height('auto');

                g.append(data);
                loader.css('display', 'none');
                loader.remove();
                g.append(loader);

                //Search result counter
                if(data.length > 0){
                    $('.results-count-wrapper .current').text( parseInt($('.results-count-wrapper .current').text()) + data.length);
                }

                Drupal.attachBehaviors(data, Drupal.settings);

                imagesLoaded(g, startMasonry);

                $('#assets-amount').text((g.children().length - 2));
                $('#assetimimage .pulse-wrap').slideUp(400);

                $('#assetimimage').css('padding-bottom', 40)

                flag_scroll = false
                if (jQuery(document).height() > jQuery(window).height()) {
                    Drupal.settings.infinityScrollWhell = false;
                }
            },
            error: function (d, e) {
                $('#assetimimage .pulse-wrap').slideUp(400);
                loader.css('display', 'none');
                $('#assetimimage').css('padding-bottom', 40)
                flag_scroll = false
            }
        });
    }

    window.onload = function(){
      $(document).on('error', 'img', imgError)
      startMasonry();
    }


    function startMasonry(){
        //imgError();
        //if (typeof window.Masonry != 'undefined') {
        //     var msnry = new Masonry( '#assetimimage', {
        //        columnWidth: 5,
        //        isResizeBound: true,
        //        itemSelector: '.gallery-item'
        //      });
        //}
    }

    function imgError(){
      $('.gallery-item').each(function(){
        if (!$(this).find('img').length) { $(this).remove();}
      });
    }

}(jQuery));

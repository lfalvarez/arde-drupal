/*
 * jQuery File Upload Plugin JS Example 8.9.1
 * https://github.com/blueimp/jQuery-File-Upload
 *
 * Copyright 2010, Sebastian Tschan
 * https://blueimp.net
 *
 * Licensed under the MIT license:
 * http://www.opensource.org/licenses/MIT
 */

/* global $, window */

(function ($) {
    'use strict';

    function generateUUID() {
        var d = new Date().getTime();
        var uuid = 'xxxxxxxx-xxxx-4xxx-yxxx-xxxxxxxxxxxx'.replace(/[xy]/g, function(c) {
            var r = (d + Math.random()*16)%16 | 0;
            d = Math.floor(d/16);
            return (c=='x' ? r : (r&0x3|0x8)).toString(16);
        });
        return uuid;
    };
    function DfmpTeacher(){
        var self = this;
        
        self.tipTopOffset = 200;
        self.scrollTime = 500;
        self.showTime = 1000;
        self.processingPopover = false;
        
        //get sorted list of all tips
        self.allPopovers = $('[data-toggle=popover].tutorial-popover').sort(
            function(first, second){
              return $(first).data('lesson') > $(second).data('lesson');
            }
        )

        //show tip
        self.showPopover = function(el){
            self.processingPopover = true;
            el = el || self.allPopovers.first()
            self.sureVisible(el);
            setTimeout(
                function(){
                    el.addClass('visible-popover').popover('show')
                    self.processingPopover = false;
                }, self.showTime
            );
        }

        //remove tip and return its number
        self.hidePopover = function(el){
            return el.popover('destroy').removeClass('visible-popover').data('lesson');
        }

        //next tip
        self.nextPopover = function(event){
            if (self.processingPopover) return;
            //hide visible tip
            var currentPopover = self.hidePopover($('.visible-popover'));
            //remove hidden tips from list
            self.allPopovers = self.allPopovers.filter(
                function(index, item){
                    return $(item).data('lesson') > currentPopover;
                }
            );
            if (!self.allPopovers.length) return;
            //show next tip
            self.showPopover(self.allPopovers.first());


        }

        //check if element on visible part of screen and scroll if not
        self.sureVisible =  function(el) {
            el = el || self.allPopovers.first()
            var vpH = $(window).height(), // Viewport Height
                st = $(window).scrollTop(), // Scroll Top
                y = $(el).offset().top,
                elementHeight = $(el).height();

            if ((y < (vpH + st)) && (y > (st - elementHeight)) && (y > st + self.tipTopOffset)) return;
            $('html, body').animate({
                scrollTop: y - self.tipTopOffset
            }, self.scrollTime);
        }

    }
    
    // Initialize the jQuery File Upload widget:
    $('#fileupload').fileupload({
        url: '/dfmp/file_uploader/upload',
        maxFileSize: parseInt(Drupal.settings.file_uploader_max) * 1048576,
        sequentialUploads: false,
        prependFiles: true,
        limitConcurrentUploads: 4,
        add: function (e, data) {

            // Split filename to extension and name
            var splitName = data.files[0].name.split('.');
            data.files[0].nameOnly = splitName[0];
            data.files[0].extension = splitName[1];

            // we need to ad unique id to each added file
            data.files[0].id = generateUUID();

            // we need to process added files
            var $this = $(this);
            data.process(function () {
                return $this.fileupload('process', data);
            });
            $.blueimp.fileupload.prototype.options.add.call(this, e, data);

            // we need to apply combobox for licenses
            dfmpInitComboBox($('tr.template-upload'));
        },
        submit: function (e, data) {
            var $this = $(this);

            var id = data.files[0].id;
            var files = $('.files tr#' + id);
            var params = [];

            // we need to add values to formData
            params.push({
                name: 'license',
                value : files.find('.jqxWidget').eq(0).jqxComboBox('getSelectedItem').originalItem.alias
            });
            params.push({
                name: 'description',
                value: files.find('input.description_resource')[0].value
            });
            params.push({
                name: 'tags',
                value: files.find('input.tags_resource')[0].value
            });
            params.push({
                name: 'name',
                value: files.find('input.name_resource')[0].value + "." + files.find('input.name_extension')[0].value
            });

            data.formData = params;
            data.jqXHR = $this.fileupload('send', data);
            return false;
        }
    });

    // Enable iframe cross-domain access via redirect option:
    $('#fileupload').fileupload(
        'option',
        'redirect',
        window.location.href.replace(
            /\/[^\/]*$/,
            '/cors/result.html?%s'
        )
    );

    if (window.location.hostname === 'blueimp.github.io') {
        // Demo settings:
        $('#fileupload').fileupload('option', {
            url: '//jquery-file-upload.appspot.com/',
            // Enable image resizing, except for Android and Opera,
            // which actually support image resizing, but fail to
            // send Blob objects via XHR requests:
            disableImageResize: /Android(?!.*Chrome)|Opera/
                .test(window.navigator.userAgent),
            maxFileSize: 5000000,
            acceptFileTypes: /(\.|\/)(gif|jpe?g|png)$/i
        });
        // Upload server status check for browsers with CORS support:
        if ($.support.cors) {
            $.ajax({
                url: '//jquery-file-upload.appspot.com/',
                type: 'HEAD'
            }).fail(function () {
                $('<div class="alert alert-danger"/>')
                    .text('Upload server currently unavailable - ' +
                            new Date())
                    .appendTo('#fileupload');
            });
        }
    } else {
        // Load existing files:
        $('#fileupload').addClass('fileupload-processing');
        $.ajax({
            // Uncomment the following to send cross-domain cookies:
            //xhrFields: {withCredentials: true},
            url: $('#fileupload').fileupload('option', 'url'),
            dataType: 'json',
            context: $('#fileupload')[0]
        }).always(function () {
            $(this).removeClass('fileupload-processing');
        }).done(function (result) {
            $(this).fileupload('option', 'done')
                .call(this, $.Event('done'), {result: result});
        });
    }
    
    $('#fileupload').bind('fileuploadadd', function (e, data) {
        var uploadErrors = [];
        var acceptFileImages = /^image|video|audio\/(gif|jpe?g|png|m4v|avi|mpg|mp4|mp3)$/i;
        if(typeof data.originalFiles[0]['type'] != 'undefined' && data.originalFiles[0]['type'].length && !acceptFileImages.test(data.originalFiles[0]['type'])) {
            uploadErrors.push('Not an accepted file type');
        }
        if(uploadErrors.length > 0) {
            alert(uploadErrors.join("\n"));
            data.files = [];
            data.abort();
        }
    });
    
    $('#fileupload').bind('fileuploaddone', function (e, data) {
        $.ajax({
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
        return true;
        
    });
    
    $('#fileupload').bind('fileuploadprocessdone', function(e, data) {
        function split(val) {
            return val.split(/,\s*/);
        }
        function extractLast(term) {
            return split(term).pop();
        }
        $(".template-upload .tags_resource")
                // don't navigate away from the field on tab when selecting an item
                .bind("keydown", function(event) {
                    if (event.keyCode === $.ui.keyCode.TAB &&
                            $(this).autocomplete("instance").menu.active) {
                        event.preventDefault();
                    }
                })
                .autocomplete({
                    minLength: 0,
                    source: function(request, response) {
                        // delegate back to autocomplete, but extract the last term
                        response($.ui.autocomplete.filter(
                                Drupal.settings.dfmp_tags, extractLast(request.term)));
                    },
                    focus: function() {
                        // prevent value inserted on focus
                        return false;
                    },
                    select: function(event, ui) {
                        var terms = split(this.value);
                        // remove the current input
                        terms.pop();
                        // add the selected item
                        terms.push(ui.item.value);
                        // add placeholder to get the comma-and-space at the end
                        terms.push("");
                        this.value = terms.join(", ");
                        return false;
                    }
                });
    });

    //file_uploader tutorial
    //show only if link has anchor 'tutorial'
    if (window.location.hash === '#tutorial'){

        var teacher = new DfmpTeacher();

        $('body').on('click', teacher.nextPopover);
        teacher.showPopover();

    }
    
})(jQuery);

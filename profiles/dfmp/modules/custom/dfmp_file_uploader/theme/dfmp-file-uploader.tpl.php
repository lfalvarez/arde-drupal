<?php
/**
 * @file
 * File uploader template file
 */
?>
<noscript><link rel="stylesheet" href="/<?php print drupal_get_path('module', 'dfmp_file_uploader')?>/css/jquery.fileupload-noscript.css"></noscript>
<noscript><link rel="stylesheet" href="/<?php print drupal_get_path('module', 'dfmp_file_uploader')?>/css/jquery.fileupload-ui-noscript.css"></noscript>


<div id="uploader-wrapper">
  <h1><?php print t('Add images and videos');?></h1>
  <div class="uploader-description-header">    
    <div class="uploader-description-icon"></div>
    <div class="upload-rotate"></div>
    <div class="uploader-description-text">
      <span><span class="bold-span">Allowed extensions of uploading files:</span> gif, jpeg, png, m4v, avi, mpg, mp4, mp3.</span><br>
      <span><span class="bold-span">Maximum file uploaded size:</span> <?php print $file_size;?></span><br>
      <span><span class="bold-span">Maximum files per upload batch:</span> 4</span>
    </div>    
  </div>
  <div class="border-uploader">
    <h1>Upload</h1>
  </div>
    <!-- The file upload form used as target for the file upload widget -->
    <form id="fileupload" action="//jquery-file-upload.appspot.com/" method="POST" enctype="multipart/form-data">
        <!-- Redirect browsers with JavaScript disabled to the origin page -->
        <noscript><input type="hidden" name="redirect" value="https://blueimp.github.io/jQuery-File-Upload/"></noscript>
        <!-- The fileupload-buttonbar contains buttons to add/delete files and start/cancel the upload -->
        <div class="wrapper-buttons">
        <div class="row fileupload-buttonbar">
            <div>
                <!-- The fileinput-button span is used to style the file input field as button -->
                <div class="uploader-button-wrap">
                  <span class="bold-span">Choose photos</span>
                  <span class="btn btn-success fileinput-button uploader-btn-primary tutorial-popover" 
                        data-toggle="popover" data-placement="right" title="Tutorial" data-content="Some description, probably with <em>markdown</em>" data-html="True" data-lesson="1">
                      <i class="glyphicon glyphicon-plus"></i>
                      <span>Select files</span>
                      <input type="file" name="files[]" multiple accept="image/*,video/*,audio/*">
                  </span>
                </div>
                <div class="uploader-button-wrap-sec">
                  <div class="delete-selected-upload btn uploader-btn-primary grey"><span>Delete Selected</span></div>
                  <button type="submit" class="btn btn-primary start uploader-btn-primary tutorial-popover" value="uploader"
                            data-toggle="popover" data-placement="left" title="Tutorial" data-content="Description of this element" data-html="True" data-lesson="3">
                      <span>Upload</span>
                  </button>
<!--                  <button type="reset" class="btn btn-warning cancel">
                      <i class="glyphicon glyphicon-ban-circle"></i>
                      <span>Cancel upload</span>
                  </button>
                  <button type="button" class="btn btn-danger delete-all">
                      <i class="glyphicon glyphicon-trash"></i>
                      <span>Delete</span>
                  </button>
                  <input type="button" value="Update" class="update-all" />
                  <input type="checkbox" class="toggle">-->
                </div>
            </div>

<!--            --><?php //if ($license_list): ?>
<!--              <select id="licence">-->
<!--                --><?php //foreach ($license_list as $license) : ?>
<!--                  <option value="--><?php //print $license->id; ?><!--">--><?php //print $license->title; ?><!--</option>-->
<!--                --><?php //endforeach; ?>
<!--              </select>-->
<!--            --><?php //endif; ?>

            <?php if ($license_list): ?>
              <input id="license_values" name="licenses" type="hidden" value='<?php print $license_list; ?>'>
            <?php endif; ?>

            <!-- The global progress state -->
            <div class="fileupload-progress fade">
                <!-- The global progress bar -->
                <div class="progress progress-striped active" role="progressbar" aria-valuemin="0" aria-valuemax="100">
                    <div class="progress-bar progress-bar-success" style="width:0%;"></div>
                </div>
                <!-- The extended global progress state -->
                <div class="progress-extended">&nbsp;</div>
            </div>

          <!-- The global file processing state -->
          <span class="fileupload-process"></span>

        </div>
        <!-- The table listing the files available for upload/download -->
        
          <table role="presentation" class="table table-striped">
            <thead>
               <tr>
                  <th class="box-dfmp"><input type="checkbox" name="check_all"/></th>
                  <th></th>
                  <th>Title and description</th>
                  <th>Tags</th>
                  <th>License</th>
               </tr>
            </thead>
            <tbody class="files">
            </tbody>
          </table>
        </div>

        <?php print theme('dfmp_file_uploader_files_list', $variables); ?>

    </form>

</div>
<!-- The blueimp Gallery widget -->
<div id="blueimp-gallery" class="blueimp-gallery blueimp-gallery-controls" data-filter=":even">
    <div class="slides"></div>
    <h3 class="title"></h3>
    <a class="prev">‹</a>
    <a class="next">›</a>
    <a class="close">×</a>
    <a class="play-pause"></a>
    <ol class="indicator"></ol>
</div>



<!-- The template to display files available for upload -->
<script id="template-upload" type="text/x-tmpl">
{% for (var i=0, file; file=o.files[i]; i++) { %}
    <tr class="template-upload fade" {% if (file.id) { %}id="{%=file.id%}"{% } %}>
        <td>
            <input type="checkbox" name="delete" value="1" class="toggle">
        </td>
        <td>
            <span class="preview"></span>
            <p class="size">Processing...</p>
        </td>
       <td class="name-wrapper" style="display:none;">
            <p class="name">{%=file.name%}</p>
            <strong class="error text-danger"></strong>
        </td>
        <td>
            <input class="name_resource" type="text" value="{%=file.nameOnly%}">
            <input class="name_extension" type="hidden" value="{%=file.extension%}">
            <input class="description_resource" type="text" placeholder="Add a description">
        </td>
        <td>
            <input class="tags_resource" type="text" placeholder="Separate tags with a comma">
        </td>
        <td class="license-cell">
            <div class="jqxWidget">
        </div>
        </td>
<!--        <td>
            <p class="size">Processing...</p>
            <div class="progress progress-striped active" role="progressbar" aria-valuemin="0" aria-valuemax="100" aria-valuenow="0"><div class="progress-bar progress-bar-success" style="width:0%;"></div></div>
        </td>-->
        <td style="display:none;">
            {% if (!i && !o.options.autoUpload) { %}
                <button class="btn btn-primary start" disabled>
                    <i class="glyphicon glyphicon-upload"></i>
                    <span>Start</span>
                </button>
            {% } %}
            {% if (!i) { %}
                <button class="btn btn-warning cancel">
                    <i class="glyphicon glyphicon-ban-circle"></i>
                    <span>Cancel</span>
                </button>
            {% } %}
        </td>
    </tr>
{% } %}
</script>
<!-- The template to display files available for download -->
<script id="template-download" type="text/x-tmpl">
{% for (var i=0, file; file=o.files[i]; i++) { %}
    <tr class="template-download fade"  id="{%=file.id%}__{%=file.assetID%}">
        <td>
            <span class="preview">
                {% if (file.thumbnailUrl) { %}
                    <a href="{%=file.url%}" title="{%=file.name%}" download="{%=file.name%}" data-gallery><img src="{%=file.thumbnailUrl%}"></a>
                {% } else { %}
                <a href="{%=file.url%}" title="{%=file.name%}" download="{%=file.name%}" data-gallery>
                <video width="80" height="60">
                <source src="{%=file.url%}" type="video/mp4">
                </video>
                </a>
                {% } %}
            </span>
        </td>
        <td>
            <p class="name">
                {% if (file.url) { %}
                    <a href="{%=file.url%}" title="{%=file.name%}" download="{%=file.name%}" {%=file.thumbnailUrl?'data-gallery':''%}>{%=file.name%}</a>
                {% } else { %}
                    <span>{%=file.name%}</span>
                {% } %}
            </p>
            {% if (file.error) { %}
                <div><span class="label label-danger">Error</span> {%=file.error%}</div>
            {% } %}
        </td>
        <td>
            <input class="description_resource" type="text" size="40" value="{%=file.description%}">
        </td>
        <td>
            <input class="tags_resource" type="text" size="40" value="{%=file.tags%}">
        </td>
        <td class="license-cell">
            <div class="jqxWidget">
        </div>
        </td>
        <td>
            <span class="size">{%=o.formatFileSize(file.size)%}</span>
        </td>
        <td>
            {% if (file.deleteUrl) { %}
                <button class="btn btn-danger delete" data-type="{%=file.deleteType%}" data-url="{%=file.deleteUrl%}"{% if (file.deleteWithCredentials) { %} data-xhr-fields='{"withCredentials":true}'{% } %}>
                    <i class="glyphicon glyphicon-trash"></i>
                    <span>Delete</span>
                </button>
                <input type="button" value="Update" class="update-each" />
                <input type="checkbox" name="delete" value="1" class="toggle">
            {% } else { %}
                <button class="btn btn-warning cancel">
                    <i class="glyphicon glyphicon-ban-circle"></i>
                    <span>Cancel</span>
                </button>
            {% } %}
        </td>
    </tr>
{% } %}
</script>

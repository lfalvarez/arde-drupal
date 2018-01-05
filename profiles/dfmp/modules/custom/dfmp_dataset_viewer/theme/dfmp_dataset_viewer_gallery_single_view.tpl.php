<?php
/**
 * @file
 * Asset single view template
 */
?>
<div id="gallery-single-view">
  <div  class="panel-display parrot-panels two-66-33 clearfix" <?php if (!empty($css_id)): print "id=\"$css_id\""; endif; ?>>
    <div id="two-66-33-top-wrapper-single-view" class="fullwidth">
      <div class="container">
        <div class="region two-66-33-top region-conditional-stack">
          <div class="single-image-back">
            <?php print l(t('Back to the album'), $backlink, array('html' => TRUE, 'attributes' => array('class' => array('arrow-btn')))); ?>
          </div>
          <div class="region-inner clearfix">
            <div class="image-center">
              <?php if (dfmp_dataset_viewer_get_mimetype_details($asset) == 'video') : ?>
              <video width="627" height="387" controls>
              <source src="<?php print $asset->url; ?>" type="video/mp4">
              </video>
              <?php elseif (dfmp_dataset_viewer_get_mimetype_details($asset) == 'image') : ?>
              <a rel="gallery" class="fancybox_gallery" data-fancybox-href="<?php print $asset->url; ?>">
                <?php if (isset($asset->metadata->resized_s3_hash)) : ?>
                  <img src="<?php print $asset->path;?>" alt="<?php print isset($asset->metadata->text) ? check_plain($asset->metadata->text) : '' ?>"/>
                <?php else : ?>
                  <?php print theme($asset->source, array(
                  'path' => $asset->path,
                  'style_name' => 'asset',
                  'alt' => isset($asset->metadata->text) ? check_plain($asset->metadata->text) : '',
                  )); ?>
                <?php endif; ?>
                </a>
              <?php endif; ?>
            </div>
          </div>
        </div>
      </div>
    </div>
    <div id="two-66-33-middle-wrapper-single-view" class="fullwidth">
      <div class="container">
        <div class="region two-66-33-first">
          <div class="region-inner clearfix">
            <?php if (isset($asset->organization) && $asset->organization->name == 'twitter'):?>
              <h1><?php print l(t('!name', array('!name' => isset($asset->metadata->user->screen_name) ?  '@'. $asset->metadata->user->screen_name : '')), TWITTER_URL . $asset->metadata->user->screen_name, array('external' => TRUE, 'attributes' => array('target' => '_blank'))); ?></h1>
              <?php else:?>
              <h1><?php print t('!name', array('!name' => isset($asset->name) ? $asset->name : '')); ?></h1>
            <?php endif;?>
            <p class="gallery-description"> <?php print t('!desc', array('!desc' => isset($asset->metadata->text) ? $asset->metadata->text : '')); ?></p>
            <div class="gallery-license">
              <h4><?php print t('License:') ?></h4>
              <p> <?php print t('!type', array('!type' => isset($asset->metadata->license_name) ? $asset->metadata->license_name : t('License Not Specified'))); ?></p>
            </div>
            <div class="gallery-tags">
              <h4><?php print t('Tags:') ?></h4>
              <p> <?php print $tags; ?></p>
            </div>
          </div>
          <?php if (user_is_logged_in()) : ?>
            <button value="<?php print $dataset_id . '__' . $asset->assetID; ?>" class="flag-asset" value="<?php print t('Flag resource'); ?>"><?php print t('Flag resource'); ?></button>
            <div id="dialog-form" title="<?php print t('Flag resource'); ?>">
              <p class="validateTips"><?php print t('Please enter reason why are you going to flag this asset:'); ?></p>
              <form>
                  <textarea  rows="4" name="reason" id="reason-msg" value="" class="text ui-widget-content ui-corner-all"></textarea>
                  <input type="submit" tabindex="-1" style="position:absolute; top:-1000px">
              </form>
            </div>
          <?php endif; ?>
        </div>
        <div class="region two-66-33-second">
          <div class="region-inner clearfix">
            <?php print l(t('Download image'), 'dfmp/download/' . base64_encode($asset->url), array('html' => TRUE, 'attributes' => array('class' => array('btn-blue', 'download-btn'), 'download' => 'download'))); ?>
            <?php if (isset($asset->metadata->post_url) && $asset->metadata->post_url) : ?>
              <div class="post-btn-separate"></div>
              <?php print l(t('See original post'), $asset->metadata->post_url, array('html' => TRUE, 'attributes' => array('target'=>'_blank', 'class' => array('btn-blue', 'see-original-post', 'organization-one-picture')))); ?>
            <?php endif; ?>
            <hr>
            <h4 class="gallery-organization-title"><?php print t('Collection title') ?></h4>
            <?php print l( $group_name->title , "/gallery/view/". $group_url, array('html' => TRUE, 'attributes' => array('target'=>'_blank', 'class' => array('btn-blue', 'see-original-post', 'organization-double-picture')))); ?> 
          </div>
        </div>
      </div>
    </div>
  </div>
</div>

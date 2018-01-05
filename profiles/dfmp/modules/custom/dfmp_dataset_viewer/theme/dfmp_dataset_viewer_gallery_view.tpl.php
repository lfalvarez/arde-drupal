<?php
/**
 * @file
 * Gallery view template
 */
?>
<div id="viewer-gallery-view">
  <div id="gallery-top">
    <div class="title-desc">
      <h1><?php print t('!title', array('!title' => isset($assets->title) ? $assets->title : '')); ?></h1>
      <p><?php print t('!desc', array('!desc' => isset($assets->description) ? $assets->description : '')); ?></p>
    </div>
    <div class="count-info">

      <div id="more-info-section">
        <div class="gradient-border-wrapper">
          <p class="more-info-button" onclick="morebtn()"><?php print t('More info'); ?></p>
        </div>
        <div class="hidden-info">
          <?php if (isset($assets->organization)): ?>
            <img src="<?php print ($assets->organization->image_full_path); ?>">
            <div class="dataset-info">
              <h4 class="gallery-organization"><?php print t('Organization:') ?></h4>
              <p> <?php print t('!title', array('!title' => isset($assets->organization->title) ? $assets->organization->title : '')); ?></p>
              <h4 class="gallery-assets"><?php print t('Assets:') ?></h4>
              <p> <?php print t('!assets', array('!assets' => isset($assets->organization->dfmp_assets) ? $assets->organization->dfmp_assets : '')); ?></p>
              <p class="gallery-dataset"> <?php print l(t('View dataset in DFMP'), $assets->organization->dfmp_link); ?>
            </div>
<!--            <div class="dfmp-devider"></div>-->
<!--            <div class="dfmp-gallery-rights"></div>-->
          <?php endif; ?>
        </div>
      </div>
    </div>
  </div>
  <div class="dfmp-devider"></div>
  <div class="dfmp-gallery-top-second">
    <ul class="dfmp-gallery-top-second-list">
      <li class="collection-images-count">
        <div class="count-images"><?php print t('!count images', array('!count' => isset($assets->count) ? $assets->count : '')); ?></div>
      </li>
      <li class="collection-offset">
        <div class="gallery-offset"><?php print t('Displaying !FROM - !TO', array('!FROM' => count($gallery) > 0 ? $offset + 1 : $offset, '!TO' => $offset + count($gallery))); ?></div>
      </li>
      <li class="dfmp-refine-search-btn">
          <a href="#" class="dfmp-pink-btn"><?php print t('Refine'); ?></a>
      </li>
    </ul>
  </div>
  <div class="download-collection">
    <div class="dwn-inner-btn">
      <a href="#" title="<?php print $dwn_btn_msg; ?>" class="btn-blue dwn-btn-wide dwn-expend-box <?php if ($count_local_files <= 0): ?>disabled_download <?php endif; ?>"><?php print t("Download displayed images"); ?></a>
    </div>
  </div>
  <div id="popups-below" class="clearfix"></div>
  <?php if ($count_local_files > 0): ?>
    <div class="download-collection-box" style="display:none">
      <div class="dwn-box-header">
        <h3><?php print t("Download !total images", array('!total' => $count_local_files)); ?></h3>
      </div>
      <div class="dwn-box-content">
        <div class="dwn-box-notification">
          <p>
            <?php print t('You have selected to download images !total. These images may have one or more license types or their rights may be reserved. Prior to downloading this collection, please view each individual image to understand its designed license.', array('!total' => '<b>' . $count_local_files . ' images</b>')); ?>
          </p>
          <p>
            <i><b><?php print t('Note') . ":"; ?></b>
            <?php print t('Images with Twitter and Flickr licenses cannot be downloaded.'); ?></i>
          </p>
        </div>
        <div class="dfmp-devider"></div>
        <div class="dwn-box-btns">
          <div class="dwn-box-download-button">
            <?php print render($dwn_form); ?>
          </div>
          <div class="dwn-box-cancel-button">
            <a href="#" class="dfmp-metal-btn dwn-expend-box"><?php print t("Cancel"); ?></a>
          </div>
          <div class="clearfix"></div>
        </div>
      </div>
    </div>
  <?php endif; ?>
  <div class="dfmp-serach-form" style="<?php print !empty($item_count) ? 'display:none;' : ''; ?>">
    <?php print render($form);?>
  </div>
  <div class="gallery-holder" id="assetimimage" data-page="0" data-maxpage="<?php print $pages; ?>">
    <?php foreach ($gallery as $item) : ?>
      <?php print $item; ?>
    <?php endforeach; ?>
    <div class="dfmp-loader"></div>
  </div><!--#assetimimage-->
</div>
<!--<div id="assetimimage" class="gallery-holder">-->

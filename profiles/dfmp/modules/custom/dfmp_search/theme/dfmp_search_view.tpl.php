<div id="viewer-gallery-view">
  <div class="assetimimage browse-main-wrapper">
    <div id="gallery-top">
      <div class="title-desc">
        <h1 class="uppercase"><?php print t('Search results'); ?></h1>
      </div>
    </div>
    <div class="dfmp-devider"></div>
    <div class="dfmp-gallery-top-second">
      <ul class="dfmp-gallery-top-second-list">
        <li class="collection-images-count">
          <?php if (!empty($_GET['search_title']) && !is_null($item_count)) : ?>
            <?php print t('Search returned <span class="total">!total</span> results for "@NAME".', array('!total' => $item_count, '@NAME' => $_GET['search_title'])); ?>
          <?php elseif (empty($_GET['search_title']) && !is_null($item_count)) : ?>
            <?php print t('Search returned <span class="total">!total</span> results.', array('!total' => $item_count)); ?>
          <?php endif; ?>
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
    </div>
  </div><!--#assetimimage-->
  <div class="dfmp-loader" style="display: none;"></div>
</div><!--assetimimage-wrapper-->

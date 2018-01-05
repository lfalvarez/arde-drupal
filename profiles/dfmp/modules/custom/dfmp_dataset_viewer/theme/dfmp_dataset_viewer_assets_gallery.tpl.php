<?php
/**
 * @file
 * Assets gallery view template
 */
?>
<div class="assetimimage-wrapper">
  <div id="assetimimage" class="assetimimage browse-main-wrapper" data-nooffset=1 data-page=0 data-maxpage=<?php echo ceil($count/GALLERY_IMAGES_LIMIT) ?>>
    <h1><?php print t('Browse')?></h1>
    <?php foreach($gallery as $image) print $image; ?>

  </div>
  <div class="dfmp-loader"></div>
</div>
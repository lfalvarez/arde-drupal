<?php
/**
 * @file
 * Dataset not found block
 */
?>
<div id="images-not-found">
  <h2> <img src="/<?php print drupal_get_path('theme', 'dfmp'); ?>/img/not_found_attention.png"> <?php print t('!errormessage', array('!errormessage' => $errormessage)); ?></h2>
</div>
<div id="viewer-gallery-view" class="clearfix">
	<div class="dfmp-no-results-form">
		<?php print $form; ?>
	</div>
</div>
<div class="assetimimage-wrapper">
  <div id="assetimimage" class="assetimimage browse-main-wrapper" data-nooffset=1 data-page=0>
    <h1 class="uppercase"><?php print t('Popular datasets')?></h1>
    <?php foreach($gallery as $image) print $image; ?>
  </div>
</div>


<?php
/**
 * @file
 * Asset list template
 */
?>
<?php if ($item->source && $item->path) : ?>
  <article class="gallery-item view-gallery-<?php echo $item->cclass; ?>-item">
    <?php if (dfmp_dataset_viewer_get_mimetype_details($item) == 'video') : ?>
      <video width="358" height="220" controls>
        <source src="<?php print $item->url; ?>" type="video/mp4">
      </video>
    <?php elseif (dfmp_dataset_viewer_get_mimetype_details($item) == 'image') : ?>
      <a rel="gallery" class="fancybox_gallery" href="<?php print url('gallery/item/' . $dataset_id . '/' . $item->assetID); ?>" data-fancybox-href="<?php print $item->url; ?>">
        <?php if (isset($item->metadata->resized_s3_hash)) : ?>
          <img data-original="<?php print $item->metadata->thumb;?>" alt="<?php print isset($item->metadata->text) ? check_plain($item->metadata->text) : '' ?>"/>
        <?php else : ?>
          <?php print theme($item->source, array(
          'path' => $item->path,
          'style_name' => '300x300crop',
          'alt' => isset($item->metadata->text) ? check_plain($item->metadata->text) : '',
          )); ?>
        <?php endif; ?>
      </a>
    <?php endif; ?>

    <div>
      <p class="image-name"><?php print t('!name', array('!name' => isset($item->name) ? $item->name : '')); ?></p>
    </div>
  </article>
<?php endif; ?>

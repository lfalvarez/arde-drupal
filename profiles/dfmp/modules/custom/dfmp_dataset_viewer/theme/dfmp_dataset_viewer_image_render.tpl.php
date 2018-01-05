<?php
/**
 * @file
 * Image item template
 */
?>
<?php if ($source && $path) : ?>
  <a href="<?php print url('gallery/view/' . $item->asset->id); ?>">
    <div class='gallery-item gallery-item-browse gallery-<?php print $class; ?>-item'>
      <div class="gallery-item-inner">
        <div class="dataset-name-left-corner">
          <?php print t($item->title); ?>
        </div>
        <div class="dataset-count-right-corner">
          <?php print $item->dfmp_total . ' images'; ?>
        </div>
        <?php print theme($source, array(
          'path' => $path,
          'style_name' => '300x300crop',
          'alt' => isset($item->name) ? $item->name : '',
        ));
        ?>
      </div>
    </div>
  </a>
<?php endif; ?>

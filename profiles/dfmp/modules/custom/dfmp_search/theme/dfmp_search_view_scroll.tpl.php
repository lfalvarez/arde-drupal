
  <?php foreach ($gallery as $item) : ?>
    <?php if ($item->url && @fopen($item->url, 'r')) : ?>
      <article class="gallery-item">
        <div class="head">
              <span class="meta">
                  <strong class="posted"><a href="<?php print url('gallery/item/' . $dataset_id . '/' . $item->_id); ?>"><?php print t('Posted'); ?></a></strong>
                  <em class="date"><?php print date('d/m/Y', strtotime($item->lastModified)); ?></em>
              </span>
        </div>
        <?php if (@strpos($item->metadata->mimetype, 'video') !== FALSE || @strpos($item->metadata->type, 'video') !== FALSE) : ?>
          <video width="358" height="220"  controls>
            <source src="<?php print $item->url;?>" type="video/mp4">
          </video>
        <?php elseif (@strpos($item->metadata->mimetype, 'image') !== FALSE || @strpos($item->metadata->type, 'image') !== FALSE) : ?>
          <a rel="gallery" class="fancybox_gallery" data-fancybox-href="<?php print $item->url; ?>">
            <?php print theme('imagecache_external', array(
              'path' => $item->url,
              'style_name' => 'gallery',
              'alt' => isset($item->metadata->text) ? $item->metadata->text : '',
            )) ?>
          </a>
        <?php endif; ?>
      </article>
     <?php elseif ($item->url && file_exists(urldecode(DRUPAL_ROOT . $item->url))) : ?>
      <article class="gallery-item">
        <div class="head">
              <span class="meta">
                  <strong class="posted"><a href="<?php print url('gallery/item/' . $dataset_id . '/' . $item->_id); ?>"><?php print t('Posted'); ?></a></strong>
                  <em class="date"><?php print date('d/m/Y', strtotime($item->lastModified)); ?></em>
              </span>
        </div>
      <?php if (@strpos($item->metadata->mimetype, 'video') !== FALSE || @strpos($item->metadata->type, 'video') !== FALSE) : ?>
          <video width="358" height="220"  controls>
            <source src="<?php print $item->url;?>" type="video/mp4">
          </video>
      <?php elseif (@strpos($item->metadata->mimetype, 'image') !== FALSE || @strpos($item->metadata->type, 'image') !== FALSE): ?>
          <a rel="gallery" class="fancybox_gallery" data-fancybox-href="<?php print $item->url; ?>">
            <?php print theme('image_style', array(
              'path' => str_replace('/sites/default/files', 'public://', urldecode($item->url)),
              'style_name'=> 'gallery',
              'alt' => isset($item->metadata->text) ? $item->metadata->text : '',
            ))?>
          </a>
        <?php endif; ?>
      </article>
    <?php endif; ?>
  <?php endforeach; ?>
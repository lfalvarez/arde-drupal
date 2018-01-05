<?php
/**
 * @file
 * File uploader list template file
 */
?>
<div id="my-files-list-wrapper">
  <div class="border-uploader">
    <h1>My images and videos</h1>
  </div>
  <table class="my-videos">
    <thead>
      <tr class="sort-direction-<?php print strtolower($sortHow); ?>">
        <th class="box-dfmp"><input type="checkbox" name="check_all"/></th>
        <th></th>
        <th <?php if ($orderBy == "name") :?> class="current_sort" <?php endif; ?>><a class="sort-ajax" href="<?php print url('dfmp/file_uploader', array('query' => $get)) . $query_sort_path; ?>direction=<?php print $sortHow; ?>&order=name">Title and description</a></th>
        <th>Tags</th>
        <th>License</th>
        <th <?php if ($orderBy == "lastModified") :?> class="current_sort" <?php endif; ?>><a class="sort-ajax" href="<?php print url('dfmp/file_uploader', array('query' => $get)) . $query_sort_path; ?>direction=<?php print $sortHow; ?>&order=lastModified">Modified</a></th>
      </tr>
    </thead>
    <tbody>
      <?php if (!empty($resources_user)): ?>
        <?php foreach ($resources_user as $resource) : ?>
          <tr id="<?php print $resource->id . '__' . $resource->assetID; ?>">
            <td>
              <input type="checkbox" name="delete" value="1" class="toggle">
              <input type="hidden" name="updated" value="">
            </td>
            <td id="without-padding">
              <?php if (strpos($resource->type, 'image') === 0) : ?>
                <div class="loader">in progress</div>
                <a href="<?php print $resource->assetID; ?>" class="dfmp_rotate_unclock">Rotate</a>
                <a href="<?php print $resource->url; ?>" title="<?php print $resource->name; ?>" download="<?php print $resource->name; ?>" data-gallery>
                  <img id="<?php print $resource->assetID; ?>" src="<?php print ($resource->thumbnailUrl ? $resource->thumbnailUrl : $resource->url) . '?' . time(); ?>"></a>
                <a href="<?php print $resource->assetID; ?>" class="dfmp_rotate">Rotate</a>

              <?php else : ?>
                <a href="<?php print $resource->url; ?>" title="<?php print $resource->name; ?>" download="<?php print $resource->name; ?>" data-gallery></a>
                <video width="80" height="60">
                  <source src="<?php print $resource->url; ?>" type="video/mp4">
                </video>
              <?php endif; ?>
            </td>
            <td>
              <span class="asset-title"><?php print $resource->name; ?></span>
              <span class="asset-description"><?php print empty($resource->description) ? 'Add a description...' : $resource->description; ?></span>
            </td>
            <td><span class="asset-tags"><?php print empty($resource->tags) ? 'Add tags...' : $resource->tags; ?></span></td>
            <td class="license-cell">
              <input class="license_initial" type="hidden" value="<?php print $resource->license; ?>">
              <div class="jqxWidget"></div>
            </td>
            <td><?php print date('j M Y', strtotime($resource->dateCreated)); ?></td>
          </tr>
        <?php endforeach; ?>
      <?php endif; ?>
    </tbody>
  </table>
  <div id="file-uploader-pager"><?php print !empty($pager) ? $pager : ''; ?></div>
  <div class="clearfix"></div>
  <div class="uploader-button-wrap-bottom">
    <button type="button" class="delete-all btn uploader-btn-primary grey"><span><?php print t('Delete Selected'); ?></span></button>
    <?php if (isset($user_own_gallery_id)): ?>
    <a href="/gallery/view/<?php print $user_own_gallery_id; ?>" class="btn uploader-btn-primary uploader-gallery-btn"><span><?php print t('View in Gallery'); ?></span></a >
    <?php endif; ?>
    <button type="button" class="update-all btn uploader-btn-primary tutorial-popover" data-toggle="popover" data-placement="left" title="Tutorial" data-content="Even more information.."
     data-html="True" data-lesson="2" ><span><?php print t('Save Changes'); ?></span></button>
  </div>
  <?php if (isset($max_pages) && $max_pages > 1) : ?>
<!--     <div class="uploader-go-to-wrap">
      <span>To page</span>
      <input type="text" name="go_to_page">
      <div class="go-to-page"><a href="#"><span><?php print t('Go'); ?></span></a></div>
    </div> -->
  <?php endif; ?>
</div>

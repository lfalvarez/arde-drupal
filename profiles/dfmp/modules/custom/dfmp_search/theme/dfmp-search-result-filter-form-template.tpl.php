<div class="header-gradient-border"></div>

<div class="search-filters-wrapper">
  <div class="search-filters-holder">
    <div class="width-100">
      <div class="width-50 float-left">
        <div class="form-item-inline"><?php print drupal_render($form['title']); ?></div>
        <div class="search-include-description"><?php print drupal_render($form['include_description']); ?></div>
        <div class="form-item-inline"><?php print drupal_render($form['search_type_media']); ?></div>
        <div class="form-item-inline"><?php print drupal_render($form['search_licence']); ?></div>
      </div>
      <div class="width-50 float-right">
        <div class="search-tags-wrap clearfix">
          <label for="edit-search-tags">Tags</label>
          <div class="tag-plus-ico"><a href="#">+&nbsp;&nbsp;&nbsp;<?php print t('Add tag'); ?></a></div>
          <?php print drupal_render($form['search_tags']); ?>
          </div>
          <div class="tags-list">
            <ul></ul>
          </div>
          <div class="element-hidden"><?php print drupal_render($form['search_tags_hidden']); ?></div>
      </div>

    </div>
    <div class="clearfix"></div>
  </div>
  <div class="search-filters-separate">
    <div></div>
  </div>
  <div class="search-filters-submit">
    <?php print drupal_render($form['submit']); ?>
    <div class="clearfix"></div>
  </div>
  <div class="search-clear-button">
    <?php print drupal_render($form['search_clear_link']); ?>
  </div>
</div>
<div class="element-hidden"><?php print drupal_render_children($form); ?></div>

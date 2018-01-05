<div class="search-input-block">
	<?php print drupal_render($form['search_title']); ?>
</div>
<div class="search-fields-block">
	<div class="markups_fields first_field">
		<?php print drupal_render($form['search_markup']); ?>
		<?php print drupal_render($form['search_type']); ?>
	</div>
	<div class="markups_fields">
		<?php print drupal_render($form['search_markup_licence']); ?>
		<?php print drupal_render($form['search_licence']); ?>
	</div>
	<div class="clearfix"></div>
</div>
<?php print drupal_render($form['submit']); ?>
<div class="element-hidden"><?php print drupal_render_children($form); ?></div>
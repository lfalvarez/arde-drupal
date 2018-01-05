<div id="group-datasets-collection" class="clearfix">
<div id="groups-collection">
	<?php foreach($groups as $key => $group) : ?>
		<div class="<?php if(($key + 1) % 4 == 0) : ?> last <?php endif; ?> group-item">
			<a href="/browse/group/<?php print $group->name; ?>">
				<?php print $group->rendered_image; ?>
			</a>
			<div class="group-title-link">
				<a href="/browse/group/<?php print $group->name; ?>">
					<?php print $group->title; ?>
				</a>
			</div>
			<div class="dataset-count-right-corner">
				<?php print $group->packages . ' ' . t('Datasets'); ?>
			</div>
		</div>
	<?php endforeach; ?>
</div>
</div>

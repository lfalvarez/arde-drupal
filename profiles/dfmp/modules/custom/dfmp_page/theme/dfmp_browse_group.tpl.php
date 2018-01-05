
<div id="group-datasets-collection">
	<div id="groups-datasets" class="browse-group-collection">
	    <h1><?php print '<span class="os-semibold">' . t('BROWSE') . '</span> <span class="os-light">' . t('!title', array('!title' => $group_title)) . '</span>'; ?></h1>
		<?php if ($no_datasets) : ?>
			<div class="msg-no-datasets">
				<?php print $msg; ?>
			</div>
		<?php else: ?>
			<?php foreach($members_list as $key => $member) : ?>
				<div class="<?php if(($key + 1) % 4 == 0) : ?> last <?php endif; ?> group-item">
					<a href="<?php print url('gallery/view/' . $member->asset_id); ?>">
						<?php print $member->rendered_image; ?>
					</a>
					<div class="group-title-link">
						<!--<a href="/browse/group/<?php /*print $member->name; */?>">-->
						<a href="<?php print url('gallery/view/' . $member->asset_id); ?>">
							<?php print $member->title; ?>
						</a>
					</div>
					<div class="dataset-count-right-corner">
						<?php print $member->count . ' ' . t('Images'); ?>
					</div>
				</div>
			<?php endforeach; ?>
		<?php endif; ?>
	</div>
</div>


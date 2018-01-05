<?php
/**
 * @file
 * Image item template
 */
?>
<?php if ($source && $path) : ?>
	<?php print theme($source, array(
	  'path' => $path,
	  'style_name' => '300x300crop',
	  'alt' => isset($item->name) ? $item->name : '',
	));
	?>
<?php else : ?>
	<img src="<?php print '/' . $placeholder_path; ?>" alt="<?php print isset($item->name) ? $item->name : ''; ?>"/>
<?php endif; ?>
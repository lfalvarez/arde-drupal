<?php
/**
 * @file
 * Asset details template
 */

if (isset($image) && $image) {
  print $image;
} 
elseif ($asset->mimetype == 'photo'){
  print "<img src='{$asset->url}'>";
}
?>

<!--video-->
<?php if(__dfmp_dataset_viewer_mime_type($asset->mimetype)):?>
  <?php $url = preg_replace('#^https?://#', '', $asset->url);?>
  <video width="500" height="300"  controls>
    <source src="/<?php print $url;?>" type="video/mp4">
  </video>
<?php endif;?>

<table>
  <tbody>
    <tr>
      <td><?php print t('Name'); ?></td>
      <td><?php print $asset->name; ?></td>
    </tr>
    <tr>
      <td><?php print t('License'); ?></td>
      <td><?php print isset($asset->license_name) ? $asset->license_name : ''; ?></td>
    </tr>
    <tr>
      <td><?php print t('Size'); ?></td>
      <td><?php print $asset->size; ?></td>
    </tr>
    <tr>
      <td><?php print t('Type'); ?></td>
      <td><?php print $asset->mimetype; ?></td>
    </tr>
    <tr>
      <td><?php print t('Location'); ?></td>
      <td><?php print isset($asset->spatial->lat) && $asset->spatial->lat && isset($asset->spatial->lng) && $asset->spatial->lng ? __dfmp_dataset_viewer_location_coordinates_format ($asset->spatial->lat, $asset->spatial->lng) : t('Not available'); ?></td>
    </tr>
  </tbody>
</table>


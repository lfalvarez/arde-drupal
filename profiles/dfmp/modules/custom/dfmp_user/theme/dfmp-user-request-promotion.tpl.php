<?php
/**
 * @file
 * Request promotion template
 */
?>
<?php foreach($territory as $row):?>
  <?php if (isset($row->link)) : ?>
      <?php print $row->link?>
  <?php endif; ?>
<?php endforeach;?>
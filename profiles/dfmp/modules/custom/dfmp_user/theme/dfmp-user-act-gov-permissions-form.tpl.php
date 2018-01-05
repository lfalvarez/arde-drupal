<h1><?php print t('Permissions'); ?></h1>
<p><?php print t('As you have registered with an @act.gov.au email address wou can immediately turn on access to restricted ACT Government datasets and resources in the DFMP.'); ?></p>
<p><?php print t('If you don\'t want access to non-public assets or want to see what general public users can see then you can leave or turn your access to restricted datasets off.'); ?></p>
<h4><?php print t('Access ACT Government restricted assets'); ?></h4>
<?php print drupal_render($form['act_request']); ?>
<?php print drupal_render_children($form); ?>

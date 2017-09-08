<?php
/**
 * @file
 * cu_hours_block.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cu_hours_block_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_display|bean|hours|form';
  $field_group->group_name = 'group_display';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'hours';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Display Options',
    'weight' => '2',
    'children' => array(
      0 => 'field_hours_display',
      1 => 'field_hours_expand_first',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-display field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_display|bean|hours|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Display Options');

  return $field_groups;
}

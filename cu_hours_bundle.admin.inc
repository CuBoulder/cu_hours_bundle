<?php

/**
 * Form for adding / editing a video entity.
 */
function cu_hours_bundle_edit_form($form, &$form_state, $hours = NULL) {
  $days = array(
    'sunday' => 'Sunday',
    'monday' => 'Monday',
    'tuesday' => 'Tuesday',
    'wednesday' => 'Wednesday',
    'thursday' => 'Thursday',
    'friday' => 'Friday',
    'saturday' => 'Saturday',
  );

  $default_values = array(
    'id' => '',
    'title' => '',
    'sunday' => '',
    'monday' => '',
    'tuesday' => '',
    'wednesday' => '',
    'thursday' => '',
    'friday' => '',
    'saturday' => '',
  );
  foreach ($days as $day => $value) {
    $default_values[$day] = array(
      'title' => '',
      'label' => '',
      'content' => '',
    );
    //$default_values[$day . '_custom_label'] = '';
  }
  if ($hours) {
    foreach ($hours as $key => $value) {
      if (array_key_exists($key, $days)) {
        $value = unserialize($value);
      }
      $default_values[$key] = $value;
    }
    $form['id'] = array(
      '#type' => 'hidden',
      '#value' => $hours->id,
    );
  }
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => 'Name/Label',
    '#required' => TRUE,
    '#default_value' => $default_values['title'],
  );
  $form['hours'] = array(
    '#type' => 'fieldset',
    '#title' => t('Hours'),
  );
  foreach ($days as $key =>  $day) {
    $form['hours']['fieldset_' . $key] = array(
      '#type' => 'fieldset',
      '#title' => $day,
    );

    $form['hours']['fieldset_' . $key][$key . '_custom_label'] = array(
      '#type' => 'textfield',
      '#title' => 'Custom Label',
      '#default_value' => $default_values[$key]['label'],
    );

    $form['hours']['fieldset_' . $key][$key] = array(
      '#type' => 'textarea',
      '#title' => 'Content',
      '#rows' => 2,
      '#default_value' => $default_values[$key]['content'],
    );

  }


  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Save Hours'),
    ),
  );
  $form['actions']['cancel'] = array(
    '#type'   => 'submit',
    '#value'  => t('Cancel'),
    '#submit' => array('trackingpixel_form_cancel'),
    '#limit_validation_errors' => array(),
  );
  if ($hours && empty($hours->is_new)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#submit' => array('cu_hours_bundle_delete_submit'),
      '#value' => t('Delete'),
    );
  }

  return $form;
}

function trackingpixel_form_cancel() {
  drupal_goto('admin/content/hours');
}

function cu_hours_bundle_delete_submit($form, &$form_state) {
  $id = $form['#entity']->id;
  $form_state['redirect'] = array('admin/content/hours/' . $id . '/delete');
}

/**
 * Submit handler for video entity form.
 */
function cu_hours_bundle_edit_form_submit($form, &$form_state) {
  $days = array(
    'sunday' => 'Sunday',
    'monday' => 'Monday',
    'tuesday' => 'Tuesday',
    'wednesday' => 'Wednesday',
    'thursday' => 'Thursday',
    'friday' => 'Friday',
    'saturday' => 'Saturday',
  );
  // Values saved to tracking_pixel table
  $values = array();
  $values['title'] = $form_state['values']['title'];
  foreach ($days as $key => $day) {
    $save = array();
    $save['content'] = $form_state['values'][$key];
    $save['label'] = $form_state['values'][$key . '_custom_label'];
    $values[$key] = serialize($save);
  }
  // See if the entity exists
  if (isset($form_state['values']['id']) && $hours = entity_load_single('hours', $form_state['values']['id'])) {
    // Entity exists, add values just in case they have changed
    foreach ($values as $key => $value) {
      $hours->$key = $value;
    }
  }
  else {
    // create new entity with values
    $hours = entity_create('hours', $values);
  }

  // Save entity and return to overview
  $hours->save();
  drupal_goto('admin/content/hours');
}

function cu_hours_bundle_view_display() {
  $output = array();

  return $output;
}

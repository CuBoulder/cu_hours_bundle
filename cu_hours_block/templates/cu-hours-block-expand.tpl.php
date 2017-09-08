<?php
  $labels = cu_hours_block_days();
  $expand_first = $configs['expand_first'] ? 'expand-first' : '';
?>
<div class="hours-block-wrapper hours-expand-wrapper <?php print $expand_first; ?>">
  <ul>
    <?php foreach($vars as $hours): ?>
      <li class="hours-instance-wrapper">
        <a href="#" class="hours-expand-link"><?php print $hours['meta']['title']; ?></a>
        <ul class="hours-days">
          <?php foreach($hours['days'] as $day => $value): ?>
            <?php if (!empty($value)): ?>
              <li class="hours-day-wrapper">
                <div class="hours-day-content">
                  <span class="day">
                    <?php
                      if (!empty($hours['labels'][$day])) {
                        print $hours['labels'][$day];
                      }
                      else {
                        print $labels[$day]['long'];
                      }
                    ?>
                  </span> <span class="hours"><?php print $value; ?></span>
                </div>
              </li>
            <?php endif; ?>
          <?php endforeach; ?>
        </ul>
      </li>
    <?php endforeach; ?>
  </ul>
  <?php if (!empty($description)): ?>
    <div class="hours-description">
      <?php print $description['safe_value']; ?>
    </div>
  <?php endif; ?>
</div>

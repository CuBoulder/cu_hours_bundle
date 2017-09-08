<?php
  $labels = cu_hours_block_days();
?>
<div class="hours-block-wrapper">
  <table class="hours-table">
    <tr class="days">
      <td></td>
      <?php
      $first = current($vars);
      foreach($days as $day => $value): ?>
        <?php if ($value): ?>
        <th scope="col">
          <span class="hours-day-long" aria-hidden="true">
            <?php
              if (!empty($first['labels'][$day])) {
                print $first['labels'][$day];
              }
              else {
                print $labels[$day]['long'];
              }
            ?>
          </span>
        </th>
      <?php endif; ?>
      <?php endforeach; ?>
    </tr>
    <?php
      $count = 0;
    ?>
    <?php foreach($vars as $hours): ?>
      <?php
        $count++;
      ?>
      <tr class="hours-row" id="hours-row-<?php print $count; ?>">
        <th scope="row" >
          <span class="hours-title-link"><a href="#" data-hours-row="<?php print $count; ?>"><?php print $hours['meta']['title']; ?></a></span>
          <span class="hours-title"><?php print $hours['meta']['title']; ?></span>
        </th>
        <?php foreach ($days as $day => $value): ?>
          <?php if (!empty($value)): ?>
          <td>
            <span class="day-label">
              <?php print $labels[$day]['long']; ?>
            </span>
            <span class="day-hours"><?php print $hours['days'][$day]; ?></span>
          </td>
        <?php endif; ?>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </table>
  <?php if (!empty($description)): ?>
    <div class="hours-description">
      <?php print $description['safe_value']; ?>
    </div>
  <?php endif; ?>
</div>

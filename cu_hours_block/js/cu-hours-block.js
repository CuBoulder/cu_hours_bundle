(function( $ ){
  jQuery(document).ready(function($){

    hoursTableResponsive();

    // https://www.w3.org/WAI/GL/wiki/Using_aria-expanded_to_indicate_the_state_of_a_collapsible_element

    // Add closed and aria expanded attributes to links.
    $('a.hours-expand-link').addClass('closed').attr('aria-expanded', 'false');
    // If first hours set is set to display, show it.

    // Toggle expand classes, update aria-expanded to true.
    $('.hours-expand-wrapper.expand-first').each(function(){
      $('.hours-instance-wrapper:first ul.hours-days', this).show();
      $('.hours-instance-wrapper:first a.hours-expand-link', this).toggleClass('closed').toggleClass('expanded').attr('aria-expanded', 'true');

      // Check to see if only one hours instance exists
      var hoursInstances = $('.hours-instance-wrapper', this).length;
      if (hoursInstances == 1) {
        $('a.hours-expand-link', this).contents().unwrap().wrap('<span class="hours-instance-title"></span>');
      }
    });

    // Click to expand functions.
    $('a.hours-expand-link').click(
      function(event) {
        event.preventDefault();
        var t = $(this).next('ul');
        $(t).slideToggle();
        $(this).toggleClass('closed').toggleClass('expanded');
        if ($(this).attr('aria-expanded') == 'true') {
          $(this).attr('aria-expanded', 'false');
        } else {
          $(this).attr('aria-expanded', 'true');
        }
        return false;
      }
    );
  });

  function hoursTableResponsive() {
    $('table.hours-table').each(function(){
      if ($('tbody', this).width() > $(this).width()) {
        $(this).removeClass('hours-table').addClass('hours-table-min');
      }
      else {
        $(this).removeClass('hours-table-min').addClass('hours-table');
      }
    });
  }
})( jQuery );

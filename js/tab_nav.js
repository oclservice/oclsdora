/**
 * @file
 * Adds Next/Previous functionality.
 */

(function ($, Drupal, window, document, undefined) {

Drupal.behaviors.islandora_guided_ingest = {
  attach: function (context, settings) {
    $(window).load(function () {
      $('.islandora-guided-ingest-next').click(function (e) {
        e.preventDefault();
        $('.vertical-tabs-list').find('li.selected').next().find('a').trigger('click');
      });

      $('.islandora-guided-ingest-prev').click(function (e) {
        e.preventDefault();
        $('.vertical-tabs-list').find('li.selected').prev().find('a').trigger('click');
      });
    });
  }
};

})(jQuery, Drupal, this, this.document);

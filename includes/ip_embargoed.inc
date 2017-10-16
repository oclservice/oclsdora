<?php

/**
 * @file
 * Serves a callback to determine whether something is IP-embargoed.
 */

/**
 * Outputs whether an object is embargoed, in XML for XSL-parsing convenience.
 *
 * XML output is encased in an "embargo_info" root node, containing an
 * "embargo_status" element that contains "true" if the object is embargoed, and
 * "false" if the PID was not in the embargo table. No assertion is made as to
 * whether the object exists in Fedora.
 *
 * @param string $pid
 *   The PID of the object to check.
 */
function oclsdora_ip_embargoed_callback($pid) {
  module_load_include('inc', 'islandora_ip_embargo', 'includes/utilities');
  $embargoed = islandora_ip_embargo_get_embargo($pid)
    ->rowCount();

  $writer = new XMLWriter();
  $writer->openURI('php://output');
  $writer->startElement('embargo_info');
  $writer->writeElement('embargo_status', $embargoed ? 'true' : 'false');
  $writer->endElement();
  $writer->flush();
}

<?php

/**
 * @file
 * Utility functions.
 */

/**
 * Gets a list of member site namespaces.
 *
 * @return array
 *   List of member site namespaces.
 */
function oclsdora_leader_site_behaviours_member_namespaces() {
  return array(
    'seneca',
    'conestoga',
    'fleming',
    'centennial',
    'loyalist',
    'georgian',
  );
}

/**
 * Determines whether a PID represents an IP-restricted member site object.
 *
 * @param string $pid
 *   The PID of the object to check.
 *
 * @return bool
 *   Boolean representing whether the given $pid represents an IP-restricted
 *   member object.
 */
function oclsdora_leader_site_behaviours_is_ip_restricted_member_object($pid) {
  module_load_include('inc', 'islandora_ip_embargo', 'includes/utilities');
  if (islandora_ip_embargo_restrict_access($pid)) {
    $pid_bits = explode(':', $pid);
    if (in_array(reset($pid_bits), oclsdora_leader_site_behaviours_member_namespaces())) {
      return TRUE;
    }
  }
  return FALSE;
}

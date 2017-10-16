<?php

/**
 * @file
 * Utility functions.
 */

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
  $pid_bits = explode(':', $pid);
  $namespace = reset($pid_bits);
  if (in_array($namespace, array(
    'seneca',
    'conestoga',
    'fleming',
    'centennial',
    'loyalist',
    'georgian',
  ))) {
    $qp = new IslandoraSolrQueryProcessor();
    $qp->buildQuery("PID:\"{$pid}\"");
    $qp->solrParams['fl'] = "PID," . OCLSDORA_LEADER_SITE_BEHAVIOURS_IP_RESTRICTED_FIELD;
    $qp->executeQuery(FALSE);
    $doc = reset($qp->islandoraSolrResult['response']['objects']);
    return isset($doc['solr_doc'][OCLSDORA_LEADER_SITE_BEHAVIOURS_IP_RESTRICTED_FIELD]) ? $doc['solr_doc'][OCLSDORA_LEADER_SITE_BEHAVIOURS_IP_RESTRICTED_FIELD] : FALSE;
  }
  return FALSE;
}

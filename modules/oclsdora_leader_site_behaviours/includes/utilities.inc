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
  $qp = new IslandoraSolrQueryProcessor();
  $qp->buildQuery("PID:\"{$pid}\"");
  $qp->solrParams['fl'] = "PID," . OCLSDORA_LEADER_SITE_BEHAVIOURS_IP_RESTRICTED_FIELD;
  $qp->executeQuery(FALSE);
  $doc = reset($qp->islandoraSolrResult['response']['objects']);
  return isset($doc['solr_doc'][OCLSDORA_LEADER_SITE_BEHAVIOURS_IP_RESTRICTED_FIELD]) ? $doc['solr_doc'][OCLSDORA_LEADER_SITE_BEHAVIOURS_IP_RESTRICTED_FIELD] : FALSE;
}
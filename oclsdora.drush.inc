<?php

/**
 * @file
 * Holds Drush commands for OCLS.
 */

/**
 * Implements hook_drush_command().
 */
function oclsdora_drush_command() {
  $commands = array();
  $commands['oclsdora-add-missing-model'] = array(
    'aliases' => array(
      'oamm',
    ),
  );
  return $commands;
}

/**
 * Drush command callback for oclsdora-add-missing-model.
 */
function drush_oclsdora_add_missing_model() {
  $model_field = variable_get('islandora_solr_content_model_field', 'RELS_EXT_hasModel_uri_ms');
  $qp = new islandoraSolrQueryProcessor();
  $qp->buildQuery(format_string('-!model_field:*', array('!model_field' => $model_field)));
  $qp->solrParams['fl'] = 'PID';
  $qp->solrParams['fq'] = array();
  $qp->solrLimit = 10000000;
  $qp->sort = 'fgs_lastModifiedDate_dt asc';
  $qp->executeQuery(FALSE);
  $processed = 0;
  foreach ($qp->islandoraSolrResult['response']['objects'] as $solr_doc) {
    $object = islandora_object_load($solr_doc['PID']);
    $object->models = 'islandora:sp_pdf';
    $processed = $processed + 1;
    drush_log(dt('@processed/@total Updated the content model for @pid.', array(
      '@processed' => $processed,
      '@total' => $qp->islandoraSolrResult['response']['numFound'],
      '@pid' => $solr_doc['PID'],
    )));
  }
}

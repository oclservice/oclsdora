<?php

/**
 * @file
 * Holds default rules for OCLS.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function oclsdora_default_rules_configuration() {
  $email_on_ingest_export = file_get_contents(drupal_get_path('module', 'oclsdora') . '/rules/ingest.rule');
  $email_on_ingest_rule = rules_import($email_on_ingest_export);
  return array(
    'oclsdora_email_on_guided_ingest_completion' => $email_on_ingest_rule,
  );
}

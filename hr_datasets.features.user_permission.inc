<?php
/**
 * @file
 * hr_datasets.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hr_datasets_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use search_api_autocomplete for search_api_views_hr_datasets'.
  $permissions['use search_api_autocomplete for search_api_views_hr_datasets'] = array(
    'name' => 'use search_api_autocomplete for search_api_views_hr_datasets',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'search_api_autocomplete',
  );

  return $permissions;
}

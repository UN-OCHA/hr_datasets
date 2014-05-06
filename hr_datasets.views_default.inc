<?php
/**
 * @file
 * hr_datasets.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hr_datasets_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hr_datasets';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_default_node_index';
  $view->human_name = 'Datasets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'sort' => array(
      'bef_format' => 'bef_toggle_links',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 1,
        'combine_rewrite' => 'Dataset Date Asc|Oldest first
Dataset Date Desc|Newest first',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
      ),
      'mefibs_block_sort_bef' => 'sorts',
    ),
    'search_api_views_fulltext' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'panopoly_wysiwyg_text';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'search_result';
  /* Field: Indexed Node: Dataset Categories */
  $handler->display->display_options['fields']['field_dataset_categories']['id'] = 'field_dataset_categories';
  $handler->display->display_options['fields']['field_dataset_categories']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_dataset_categories']['field'] = 'field_dataset_categories';
  $handler->display->display_options['fields']['field_dataset_categories']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_dataset_categories']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_dataset_categories']['bypass_access'] = 0;
  /* Field: Indexed Node: Summary */
  $handler->display->display_options['fields']['field_ds_summary']['id'] = 'field_ds_summary';
  $handler->display->display_options['fields']['field_ds_summary']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_summary']['field'] = 'field_ds_summary';
  /* Field: Indexed Node: Dataset Date */
  $handler->display->display_options['fields']['field_ds_date']['id'] = 'field_ds_date';
  $handler->display->display_options['fields']['field_ds_date']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_date']['field'] = 'field_ds_date';
  $handler->display->display_options['fields']['field_ds_date']['settings'] = array(
    'format_type' => 'hr_1',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Indexed Node: Abstract */
  $handler->display->display_options['fields']['field_ds_abstract']['id'] = 'field_ds_abstract';
  $handler->display->display_options['fields']['field_ds_abstract']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_abstract']['field'] = 'field_ds_abstract';
  /* Field: Indexed Node: Dataset Files */
  $handler->display->display_options['fields']['field_ds_files']['id'] = 'field_ds_files';
  $handler->display->display_options['fields']['field_ds_files']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_files']['field'] = 'field_ds_files';
  $handler->display->display_options['fields']['field_ds_files']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_ds_files']['delta_offset'] = '0';
  /* Field: Indexed Node: Instructions */
  $handler->display->display_options['fields']['field_ds_instructions']['id'] = 'field_ds_instructions';
  $handler->display->display_options['fields']['field_ds_instructions']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['fields']['field_ds_instructions']['field'] = 'field_ds_instructions';
  /* Sort criterion: Indexed Node: Dataset Date */
  $handler->display->display_options['sorts']['field_ds_date']['id'] = 'field_ds_date';
  $handler->display->display_options['sorts']['field_ds_date']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['sorts']['field_ds_date']['field'] = 'field_ds_date';
  $handler->display->display_options['sorts']['field_ds_date']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_ds_date']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_ds_date']['expose']['label'] = 'Dataset Date';
  /* Contextual filter: Indexed Node: Groups audience */
  $handler->display->display_options['arguments']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['arguments']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['arguments']['og_group_ref']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['og_group_ref']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['og_group_ref']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['og_group_ref']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['og_group_ref']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['og_group_ref']['validate_options']['types'] = array(
    'hr_operation' => 'hr_operation',
  );
  $handler->display->display_options['arguments']['og_group_ref']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['og_group_ref']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['og_group_ref']['not'] = 0;
  /* Filter criterion: Indexed Node: Content type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hr_dataset' => 'hr_dataset',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Indexed Node: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_default_node_index';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search Datasets';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    30037204 => 0,
  );

  /* Display: Master */
  $handler = $view->new_display('page', 'Master', 'master');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['mefibs'] = array(
    'blocks' => array(
      0 => array(
        'name' => 'Sorts',
        'machine_name' => 'sorts',
      ),
    ),
    'extras' => array(
      'sort' => NULL,
      'items_per_page' => NULL,
    ),
    'list' => array(
      'sort_block' => 'sorts',
      'filter' => array(),
    ),
    'master' => array(
      'filter' => array(),
      'sort_block' => 'sorts',
    ),
  );
  $handler->display->display_options['path'] = 'node/%/datasets';

  /* Display: List */
  $handler = $view->new_display('page', 'List', 'list');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['mefibs'] = array(
    'blocks' => array(
      0 => array(
        'name' => 'Sorts',
        'machine_name' => 'sorts',
      ),
    ),
    'extras' => array(
      'sort' => NULL,
      'items_per_page' => NULL,
    ),
    'list' => array(
      'sort_block' => 'sorts',
      'filter' => array(),
    ),
  );
  $handler->display->display_options['path'] = 'node/%/datasets/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Table */
  $handler = $view->new_display('page', 'Table', 'table');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['mefibs'] = array(
    'blocks' => array(
      0 => array(
        'name' => 'Sorts',
        'machine_name' => 'sorts',
      ),
    ),
    'extras' => array(
      'sort' => NULL,
      'items_per_page' => NULL,
    ),
    'list' => array(
      'sort_block' => 'sorts',
      'filter' => array(),
    ),
    'table' => array(
      'filter' => array(),
      'sort_block' => 'sorts',
    ),
  );
  $handler->display->display_options['path'] = 'node/%/datasets/table';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Table';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $translatables['hr_datasets'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Select any filter and click on Apply to see results'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Dataset Categories'),
    t('Summary'),
    t('Dataset Date'),
    t('Abstract'),
    t('Dataset Files'),
    t('Instructions'),
    t('All'),
    t('Search Datasets'),
    t('List'),
    t('Table'),
  );
  $export['hr_datasets'] = $view;

  return $export;
}

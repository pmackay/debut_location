<?php
/**
 * @file
 * debut_location.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function debut_location_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'location_map';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Location map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Location map';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'openlayers_map';
  $handler->display->display_options['style_options']['map'] = 'location_map';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'location-map';
  $export['location_map'] = $view;

  $view = new view;
  $view->name = 'location_map_data';
  $view->description = 'Location data layer for a map';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Location map data';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Location map data';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'openlayers_data';
  $handler->display->display_options['style_options']['data_source'] = array(
    'value' => 'other_latlon',
    'other_lat' => 'field_geolocation_1',
    'other_lon' => 'field_geolocation',
    'wkt' => 'field_geolocation',
    'other_top' => 'title',
    'other_right' => 'title',
    'other_bottom' => 'title',
    'other_left' => 'title',
    'name_field' => 'title',
    'description_field' => 'body',
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Geolocation */
  $handler->display->display_options['fields']['field_geolocation_1']['id'] = 'field_geolocation_1';
  $handler->display->display_options['fields']['field_geolocation_1']['table'] = 'field_data_field_geolocation';
  $handler->display->display_options['fields']['field_geolocation_1']['field'] = 'field_geolocation';
  $handler->display->display_options['fields']['field_geolocation_1']['label'] = '';
  $handler->display->display_options['fields']['field_geolocation_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_geolocation_1']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_geolocation_1']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_geolocation_1']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_geolocation_1']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_geolocation_1']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_geolocation_1']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_geolocation_1']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_geolocation_1']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_geolocation_1']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_geolocation_1']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_geolocation_1']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_geolocation_1']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_geolocation_1']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_geolocation_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geolocation_1']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_geolocation_1']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_geolocation_1']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_geolocation_1']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_geolocation_1']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_geolocation_1']['type'] = 'geofield_lat';
  $handler->display->display_options['fields']['field_geolocation_1']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  $handler->display->display_options['fields']['field_geolocation_1']['field_api_classes'] = 0;
  /* Field: Content: Geolocation */
  $handler->display->display_options['fields']['field_geolocation']['id'] = 'field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['table'] = 'field_data_field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['field'] = 'field_geolocation';
  $handler->display->display_options['fields']['field_geolocation']['label'] = '';
  $handler->display->display_options['fields']['field_geolocation']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_geolocation']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_geolocation']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_geolocation']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geolocation']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_geolocation']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_geolocation']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_geolocation']['click_sort_column'] = 'wkt';
  $handler->display->display_options['fields']['field_geolocation']['type'] = 'geofield_lon';
  $handler->display->display_options['fields']['field_geolocation']['settings'] = array(
    'data' => 'full',
    'format' => 'decimal_degrees',
  );
  $handler->display->display_options['fields']['field_geolocation']['field_api_classes'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'location' => 'location',
  );

  /* Display: OpenLayers Data Overlay */
  $handler = $view->new_display('openlayers', 'OpenLayers Data Overlay', 'openlayers_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $export['location_map_data'] = $view;

  return $export;
}

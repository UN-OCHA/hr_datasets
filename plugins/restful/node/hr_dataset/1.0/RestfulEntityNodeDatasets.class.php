<?php

/**
 * @file
 * Contains \RestfulEntityNodeDatasets.
 */

class RestfulEntityNodeDatasets extends \RestfulEntityBaseNode {

  /**
   * Overrides RestfulEntityBaseNode::addExtraInfoToQuery()
   * 
   * Adds proper query tags
   */
  protected function addExtraInfoToQuery($query) {
    parent::addExtraInfoToQuery($query);
    $filters = $this->parseRequestForListFilter();
    if (!empty($filters)) {
      foreach ($query->tags as $i => $tag) {
        if ($tag == 'node_access') {
          unset($query->tags[$i]);
        }
      }
      $query->addTag('entity_field_access');
    }
  }

  /**
   * Overrides \RestfulEntityBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    $public_fields = parent::publicFieldsInfo();


    $public_fields['files'] = array(
      'property' => 'field_ds_files',
      'process_callbacks' => array(array($this, 'getFiles')),
    );

    $public_fields['operation'] = array(
      'property' => 'og_group_ref',
      'resource' => array(
        'hr_operation' => 'operations',
      ),
      'process_callbacks' => array(array($this, 'getEntity')),
    );

    /*$public_fields['space'] = array(
      'property' => 'og_group_ref',
      'resource' => array(
        'hr_space' => 'spaces',
      ),
      'process_callbacks' => array(array($this, 'getEntity')),
    );*/

    $public_fields['url'] = array(
      'property' => 'url',
    );

    return $public_fields;
  }

  protected function getEntity($wrapper) {
    foreach ($wrapper as &$item) {
      $array_item = (array)$item;
      $properties = array_keys($array_item);
      foreach ($properties as $property) {
        if (!in_array($property, array('id', 'label', 'self'))) {
          unset($array_item[$property]);
        }
      }
      $item = (object)$array_item;
    }
    return $wrapper;
  }

  protected function getFiles($values) {
    $return = array();
    if (!empty($values)) {
      foreach ($values as $value) {
        $tmp = new stdClass();
        $tmp->fid = $value['fid'];
        $tmp->filename = $value['filename'];
        $tmp->filesize = $value['filesize'];
        $tmp->url = file_create_url($value['uri']);
        $return[] = $tmp;
      }
    }
    return $return;
  }

}

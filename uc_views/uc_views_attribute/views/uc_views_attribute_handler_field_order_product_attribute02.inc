<?php
// $Id: uc_views_attribute_handler_field_order_product_attribute.inc,v 1.1.2.2 2010/01/12 20:07:04 hanoii Exp $

/**
 * Field handler to provide a human-readable version of the selected combination of attributes
 */
class uc_views_attribute_handler_field_order_product_attribute02 extends views_handler_field {
 
  /**
   * Defines a few default options for the combination field
   */
  function option_definition() {
    $options = parent::option_definition();

    return $options;
  }

  function render($values) {
    $data = unserialize($values->{$this->field_alias});
    $result = "heck yeah";
    if (is_array($data['attributes'])) {
      $result = 'even better';
      $rows = array();
      foreach ($data['attributes'] as $attribute => $option) {
        $rows[] = t('@option', array('@attribute' => $attribute, '@option' => implode(', ', (array) $option)));
        if (count($rows)) {
		//Grab the value for the second attribute.
		$result = $rows[1];
          //$result = theme('item_list', array('items' => $rows, 'title' => NULL, 'type' => 'ul', 'attributes' => array('class' => 'product-description')));
        }
      }
    }
    return $result;
  }
}

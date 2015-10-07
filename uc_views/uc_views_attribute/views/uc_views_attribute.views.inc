<?php
/**
 * @file
 * Views 2 hooks and callback registries.
 */

/**
 * Implements hook_views_data().
 */
function uc_views_attribute_views_data() {
  $uc_product_attributes = drupal_get_schema('uc_product_attributes');
  //Create a filter for each product attribute
  $result = db_query("SELECT aid, name, description FROM {uc_attributes}");
foreach($result as $row) {
    $data['uc_order_products']['attr_' . $row->aid] = array(
      'title' => 'Attribute: ' . $row->name,
      'help' => 'Attribute desc: ' . $row->description,
      'filter' => array(
        'handler' => 'uc_views_attribute_handler_filter_attr',
      ),
      'aid' => $row->aid,
    );
  }

  // Patch by hanoii
  $data['uc_product_adjustments']['table']['group'] = t('Product attributes');

  $uc_product_adjustments = drupal_get_schema('uc_product_adjustments');

  $data['uc_product_adjustments']['table']['join']['node'] = array(
    'left_field' => 'nid',
    'field' => 'nid',
  );

  $data['uc_product_adjustments']['model'] = array(
    'title' => t('Model'),
    'help' => $uc_product_adjustments['fields']['model']['description'],
    'field' => array(
      'handler' => 'views_handler_field',
    ),
    'relationship' => array(
      'base' => 'uc_product_stock',
      'base field' => 'sku',
      'relationship field' => 'model',
      'handler' => 'views_handler_relationship',
      'label' => t('Model'),
    ),
  );

  $data['uc_product_adjustments']['combination'] = array(
    'title' => t('Attributes'),
    'help' => t('Product combination of attributes.'),
    'field' => array(
      'handler' => 'uc_views_attribute_handler_field_combination',
    ),
  );
  $data['uc_product_adjustments']['combination_sell_price'] = array(
    'title' => t('Sell price w/attributes adjustment'),
    'help' => t('The sell price of the product with all the price adjustments from its combination of attributes.'),
    'field' => array(
      'additional fields' => array(
        'combination',
      ),
      'handler' => 'uc_views_attribute_handler_field_combination_price',
      'price' => 'sell_price',
      'float' => TRUE,
    ),
  );

  $data['uc_product_adjustments']['combination_cost_price'] = array(
    'title' => t('Cost price w/attributes adjustment'),
    'help' => t('The cost price of the product with all the price adjustments from its combination of attributes.'),
    'field' => array(
      'additional fields' => array(
        'combination',
      ),
      'handler' => 'uc_views_attribute_handler_field_combination_price',
      'price' => 'cost',
      'float' => TRUE,
    ),
  );

  // Add stock relationship to the adjustments table
  $data['uc_product_stock']['sku']['relationship'] = array(
    'base' => 'uc_product_adjustments',
    'base field' => 'model',
    'relationship field' => 'sku',
    'handler' => 'views_handler_relationship',
    'label' => t('SKU'),
  );

  // Add viewhandler for uc_order_product attributes
  $data['uc_order_products']['attributes'] = array(
    'title' => t('Product attributes'),
    'help' => t('List of attribute selection for the ordered product.'),
    'group' => t('Ubercart order product'),
    'field' => array(
      'table' => 'uc_order_products',
      'field' => 'data',
      'handler' => 'uc_views_attribute_handler_field_order_product_attribute',
    ),
  );
  
// Add viewhandler for uc_order_product attributes: Attribute 01
  $data['uc_order_products']['attributes01'] = array(
    'title' => t('Product attribute 01'),
    'help' => t('The first attribute selection for the ordered product.'),
    'group' => t('Ubercart order product'),
    'field' => array(
      'table' => 'uc_order_products',
    	'real field' => 'data',
      'handler' => 'uc_views_attribute_handler_field_order_product_attribute01',
    ),
  );  
  
  // Add viewhandler for uc_order_product attributes: Attribute 02
  $data['uc_order_products']['attributes02'] = array(
    'title' => t('Product attribute 02'),
    'help' => t('The second attribute selection for the ordered product.'),
    'group' => t('Ubercart order product'),
    'field' => array(
      'table' => 'uc_order_products',
    	'real field' => 'data',
      'handler' => 'uc_views_attribute_handler_field_order_product_attribute02',
    ),
  ); 
  
    // Add viewhandler for uc_order_product attributes: Attribute 03
  $data['uc_order_products']['attributes03'] = array(
    'title' => t('Product attribute 03'),
    'help' => t('The third attribute selection for the ordered product.'),
    'group' => t('Ubercart order product'),
    'field' => array(
      'table' => 'uc_order_products',
    	'real field' => 'data',
      'handler' => 'uc_views_attribute_handler_field_order_product_attribute03',
    ),
  );
   
      // Add viewhandler for uc_order_product attributes: Attribute 04
  $data['uc_order_products']['attributes04'] = array(
    'title' => t('Product attribute 04'),
    'help' => t('The fourth attribute selection for the ordered product.'),
    'group' => t('Ubercart order product'),
    'field' => array(
      'table' => 'uc_order_products',
    	'real field' => 'data',
      'handler' => 'uc_views_attribute_handler_field_order_product_attribute04',
    ),
  );
  
        // Add viewhandler for uc_order_product attributes: Attribute 05
  $data['uc_order_products']['attributes05'] = array(
    'title' => t('Product attribute 05'),
    'help' => t('The fifth attribute selection for the ordered product.'),
    'group' => t('Ubercart order product'),
    'field' => array(
      'table' => 'uc_order_products',
    	'real field' => 'data',
      'handler' => 'uc_views_attribute_handler_field_order_product_attribute05',
    ),
  );
  
          // Add viewhandler for uc_order_product attributes: Attribute 06
  $data['uc_order_products']['attributes06'] = array(
    'title' => t('Product attribute 06'),
    'help' => t('The sixth attribute selection for the ordered product.'),
    'group' => t('Ubercart order product'),
    'field' => array(
      'table' => 'uc_order_products',
    	'real field' => 'data',
      'handler' => 'uc_views_attribute_handler_field_order_product_attribute06',
    ),
  ); 
  
            // Add viewhandler for uc_order_product attributes: Attribute 07
  $data['uc_order_products']['attributes07'] = array(
    'title' => t('Product attribute 07'),
    'help' => t('The seventh attribute selection for the ordered product.'),
    'group' => t('Ubercart order product'),
    'field' => array(
      'table' => 'uc_order_products',
    	'real field' => 'data',
      'handler' => 'uc_views_attribute_handler_field_order_product_attribute07',
    ),
  ); 

  
  return $data;
}

/**
 * Implements hook_views_handlers().
 */
function uc_views_attribute_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'uc_views_attribute') . '/views',
    ),
    'handlers' => array(
      // fields
      'uc_views_attribute_handler_field_combination' => array('parent' => 'views_handler_field'),
      'uc_views_attribute_handler_field_order_product_attribute' => array('parent' => 'views_handler_field'),
      'uc_views_attribute_handler_field_combination_price' => array('parent' => 'uc_views_handler_field_money_amount'),
      //fiters
      'uc_views_attribute_handler_filter_attr' => array('parent' => 'views_handler_filter_in_operator'),
    ),
  );
}

/**
 * Conditionally add editablefields support.
 */
function uc_views_attribute_views_tables_alter(&$tables) { }

/**
 * Load all attributes.
 */
function uc_get_attributes() {
  $result = db_query("SELECT aid FROM {uc_attributes} ORDER BY ordering");
  $chosen_attr = array();
  while ($attr = db_fetch_object($result)) {
    $chosen_attr[$attr->aid] = uc_attribute_load($attr->aid);
  }
  return $chosen_attr;
}

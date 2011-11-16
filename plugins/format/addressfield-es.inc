<?php

/**
 * @file
 * A specific handler for ES.
 */

$plugin = array(
  'title' => t('Address form (ES add-on)'),
  'format callback' => 'addressfield_format_address_es_generate',
  'type' => 'address',
  'weight' => -80,
);

function addressfield_format_address_es_generate(&$format, $address, $context = array()) {
  if ($address['country'] == 'ES') {
    if ($context['mode'] == 'form') {	            
      $format['street_block']['#attributes']['class'][] = 'addressfield-container-inline';    
      $format['street_block']['thoroughfare']['#title'] = t('Street');
      $format['street_block']['thoroughfare']['#type'] = 'textfield';
      $format['street_block']['thoroughfare']['#default_value'] = $address['thoroughfare'];
      $format['street_block']['premise'] = array(
        '#title' => t('Number'),
        '#type' => 'textfield',
        '#size' => 8,
        '#default_value' => $address['premise'],
      );

      $format['sub_premise'] = array(
        '#title' => t('Floor / Stair / Door'),
        '#type' => 'textfield',
        '#size' => 30,
        '#default_value' => $address['sub_premise'],
      );
    }
    else {
    	$format['street_block']['thoroughfare']['#tag'] = 'span';
      if (isset($address['premise']) && $address['premise'] != ''){
        $format['street_block']['thoroughfare']['#suffix'] = ', ';
        $format['street_block']['premise']['#tag'] = 'span';	
      }
      if (isset($address['sub_premise']) && $address['sub_premise'] != ''){
        $format['street_block']['premise']['#suffix'] = ', ';
        $format['street_block']['sub_premise']['#tag'] = 'span';	
      }    	
    	
    }
    hide($format['country']);
    $format['locality_block']['administrative_area']['#options'] = array(
        ''   => t('--'),
        'a-coruna' => t('A Coruña'),
        'alava' => t('Álava'),
        'albacete' => t('Albacete'),
        'alicante' => t('Alicante'),
        'almeria' => t('Almería'),
        'asturias' => t('Asturias'),
        'avila' => t('Ávila'),
        'badajoz' => t('Badajoz'),
        'baleares' => t('Baleares'),
        'barcelona' => t('Barcelona'),
        'burgos' => t('Burgos'),
        'caceres' => t('Cáceres'),
        'cadiz' => t('Cádiz'),
        'cantabria' => t('Cantabria'),
        'castellon' => t('Castellón'),
        'ceuta' => t('Ceuta'),
        'ciudad-real' => t('Ciudad Real'),
        'cordoba' => t('Córdoba'),
        'cuenca' => t('Cuenca'),
        'girona' => t('Girona'),
        'granada' => t('Granada'),
        'guadalajara' => t('Guadalajara'),
        'guipuzcoa' => t('Guipúzcoa'),
        'huelva' => t('Huelva'),
        'huesca' => t('Huesca'),
        'jaen' => t('Jaén'),
        'la-rioja' => t('La Rioja'),
        'las-palmas' => t('Las Palmas'),
        'leon' => t('León'),
        'lleida' => t('Lleida'),
        'lugo' => t('Lugo'),
        'madrid' => t('Madrid'),
        'malaga' => t('Málaga'),
        'melilla' => t('Melilla'),
        'murcia' => t('Murcia'),
        'navarra' => t('Navarra'),
        'ourense' => t('Ourense'),
        'palencia' => t('Palencia'),
        'pontevedra' => t('Pontevedra'),
        'salamanca' => t('Salamanca'),
        'santa-cruz-tenerife' => t('Santa Cruz de Tenerife'),
        'segovia' => t('Segovia'),
        'sevilla' => t('Sevilla'),
        'soria' => t('Soria'),
        'tarragona' => t('Tarragona'),
        'teruel' => t('Teruel'),
        'toledo' => t('Toledo'),
        'valencia' => t('Valencia'),
        'valladolid' => t('Valladolid'),
        'vizcaya' => t('Vizcaya'),
        'zamora' => t('Zamora'),
        'zaragoza' => t('Zaragoza'),
      );
  }
}


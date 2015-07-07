<?php

require_once('common_constants.php');

function get_assoc_array($mysql_result) {
	$assoc_array = array();

	while ($row = mysql_fetch_assoc($mysql_result)) {
		array_push($assoc_array, $row);
	}

	return $assoc_array;
}

function get_customers($db) {
	$customers = null;

	$sql_select_customers = '
		SELECT *
		FROM customers
		;
	';

	$mysql_result = mysql_query($sql_select_customers, $db);

	$customers = get_assoc_array($mysql_result);

	return $customers;
}

function get_customer_by_userID($db, $customerID) {
	$customer = null;

	$sql_select_customer_by_userID = '
		SELECT *
		FROM customers
		WHERE id = ' . $customerID . '
		;
	';

	$mysql_result = mysql_query($sql_select_customer_by_userID, $db);

	$customer = get_assoc_array($mysql_result);

	return $customer[0];
}

function get_db_connection() {
	$db = mysql_connect(DB_SERVER_ADDRESS, DB_USER, DB_PASSWORD);

	mysql_select_db(DB_DATENBANK, $db);

	return $db;
}

function get_first_customerID($db) {
	$customerID = null;

	$sql_select_first_customerID = '
		SELECT MIN(id) AS "customerID"
		FROM customers
		;
	';
	$mysql_result = mysql_query($sql_select_first_customerID, $db);

	$result = get_assoc_array($mysql_result);

	$customerID = $result[0]['customerID'];

	return $customerID;
}

function get_last_customerID($db) {
	$customerID = null;

	$sql_select_last_customerID = '
		SELECT MAX(id) AS "customerID"
		FROM customers
		;
	';
	$mysql_result = mysql_query($sql_select_last_customerID, $db);

	$result = get_assoc_array($mysql_result);

	$customerID = $result[0]['customerID'];

	return $customerID;
}

function get_next_customerID($db, $currentCustomerID) {
	$customerID = null;

	$sql_select_first_customerID = '
		SELECT id AS "customerID"
		FROM customers
		WHERE id > ' . $currentCustomerID . '
		ORDER BY id
		LIMIT 1
		;
	';
	$mysql_result = mysql_query($sql_select_first_customerID, $db);

	$result = get_assoc_array($mysql_result);

	if (count($result) == 0) {
		$customerID = null;
	} else {
		$customerID = $result[0]['customerID'];
	}

	return $customerID;
}

function get_orders($db) {
	$orders = null;

	$sql_select_orders = '
		SELECT
			o.id AS "orderID",
			o.*,
			c.id AS "customerID",
			c.*
		FROM
			orders AS o
			JOIN customers AS c ON (c.id = o.customerID)
		;
	';

	$mysql_result = mysql_query($sql_select_orders, $db);

	$orders = get_assoc_array($mysql_result);

	return $orders;
}

function get_previous_customerID($db, $currentCustomerID) {
	$customerID = null;

	$sql_select_first_customerID = '
		SELECT id AS "customerID"
		FROM customers
		WHERE id < ' . $currentCustomerID . '
		ORDER BY id
		LIMIT 1
		;
	';
	$mysql_result = mysql_query($sql_select_first_customerID, $db);

	$result = get_assoc_array($mysql_result);

	if (count($result) == 0) {
		$customerID = null;
	} else {
		$customerID = $result[0]['customerID'];
	}

	return $customerID;
}

function insert_customer($db, $array_insert_customer) {
	$customerID = false;

	$keys = array_keys($array_insert_customer);
	sort($keys);
	sort($array_insert_customer);

	# Text fields in ''
	foreach ($array_insert_customer as $field_name => $value) {
		if (!is_numeric($value)) {
			$array_insert_customer[$field_name] = "'" . $value . "'";
		}
	}

	# Comma-separated list
	$field_name_list = implode(', ', $keys);
	$values_list = implode(', ', $array_insert_customer);

	$sql_insert_customer = "
		INSERT INTO `customers`
			($field_name_list)
		VALUES
			($values_list)
		;
	";

	$query_ok = mysql_query($sql_insert_customer, $db);

	if (!$query_ok) {
		echo(mysql_error($db));
		echo("<br/>\n<hr/><br/>\n");
		echo($sql_insert_customer);
	} else {
		$customerID = mysql_insert_id($db);
	}

	return $customerID;
}

function insert_order($db, $array_insert_order) {
	$orderID = false;

	$keys = array_keys($array_insert_order);
	sort($keys);
	sort($array_insert_order);

	# Text fields in ''
	foreach ($array_insert_order as $field_name => $value) {
		if (!is_numeric($value)) {
			$array_insert_order[$field_name] = "'" . $value . "'";
		}
	}

	# Comma-separated list
	$field_name_list = implode(', ', $keys);
	$values_list = implode(', ', $array_insert_order);

	$sql_insert_order = "
		INSERT INTO `orders`
			($field_name_list)
		VALUES
			($values_list)
		;
	";

	$query_ok = mysql_query($sql_insert_order, $db);

	if (!$query_ok) {
		echo(mysql_error($db));
		echo("<br/>\n<hr/><br/>\n");
		echo($sql_insert_order);
		die();
	} else {
		$orderID = mysql_insert_id($db);
	}

	return $orderID;
}

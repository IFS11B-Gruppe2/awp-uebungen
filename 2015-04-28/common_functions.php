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

function get_db_connection() {
	$db = mysql_connect(DB_SERVER_ADDRESS, DB_USER, DB_PASSWORD);

	mysql_select_db(DB_DATENBANK, $db);

	return $db;
}

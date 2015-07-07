<?php
	require_once('common_functions.php');

	$db = get_db_connection();

	if (isset($_POST['hidCustomerID'])) {
		$current_customerID = $_POST['hidCustomerID'];
	} else {
		$current_customerID = get_first_customerID($db);
	}

	if (isset($_POST['btnShowFirst'])) {
		$current_customerID = get_first_customerID($db);
	}

	if (isset($_POST['btnShowPrevious'])) {
		$customerID = get_previous_customerID($db, $current_customerID);

		if ($customerID != null) {
			$current_customerID = $customerID;
		}
	}

	if (isset($_POST['btnShowNext'])) {
		$customerID = get_next_customerID($db, $current_customerID);

		if ($customerID != null) {
			$current_customerID = $customerID;
		}
	}

	if (isset($_POST['btnShowLast'])) {
		$current_customerID = get_last_customerID($db);
	}

	$customer = get_customer_by_userID($db, $current_customerID);

	if (isset($_POST['btnUpdateCustomer'])) {
		$array_update_customer = array(
			'firstname' => mysql_real_escape_string($_POST['txtCustomerFirstname']),
			'lastname'  => mysql_real_escape_string($_POST['txtCustomerLastname']),
			'address'   => mysql_real_escape_string($_POST['txtCustomerAddress'])
		);

		$customer_updated = update_customer($db, $array_update_customer);
	}
?>
<!DOCTYPE html>
<html lang="de">
<head>
	<meta charset="UTF-8">
	<title>Kundendaten ändern</title>
</head>
<body>
	<?php include_once('nav_menu.html') ?>

	<h3>Kundendaten ändern</h3>

	<?php if (isset($customer_updated) and $customer_updated === true) { ?>
		<div class="info">
			<strong>Kunde geändert</strong>
		</div>
	<?php } ?>

	<form method="post">
		<input type="hidden" name="hidCustomerID" value="<?php echo $current_customerID; ?>" />

		<table>
			<tbody>
				<tr>
					<td><label for="txtCustomerID">id:</label></td>

					<td><input type="text" id="txtCustomerID" disabled name="txtCustomerID" value="<?php echo $customer['id'] ?>" /></td>
				</tr>

				<tr>
					<td><label for="txtCustomerFirstname">Name:</label></td>

					<td><input type="text" id="txtCustomerFirstname" name="txtCustomerFirstname" value="<?php echo $customer['firstname'] ?>" /></td>
				</tr>

				<tr>
					<td><label for="txtCustomerLastname">Vorname:</label></td>

					<td><input type="text" id="txtCustomerLastname" name="txtCustomerLastname" value="<?php echo $customer['lastname'] ?>" /></td>
				</tr>

				<tr>
					<td><label for="txtCustomerAddress">Straße:</label></td>

					<td><input type="text" id="txtCustomerAddress" name="txtCustomerAddress" value="<?php echo $customer['address'] ?>" /></td>
				</tr>

				<tr>
					<td colspan="2"><input type="submit" name="btnUpdateCustomer" value="Ändern" /></td>
				</tr>

				<tr>
					<td colspan="2">
						<input type="submit" name="btnShowFirst" value="<<" />

						<input type="submit" name="btnShowPrevious" value="<" />

						<input type="submit" name="btnShowNext" value=">" />

						<input type="submit" name="btnShowLast" value=">>" />
					</td>
				</tr>
			</tbody>
		</table>
	</form>
</body>
</html>

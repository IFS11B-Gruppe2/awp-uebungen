<?php
	require_once('common_functions.php');

	if (isset($_POST['btnInsertCustomer'])) {
		$db = get_db_connection();

		$array_insert_customer = array(
			'firstname' => mysql_real_escape_string($_POST['txtCustomerFirstname']),
			'lastname'  => mysql_real_escape_string($_POST['txtCustomerLastname']),
			'address'   => mysql_real_escape_string($_POST['txtCustomerAddress'])
		);

		$customerID = insert_customer($db, $array_insert_customer);
	}
?>
<!DOCTYPE html>
<html lang="de">
<head>
	<meta charset="UTF-8">
	<title>Neuer kunde</title>
</head>
<body>
	<?php include_once('nav_menu.html') ?>

	<h3>Neuer kunde</h3>

	<?php if (isset($customerID) and $customerID !== false) { ?>
		<div class="info">
			<strong>Kunde eingetragen, ID: <?php echo $customerID; ?></strong>
		</div>
	<?php } ?>

	<form method="post">
		<table>
			<tbody>
				<tr>
					<td><label for="txtCustomerFirstname">Name:</label></td>

					<td><input type="text" id="txtCustomerFirstname" name="txtCustomerFirstname" /></td>
				</tr>

				<tr>
					<td><label for="txtCustomerLastname">Vorname:</label></td>

					<td><input type="text" id="txtCustomerLastname" name="txtCustomerLastname" /></td>
				</tr>

				<tr>
					<td><label for="txtCustomerAddress">Straße:</label></td>

					<td><input type="text" id="txtCustomerAddress" name="txtCustomerAddress" /></td>
				</tr>

				<tr>
					<td colspan="2"><input type="submit" name="btnInsertCustomer" value="Hinzufügen" /></td>
				</tr>
			</tbody>
		</table>







	</form>
</body>
</html>

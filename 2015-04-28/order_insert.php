<?php
	require_once('common_functions.php');

	$db = get_db_connection();

	$customers = get_customers($db);

	if (isset($_POST['btnInsertOrder'])) {
		$array_insert_order = array(
			'customerID' => mysql_real_escape_string($_POST['txtCustomerID']),
			'date'  => mysql_real_escape_string($_POST['txtOrderDate'])
		);

		$orderID = insert_order($db, $array_insert_order);
	}
?>
<!DOCTYPE html>
<html lang="de">
<head>
	<meta charset="UTF-8">
	<title>Neuer Bestellung</title>
</head>
<body>
	<?php include_once('nav_menu.html') ?>

	<h3>Neuer Bestellung</h3>

	<?php if (isset($orderID) and $orderID !== false) { ?>
		<div class="info">
			<strong>Bestellung eingetragen, ID: <?php echo $orderID; ?></strong>
		</div>
	<?php } ?>

	<form method="post">
		<table>
			<tbody>
				<tr>
					<td><label for="txtCustomerID">Kunde:</label></td>

					<td>
						<select id="txtCustomerID" name="txtCustomerID">
							<?php foreach ($customers as $row) { ?>
								<option value="<?php echo $row['id']; ?>">
									<?php echo $row['id'] . ' -- ' . $row['firstname']; ?>
								</option>
							<?php } ?>
						</select>
					</td>
				</tr>

				<tr>
					<td><label for="txtOrderDate">Datum:</label></td>

					<td><input type="text" id="txtOrderDate" name="txtOrderDate" /></td>
				</tr>

				<tr>
					<td colspan="2"><input type="submit" name="btnInsertOrder" value="Hinzufügen" /></td>
				</tr>
			</tbody>
		</table>
	</form>
</body>
</html>

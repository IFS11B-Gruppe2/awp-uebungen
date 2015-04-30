<?php
	require_once('common_functions.php');

	$db = get_db_connection();

	$orders = get_orders($db);
?>
<!DOCTYPE html>
<html lang="de">
<head>
	<meta charset="UTF-8">
	<title>Liste Bestellungen</title>
</head>
<body>
	<?php include_once('nav_menu.html') ?>

	<h3>Liste Bestellungen</h3>

	<?php if (count($orders) == 0) { ?>
		<div class="info">
			<strong>Noch keine Bestellung vorhanden</strong>
		</div>
	<?php } else { ?>
		<table class="default orders">
			<tbody>
				<tr>
					<th>Bestellung ID</th>

					<th>Datum</th>

					<th>Kunden ID</th>

					<th>Kundenname</th>
				</tr>
				<?php foreach ($orders as $row) { ?>
					<tr>
						<td class="em">
							<?php echo $row['orderID']; ?>
						</td>

						<td>
							<?php echo $row['date']; ?>
						</td>

						<td class="em">
							<?php echo $row['customerID']; ?>
						</td>

						<td>
							<?php echo $row['lastname']; ?>
						</td>
					</tr>
				<?php } ?>
			</tbody>
		</table>
	<?php } ?>
</body>
</html>

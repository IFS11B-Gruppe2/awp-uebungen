<?php
	require_once('common_functions.php');

	$db = get_db_connection();

	$customers = get_customers($db);
?>
<!DOCTYPE html>
<html lang="de">
<head>
	<meta charset="UTF-8">
	<title>Liste Kunden</title>
</head>
<body>
	<?php include_once('nav_menu.html') ?>

	<h3>Liste Kunden</h3>

	<?php if (count($customers) == 0) { ?>
		<div class="info">
			<strong>Noch kein Kunde vorhanden</strong>
		</div>
	<?php } else { ?>
		<table class="default customers">
			<tbody>
				<tr>
					<th>id</th>

					<th>Nachname</th>

					<th>Vorname</th>

					<th>Adresse</th>
				</tr>
				<?php foreach ($customers as $row) { ?>
					<tr>
						<td class="em">
							<?php echo $row['id']; ?>
						</td>

						<td>
							<?php echo $row['lastname']; ?>
						</td>

						<td>
							<?php echo $row['firstname']; ?>
						</td>

						<td class="em">
							<?php echo $row['address']; ?>
						</td>
					</tr>
				<?php } ?>
			</tbody>
		</table>
	<?php } ?>
</body>
</html>

<?php

if (isset($_POST['txtText'])) {
	$look_for = array('A', 'E', 'I', 'O', 'U', 'Ä', 'Ö', 'Ü');
	$upper_text = mb_strtoupper($_POST['txtText'], 'UTF-8');

	$counter = array();
	foreach ($look_for as $value) {
		$counter[$value] = mb_substr_count($upper_text, $value, 'UTF-8');
	}

	$vocals = $counter['A'] + $counter['E'] + $counter['I'] + $counter['O'] + $counter['U'];
	$umlaut = $counter['Ä'] + $counter['Ö'] + $counter['Ü'];
	$total = strlen($upper_text);
	$other = $total - $vocals - $umlaut;

	$output = array(
		'A' => $counter['A'],
		'I' => $counter['I'],
		'E' => $counter['E'],
		'U' => $counter['U'],
		'O' => $counter['O'],
		'Umlaut' => $umlaut,
		'Sonstige' => $other,
		'Summe' => $total
	);
}

?>
<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<title>Zeichen zahlen</title>

	<link rel="stylesheet" href="Zeichen_Zahlen.css">
</head>
<body>
	<h1>Zeichen zahlen</h1>

	<form action="" method="post">
		<input type="text" name="txtText" placeholder="Schreiben Sie hier einen Text..." value="<?php echo @$_POST['txtText'] ?>" />

		<input type="submit" name="btnSend" value="senden" />
	</form>

	<table>
		<tbody>
			<?php if (isset($_POST['txtText'])) { ?>
				<?php foreach ($output as $key => $value) { ?>
					<tr>
						<td><?php echo $key; ?></td>

						<td><?php echo $value; ?></td>
					</tr>
				<?php } ?>
			<?php } ?>
		</tbody>
	</table>
</body>
</html>

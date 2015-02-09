<?php
$values = array();
$repeated_values = array(
	1 => 0,
	2 => 0,
	3 => 0,
	4 => 0,
	5 => 0,
	6 => 0,
);

if (isset($_POST['txtDices']) and !empty($_POST['txtDices']) and is_numeric($_POST['txtDices'])) {
	for ($dice = 0; $dice < $_POST['txtDices']; $dice++) {
		$random_number = rand(1, 6);
		array_push($values, $random_number);
		$repeated_values[$random_number]++;
	}
}

?>
<!DOCTYPE html>
<html lang="de">
<head>
	<meta charset="UTF-8">
	<title>Würfelspiel</title>

	<link rel="stylesheet" href="Wuerfel.css">
</head>
<body>
	<h1>Würfelspiel</h1>

	<form action="" method="post">
		<label for="txtDices">Anzahl der Würfel: </label>
		<input type="text" id="txtDices" name="txtDices" value="6" />

		<input type="submit" name="btnSend" value="würfeln" />
	</form>

	<?php if (isset($_POST['txtDices'])) { ?>
		<?php if (empty($_POST['txtDices']) or !is_numeric($_POST['txtDices'])) { ?>
			<div class="error-message">
				Anzahl der Würfel soll ein Nummer sein.
			</div>
		<?php } else { ?>
			<div>
				<?php foreach ($values as $index => $value) { ?>
					<div class="dice">
						<img src="../img/dice<?php echo $value; ?>.jpg" />
					</div>
				<?php } ?>
			</div>

			<?php foreach ($repeated_values as $value => $count) { ?>
				<?php if ($count > 0) { ?>
					<div>
						<span><?php echo $count; ?> mal eine <?php echo $value; ?></span>
						<img src="../img/dice<?php echo $value; ?>.jpg" />
					</div>
				<?php } ?>
			<?php } ?>
		<?php } ?>
	<?php } ?>
</body>
</html>

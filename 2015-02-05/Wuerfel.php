<?php
define('N_DICES', '5');
$values = array();
$repeated_values = array(
	1 => 0,
	2 => 0,
	3 => 0,
	4 => 0,
	5 => 0,
	6 => 0,
);

for ($dice = 0; $dice < N_DICES; $dice++) {
	$random_number = rand(1, 6);
	array_push($values, $random_number);
	$repeated_values[$random_number]++;
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
</body>
</html>

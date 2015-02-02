<?php
	require_once('functions.php');
?>

<!DOCTYPE html>
<html lang="de">
<head>
	<meta charset="UTF-8">
	<title>PHP-Übung</title>

	<link rel="stylesheet" href="Zahlenausgabe_Tabelle.css">
</head>
<body>

	<table>
		<tr>
	<?php
		$count_prime_numbers = 0;

		for ($i = 1, $number = 29; $i <= 100; $i++, $number++) {
			$class = '';

			if (is_prime($number)) {
				$class = 'class="blue"';
				$count_prime_numbers++;
			}

			echo ' <td ' . $class . '>' . $number . '</td>';

			if ($i % 10 == 0) {
				echo '</tr><tr>';
			}
		}
	?>
		</tr>
	</table>

	<div class="blue"></div>
	<?php echo $count_prime_numbers; ?> Primzahlen

</body>
</html>

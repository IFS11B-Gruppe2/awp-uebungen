<?php
	require_once('functions.php');
	define('FIRST_NUMBER', 71);
	define('N_CELLS', 100)
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

		for ($i = 1, $number = FIRST_NUMBER; $i <= N_CELLS; $i++, $number++) {
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

<?php
	require_once('functions.php');
	define('FIRST_NUMBER', 71);
	define('N_CELLS', 100);
	define('COLUMNS', 10);
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
				$count_prime_numbers++;
				$class = 'blue';
			}

			echo ' <td class="' . $class . '">' . $number . '</td>';

			if ($i % COLUMNS == 0) {
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

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
		for ($i = 1, $number = 29; $i <= 100; $i++, $number++) {
			$class = '';

			if (is_prime($number)) {
				$class = 'class="blue"';
			}

			echo ' <td ' . $class . '>' . $number . '</td>';

			if ($i % 10 == 0) {
				echo '</tr><tr>';
			}
		}
	?>
		</tr>
	</table>

</body>
</html>

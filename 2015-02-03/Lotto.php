<?php
$recommended = array();
for ($i = 0; $i < 6; $i++) {
	$recommended[$i] = rand(1, 49);
}
?>
<!DOCTYPE html>
<html lang="de">
<head>
	<meta charset="UTF-8">
	<title>Lotto</title>

	<link rel="stylesheet" type="text/css" href="Lotto.css">
</head>
<body>
	<h1>Lottoschein - Normal</h1>

	<table>
		<tbody>
			<?php for ($row = 0, $number = 1; $row < 7; $row++) { ?>
			<tr>
				<?php for ($cell = 0; $cell < 7; $cell++, $number++) { ?>
				<?php
					if (in_array($number, $recommended)) {
						$class = 'recommended';
					} else {
						$class = '';
					}
				?>
				<td>
					<span class="<?php echo $class; ?>">
						<?php echo $number; ?>
					</span>
				</td>
				<?php } ?>
			</tr>
			<?php } ?>
		</tbody>
	</table>
</body>
</html>

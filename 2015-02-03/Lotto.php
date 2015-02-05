<?php
$recommended = array();
for ($game_row = 0; $game_row < 6; $game_row++) {
	$recommended[$game_row] = array();

	for ($game_column = 0; $game_column < 2; $game_column++) {
		$recommended[$game_row][$game_column] = array();
		for ($i = 0; $i < 6; $i++) {
			do {
				$random = rand(1, 49);
			} while (in_array($random, $recommended[$game_row][$game_column]));

			$recommended[$game_row][$game_column][$i] = $random;
		}
	}
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

	<?php
	for ($game_row = 0; $game_row < 6; $game_row++) {
		for ($game_column = 0; $game_column < 2; $game_column++) {
			?>
			<table>
				<tbody>
					<?php for ($row = 0, $number = 1; $row < 7; $row++) { ?>
					<tr>
						<?php for ($cell = 0; $cell < 7; $cell++, $number++) { ?>
						<?php
							if (in_array($number, $recommended[$game_row][$game_column])) {
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
			<?php
		}
	}
	?>
</body>
</html>

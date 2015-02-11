<?php session_start(); ?>
<?php

if (!isset($_SESSION['recommended'])) {
	$_SESSION['recommended'] = array();

	for ($i = 0; $i < 6; $i++) {
		do {
			$random = rand(1, 49);
		} while (in_array($random, $_SESSION['recommended']));

		$_SESSION['recommended'][$i] = $random;
	}
}
?>
<!DOCTYPE html>
<html lang="de">
<head>
	<meta charset="UTF-8">
	<title>Lottoschein - Session</title>

	<link rel="stylesheet" type="text/css" href="../2015-02-03/Lotto.css">
</head>
<body>
	<h1>Lottoschein - Session</h1>

	<table>
		<tbody>
			<?php for ($row = 0, $number = 1; $row < 7; $row++) { ?>
				<tr>
					<?php for ($cell = 0; $cell < 7; $cell++, $number++) { ?>
						<?php
							$class = '';

							if (in_array($number, $_SESSION['recommended'])) {
								$class .= 'recommended ';
							}

							if (!empty($_POST['txtSelected']) and in_array($number, $_POST['txtSelected'])) {
								$class .= 'selected ';
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

	<form action="" method="post">
		<?php for ($selected_number = 0; $selected_number < 6; $selected_number++) { ?>
			<input type="text" name="txtSelected[]" value="<?php echo (!empty($_POST['txtSelected'])) ? $_POST['txtSelected'][$selected_number]: ''; ?>" />
		<?php } ?>

		<input type="submit" name="btnSend" value="Senden" />
	</form>
</body>
</html>

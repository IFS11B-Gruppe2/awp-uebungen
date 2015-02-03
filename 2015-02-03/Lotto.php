<!DOCTYPE html>
<html lang="de">
<head>
	<meta charset="UTF-8">
	<title>Lotto</title>
</head>
<body>
	<table>
		<tbody>
			<?php for ($row = 0, $number = 1; $row < 7; $row++) { ?>
			<tr>
				<?php for ($cell = 0; $cell < 7; $cell++, $number++) { ?>
				<td><?php echo $number; ?></td>
				<?php } ?>
			</tr>
			<?php } ?>
		</tbody>
	</table>
</body>
</html>

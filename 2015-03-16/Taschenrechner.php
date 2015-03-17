<?php
	session_start('calculator');

	if (isset($_POST['txtN1'])) {
		$txtN1 = $_POST['txtN1'];
	} else {
		$txtN1 = 0;
	}

	if (isset($_POST['txtN2'])) {
		$txtN2 = $_POST['txtN2'];
	} else {
		$txtN2 = 0;
	}

	if (isset($_POST['btnCalculate'])) {
		$result = $txtN1 + $txtN2;
	} else { // btnClearScreen action too
		$txtN1 = 0;
		$txtN2 = 0;
		$result = 0;
	}
?>
<!DOCTYPE html>
<html lang="de">
<head>
	<meta charset="UTF-8">
	<title>Taschenrechner</title>
	<link rel="stylesheet" type="text/css" href="Taschenrechner.css" />
</head>
<body>

<h1>Taschenrechner</h1>

<form method="POST">
	<table>
		<tbody>
			<tr>
				<td>Operand 1</td>

				<td>Operator</td>

				<td>Operand 2</td>

				<td> </td>

				<td>Ergebnis</td>
			</tr>

			<tr>
				<td>
					<input type="text" name="txtN1" value="<?php echo $txtN1; ?>" />
				</td>

				<td>+</td>

				<td>
					<input type="text" name="txtN2" value="<?php echo $txtN2; ?>" />
				</td>

				<td>=</td>

				<td>
					<input type="text" name="txtResult" value="<?php echo $result; ?>" />
				</td>
			</tr>

			<tr>
				<td colspan="5">
					<input type="submit" name="btnCalculate" value="Berechnen" class="wide" />

					<input type="submit" name="btnClearScreen" value="C" class="wide" />

					<input type="submit" name="btnSaveValue" value="M+" class="wide" />

					<input type="submit" name="btnLoadValue" value="MR" class="wide" />
				</td>
			</tr>
		</tbody>
	</table>
</form>

</body>
</html>

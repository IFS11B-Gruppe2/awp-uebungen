<?php
	session_start('coffee_machine');

	$change = 0;

	if (!isset($_SESSION['credit'])) {
		$_SESSION['credit'] = 0;
	}

	$prices = array(
		'black_coffee' => .50,
		'milk_coffee' => .55,
		'sugar_coffee' => .55,
		'sugar_milk_coffee' => .60,
		'cappuccino' => .65,
		'latte_machiato' => .70
	);
?>
<!DOCTYPE html>
<html lang="de">
<head>
	<meta charset="UTF-8">
	<title>Kaffeautomat</title>
	<link rel="stylesheet" type="text/css" href="Kaffeeautomat.css">
</head>
<body>
	<h1>Kaffeeautomat</h1>

	<table>
		<tr>
			<td>
				<img src="" alt="">
			</td>

			<td>
				<table>
					<tr>
						<td>Kaffeeauswahl</td>

						<td>
							Geldeinwurf
							<br/>
							Ihr Guthaben <?php echo $_SESSION['credit']; ?> €
						</td>
					</tr>

					<tr>
						<td>
							<input type="submit" class="wide" name="btnBlackCoffee" value="Kaffee Schwarz <?php echo $prices['black_coffee']; ?> €" />
						</td>

						<td>
							<input type="submit" class="half-wide" name="btnInsert2euros" value="2 €" />
						</td>
					</tr>
					<tr>
						<td>
							<input type="submit" class="wide" name="btnMilkCoffee" value="Kaffee mit Milch <?php echo $prices['milk_coffee']; ?> €" />
						</td>

						<td>
							<input type="submit" class="half-wide" name="btnInsert1euro" value="1 €" />
						</td>
					</tr>
					<tr>
						<td>
							<input type="submit" class="wide" name="btnSugarCoffee" value="Kaffee mit Zucker <?php echo $prices['sugar_coffee']; ?> €" />
						</td>

						<td>
							<input type="submit" class="half-wide" name="btnInsert50cent" value="50 cent" />
						</td>
					</tr>
					<tr>
						<td>
							<input type="submit" class="wide" name="btnSugarMilkCoffee" value="Kaffee mit Milch &amp; Zucker <?php echo $prices['sugar_milk_coffee']; ?> €" />
						</td>

						<td>
							<input type="submit" class="half-wide" name="btnInsert20cent" value="20 cent" />
						</td>
					</tr>
					<tr>
						<td>
							<input type="submit" class="wide" name="btnCappuccino " value="Cappuccino <?php echo $prices['cappuccino']; ?> €" />
						</td>

						<td>
							<input type="submit" class="half-wide" name="btnInsert10cent" value="10 cent" />
						</td>
					</tr>
					<tr>
						<td>
							<input type="submit" class="wide" name="btnLatteMachiato" value="LatteMachiato <?php echo $prices['latte_machiato']; ?> €" />
						</td>

						<td>
							<input type="submit" class="half-wide" name="btnInsert5cent" value="5 cent" />
						</td>
					</tr>
					<tr>
						<td>
							<input type="submit" name="btnGetDrink" value="Getränkeausgabe" />
						</td>

						<td>
							Rückgeld
							<br/>
							<?php echo $change; ?>
						</td>
					</tr>
				</table>
			</td>
		</tr>
	</table>
</body>
</html>

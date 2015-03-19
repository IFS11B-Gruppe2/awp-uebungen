<?php
	session_start('coffee_machine');

	$change = 0;

	if (!isset($_SESSION['credit'])) {
		$_SESSION['credit'] = 0;
	}

	if (!isset($_SESSION['ordered'])) {
		$_SESSION['ordered'] = array(
			'black_coffee' => 0,
			'milk_coffee' => 0,
			'sugar_coffee' => 0,
			'sugar_milk_coffee' => 0,
			'cappuccino' => 0,
			'latte_machiato' => 0
		);
	}

	$prices = array(
		'black_coffee' => .50,
		'milk_coffee' => .55,
		'sugar_coffee' => .55,
		'sugar_milk_coffee' => .60,
		'cappuccino' => .65,
		'latte_machiato' => .70
	);

	if (isset($_POST['btnInsert2euro'])) {
		$_SESSION['credit'] += 2;
	}

	if (isset($_POST['btnInsert1euro'])) {
		$_SESSION['credit'] += 1;
	}

	if (isset($_POST['btnInsert50cent'])) {
		$_SESSION['credit'] += .50;
	}

	if (isset($_POST['btnInsert20cent'])) {
		$_SESSION['credit'] += .20;
	}

	if (isset($_POST['btnInsert10cent'])) {
		$_SESSION['credit'] += .10;
	}

	if (isset($_POST['btnInsert5cent'])) {
		$_SESSION['credit'] += .05;
	}

	if (isset($_POST['btnBlackCoffee'])) {
		$_SESSION['ordered']['black_coffee'] ++;
	}

	if (isset($_POST['btnMilkCoffee'])) {
		$_SESSION['ordered']['milk_coffee'] ++;
	}

	if (isset($_POST['btnSugarCoffee'])) {
		$_SESSION['ordered']['sugar_coffee'] ++;
	}

	if (isset($_POST['btnSugarMilkCoffee'])) {
		$_SESSION['ordered']['sugar_milk_coffee'] ++;
	}

	if (isset($_POST['btnCappuccino'])) {
		$_SESSION['ordered']['cappuccino'] ++;
	}

	if (isset($_POST['btnLatteMachiato'])) {
		$_SESSION['ordered']['latte_machiato'] ++;
	}

	if (isset($_POST['btnGetDrink'])) {
		$total_cost = 0;

		foreach($_SESSION['ordered'] as $name => $value) {
			$total_cost += $prices[$name] * $value;
		}

		if ($_SESSION['credit'] >= $total_cost) {
			$change = $_SESSION['credit'] - $total_cost;

			$_SESSION['credit'] = 0;

			foreach ($_SESSION['ordered'] as $key => $value) {
				$_SESSION['ordered'][$key] = 0;
			}
		} else {
			$error_message = 'Guthaben nicht genug!';
		}
	}
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

	<form action="" method="post">
		<table>
			<tr>
				<td>
					<img src="" alt="" />

					<?php
						$total_cost = 0;

						foreach($_SESSION['ordered'] as $name => $value) {
							$total_cost += $prices[$name] * $value;
							echo $name . ' ' . $value . "<br/>\n";
						}

						echo 'Gesamtsumme: ' . $total_cost;
					?>
				</td>

				<td>
					<table>
						<tr>
							<td>Kaffeeauswahl</td>

							<td>
								Geldeinwurf
								<br/>
								Ihr Guthaben <?php echo sprintf('%.2f', $_SESSION['credit']); ?> €
							</td>
						</tr>

						<tr>
							<td>
								<input type="submit" class="wide" name="btnBlackCoffee" value="Kaffee Schwarz <?php echo $prices['black_coffee']; ?> €" />
							</td>

							<td>
								<input type="submit" class="half-wide" name="btnInsert2euro" value="2 €" />
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

								<?php if (isset($error_message)) { ?>
									<div class="error">
										<?php echo $error_message; ?>
									</div>
								<?php } ?>
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
	</form>
</body>
</html>

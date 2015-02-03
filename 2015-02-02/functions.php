<?php

function is_prime($number) {
	$has_divisor = false;

	if ($number != 2) {
		for ($i = 2; $i < $number / 2 and $has_divisor == false; $i++) {
			if ($number % $i == 0) {
				$has_divisor = true;
			}
		}
	}

	# if it has a divisor, it is not a prime number.
	return !$has_divisor;
}

<?php

print_r($_POST);

$error_messages = '';
$info_messages = '';

if (empty($_POST['txtName'])) {
	$error_messages .= 'Name nicht eingegeben. <br/>';
} else {
	$info_messages .= 'Name: '.$_POST['txtName'].'<br/>';
}

if (empty($_POST['txtRoomNumber'])) {
	$error_messages .= 'Zimmernummer nicht eingegeben. <br/>';
} else {
	$info_messages .= 'Zimmernummer: '.$_POST['txtRoomNumber'].'<br/>';
}

if (
	!isset($_POST['chkCheese1'])
	and !isset($_POST['chkCheese2'])
	and !isset($_POST['chkCheese3'])
	and !isset($_POST['chkCheese4'])
) {
	$error_messages .= 'Käse nicht eingegeben. <br/>';
} else {
	$info_messages .= 'Gewunschte Käse: '.@$_POST['chkCheese1'].' '.@$_POST['chkCheese2'].' '.@$_POST['chkCheese3'].' '.@$_POST['chkCheese4'].' '.'<br/>';
}

if (!empty($_POST['txtOther'])) {
	$info_messages .= 'Weiteren Wunsch: '.$_POST['txtOther'].'<br/>';
}

$info_messages .= 'Zahlungswunsch: '.$_POST['cmbPaymentMode'];

echo '<p style="color: red;">'.$error_messages.'</p>';
echo '<p style="color: green;">'.$info_messages.'</p>';

?>

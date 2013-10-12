<?php

include 'header.php.inc'

# Open a file for reading

$fh = fopen ('addresses.txt', 'r');

?>

<h1>Mailing List</h1>

<u1>

<?php
$line = null;

while (($line = fgets($fh))) {
?>

  <li><?= $line ?></li>

<?php
}
?>

</u1>
<?php
fclose($fh);
include 'footer.php.inc';
?>

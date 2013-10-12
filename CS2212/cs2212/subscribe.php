<?php

include 'header.php.inc';

$email = $_POST['email'];
$database = "addresses.txt";

if ($email){
  # Open a file handle
  $fh = fopen($database, 'a') or die("<h1>Can't open file</h1>");

  #Write the email address to the file
  fwrite($fh, $email);

  #Write a new line to the file
  fwrite($fh, "\n");;

  #Close the file
  fclose($fh);
?>
  
  <h1>Thank you</h1>

  <p><?= $email ?> has been added to my mailing list.</p>

<?php
}

else{

?>

  <h1>Error</h1>

  <p>Please enter your email address.</p>

<?php

}

include 'footer.php.inc';

?>

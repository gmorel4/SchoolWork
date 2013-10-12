<?php
  $selected_radio_button=$_POST['group1'];
  $dir=$_POST['dir'];
  $filename=$_POST['filename'];
  $text=$_POST['texttobeputinfile'];
  $file=$dir."/".$filename;
  if (!(is_dir($dir)))
  {
    echo "<p><h1>The directory $dir does not exist</h1>";
  }
  else if ($selected_radio_button == 'write')
  {
    file_put_contents($file,$text);
    echo '<p><h1>Success Writing to File</h1>';
  }
  else if ($selected_radio_button == 'read')
  {
    $readfromfile = file_get_contents($file);
    echo '<p><h1>Success when reading file</h1>';
    echo "<p><h1>File contained: $readfromfile</h1>";
  }
  else
  {
    echo "<p><h1>Something weird is going on, no file io!</h1></p>";
  }
?>

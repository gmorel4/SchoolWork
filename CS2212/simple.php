<?php
    $fname = $_POST['firstname'];
     $lname = $_POST['lastname'];
     echo("<applet code=FirstGUI.class width=400 height=400>");
     echo("<param name=\"first\" value=\"" . $fname . "\">" );
     echo("<param name=\"last\" value=\"" . $lname . "\">" );
     echo("</applet>");
?>
<html>
<body>
<?php

//the next 4 lines will bring the Facebook SDK in to your program and initialize it
       require ("facebook.php");
       define("FACEBOOK_APP_ID", '1410109409217912');
       define("FACEBOOK_SECRET_KEY", '3caad6eebb293019bce3881e4f70f06c');
       $facebook = new Facebook(array('appId' => FACEBOOK_APP_ID, 'secret' => FACEBOOK_SECRET_KEY));
       $uid = $facebook->getUser();
       if (!$uid)
              {$loginUrl = $facebook->getLoginUrl();
              //echo "<script type='text/javascript'>top.location.href = '$loginUrl';</script>";
              exit;
       }

       //$javaclass = new Java("friendSearch");

       echo ("<applet code=FriendSearch.class width=1000, height=2000>");
       try {$uid = $facebook->getUser();
              //print $uid; //this is the unique number that identifies a facebook user
              $user_profile = $facebook->api('/me','GET');
              //echo "<br>First Name: " . $user_profile['first_name'];
              $profilepic= "https://graph.facebook.com/" . $user_profile['id'] ."/picture?type=large";
              //echo "<p>URL Location of my facebook profile picture: " ;
              //echo $profilepic; 
              $headers = get_headers ($profilepic, 1);
              $url = $headers['Location'];
              echo($user_profile.','.$url.'\n');
              //echo "<p>URL location of my facebook profile picture if I need to get at the .jpg file:";
              //echo $url;
              //echo "<img src=\" $profilepic \"/>";
              //echo "<p>";
              $friends = $facebook->api('/me/friends',array('fields' => 'id,first_name')); 
              //echo '<ul>';
              //$file = "friendList.txt";
              //file_put_contents($friendList, " ");
              //<param name = "fileName"
              //value = $file />
              $getList = $_POST["getList"];
              if ($getList == "true"){
                foreach ($friends["data"] as $value) {
                            //echo '<li>';
                            //file_put_contents($file,$value["first_name"]."\n", FILE_APPEND | LOCK_EX);
                            //echo '</li>';
                  //$javaclass->addFriend($value['first_name'], $value['id']);
                  echo ($value['first_name'].','.$value['id'] + '\n');
                }

              }
              $friendToGet = null;
              while (true){
                $currentFriend = $_POST["friendId"];
                if ($currentFriend != $friendToGet){
                  $friendToGet = $currentFriend;
                  $friendPic = "https://graph.facebook.com/".$friendToGet."/picture?type=large";
                  echo ($friendPic.'\n');
                }
              }
              //echo '</ul>'; 
        } catch (FacebookApiException $e) {
              print "in error exception";
              echo ($e);
        }
?>
</body>
</html>
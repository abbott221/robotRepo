===============SET UP (ONE TIME THING)===============

//make github account

//put this on flashdrive: http://msysgit.github.io/

//On flash drive "Git" folder -> "Git Bash"

mkdir project

cd project

git init

git config --global user.name "abbott221"

git config --global user.email "abbottm07@gmail.com"

git remote add thisURL https://github.com/abbott221/robotRepo.git


===============BEFORE MAKING CHANGES===============

//delete everything in that project folder

//On flash drive "Git" folder -> "Git Bash"

cd project

//not working
//git pull thisURL master

git clone https://github.com/abbott221/robotRepo.git

//drag all that stuff in the folder into the corresponding QT Creator folder

//make changes

===============AFTER MAKING CHANGES===============

//drag all that stuff back into the folder on your flashdrive for replacements

//DO NOT HAVE THAT SECOND INTERNAL FOLDER THIS TIME, THAT MAY CAUSE ERRORS

//right click on a file and open the GUI
//OR via command

$git gui

"commit" on toolbar -> "Stage changed files to commit"

//CHECK THAT THE NEW LINEUP OF FILES DON'T CONTAIN A BUNCH OF RED X's NEXT TO THEM,

//THAT MEANS YOU STILL NEED TO DELETE THE SECOND INTERNAL FILE AS MENTIONED ABOVE

type a message for the commit


press "commit" button

then, remote ->  push to push code to the internet
//straight up "push" button oddly doesn't work

type your username and password

if failed to send,
$git pull thisURL master

then, press push button again






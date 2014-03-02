
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

git pull thisURL master

//drag all that stuff in the folder into the corresponding QT Creator folder
//make changes

===============AFTER MAKING CHANGES===============

//drag all that stuff back into the folder on your flashdrive for replacements

//right click on a file and open the GUI

"commit" on toolbar -> "Stage changed files to commit"
type a message for the commit
press "push" button to push the code to the internet
type your username and password

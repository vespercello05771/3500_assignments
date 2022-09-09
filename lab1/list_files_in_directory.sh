#!/bin/bash
#resource used:
#https://www.linuxquestions.org/questions/programming-9/find-command-return-true-if-a-file-was-found-881400/#:~:text=the%20find%20command%20will%20only,it%20find%20or%20not%20file.

echo "enter the name of the directory: "
read directory

paths=$(find /home -iname $directory ) 

if [ $(find /home -iname $directory | wc -m) -gt 0 ]
then
    for path in $paths      
    do
        echo $path
        ls $path| cut -f1 -d'/' 
    done
else
    echo "there is no such directory/file."
fi

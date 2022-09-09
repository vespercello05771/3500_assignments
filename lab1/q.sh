#! /bin/bash

read password
echo $password
criteria=(0 0 0)

if [[ $password =~ [a-z] ]]
then	
	 ((criteria[0]++)) 
fi
if [[ $password =~ [A-Z] ]]
then	(( criteria[1]++ ))
fi
if [[ $password =~ ['!@#$%^&*()_+'] ]]
then	(( criteria[2]++ ))
fi

strength=(0 0)
if [[ ${criteria[0]} -ge 1 && ${criteria[1]} -ge 1 && ${criteria[2]} -ge 1 ]]
then	(( strength[0]++ ))
fi
if [[ $password =~ [0-9] ]]
then	(( strength[1]++ ))
fi

if [[ ${strength[0]} == 1 && ${strength[1]} -ge 1 && ${#password} -ge 8 ]]
then	echo "STRONG PASSWORD"
elif [[ ${strength[0]} == 1 && ${#password} -ge 6 ]]
then	echo "MODERATE PASSWORD"
else
	echo "WEAK PASSWORD"
fi
#!/bin/bash

MergeSort (){

  local arr=("$@")

  if [ ${#arr[@]} -eq 1 ]
  then
    echo ${arr[@]}
  elif [ ${#arr[@]} -eq 2 ]
  then
    if [ ${arr[0]} -gt ${arr[1]} ]
    then
      echo ${arr[1]} ${arr[0]}
    else
      echo ${arr[@]}
    fi
  else

    local p=($(( ${#arr[@]} / 2 )))
    local m1=($(MergeSort "${arr[@]:0:p}"))
    local m2=($(MergeSort "${arr[@]:p}"))
    local ret=()

    while [ ${#m1[@]} -gt 0 ] && [ ${#m2[@]} -gt 0 ]; do
      if [ ${m1[0]} -gt ${m2[0]} ]; then
        ret+=(${m2[0]})
        m2=(${m2[@]:1})
      else
        ret+=(${m1[0]})
        m1=(${m1[@]:1})
      fi
    done
    echo ${ret[@]} ${m1[@]} ${m2[@]}
  fi
}
read -a arr
echo ${arr[@]}
b=($(MergeSort "${arr[@]}"))
echo "${b[@]:0}"


#source: https://stackoverflow.com/questions/62936852/merge-sort-recursive-algorithm-in-bash-cannot-exit-and-return-value
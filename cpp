#!/bin/bash

#0 for no repeat file 1 for yes
flag=0

#times 
t=0

#open file
firstopenfile="init.sh"

for argv in $*
do
  for file in `ls`
  do
    if [ ${file} = ${argv} ]; then
      echo -e "\n${argv} already exist!\n"
      flag=1
      break 1
    fi
  done

  if [ $flag -eq 0 ]; then
    t=`expr $t + 1`
    #the full name of the file usually +.cpp i must commit that use a less name if full
    ./cppinit ${argv} >> ${argv}

    if [ $t -eq 1 ]; then
      firstopenfile=$argv
    fi


  fi

  flag=0

done

vim $firstopenfile

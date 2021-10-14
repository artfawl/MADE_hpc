#!/bin/bash
myArr=(5 4 3 "word" "another" 11 7 -1 73 21 37 12)
for elem in ${myArr[@]}
do
  echo $elem
done

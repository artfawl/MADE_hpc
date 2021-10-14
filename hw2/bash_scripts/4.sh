#!/bin/bash

if [[ -d "Linux" ]]
then
  echo "course"
else
  echo "very easy"
  touch Linux
  echo "easy" >> ./Linux
fi

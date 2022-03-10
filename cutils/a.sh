#!/bin/bash


echo "compile $1"
file_c=$1
file_name=${file_c:0:-2}
gcc $1 -o $file_name

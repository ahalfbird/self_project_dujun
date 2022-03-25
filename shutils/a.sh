#!/bin/bash

#echo "compile a.c"
if [ -f "a" ]; then
rm -rf "a"
fi
gcc a.c -o a
echo "finish gen file"

pnum=$#

./a $@

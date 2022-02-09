#!/bin/bash

echo "this is a bash sh to generate file"


:<<!
following the steps:
1 create ten dir and rename with Arabic figures.
2 create ten dir in last dir and rename __sprite.
3 create ten 1.png and move in __spite.
!

rm -rf test
mkdir test
cd test
for i in $(seq 1 10);
do
mkdir "$i"
cd "$i"
mkdir "__sprite"
cd ..
done

for i in $(seq 1 10);
do
cd "$i/__sprite"
echo -e "$i\n" > "1.png"
cd ../..
done
cd ..

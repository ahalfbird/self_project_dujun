#!/bin/bash

### This file is compress a file in multiple times and password.
### 
### 
### 
### 
### 

rm -rf *.zip
FILEPATH=
CTIMES=
PASSWORD=

if [  $# == 3 ]
then 
    FILEPATH=$1
	CTIMES=$2
	PASSWORD=$3
fi
if [  $# == 2 ]
then 
    FILEPATH=$1
	CTIMES=$2
	PASSWORD=123456
fi
if [  $# == 1 ]
then 
    FILEPATH=$1
	CTIMES=1
	PASSWORD=123456
fi


TMPPATH=$FILEPATH
TMPTIMES=$CTIMES

cp $FILEPATH $FILEPATH-tmp

while (($TMPTIMES>0))
do
	zip -rm tmp.zip $TMPPATH -P $PASSWORD
	((TMPTIMES--))
	mv tmp.zip $FILEPATH.zip
	TMPPATH=$FILEPATH.zip
done

mv $FILEPATH-tmp $FILEPATH
mv $FILEPATH.zip $FILEPATH-target.zip

echo "compress $1 to $1-target.zip ok"

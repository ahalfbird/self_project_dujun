#!/bin/bash

echo "this is a bash sh to generate UNPAK file"


UNPAK_FILE=
UNPAK_FILE_NAME=
UNPAK_TARGET_DIR=
if [[ $# == 0 ]]
then
echo "please enter name of file"
exit 0
fi

if [[ $# == 1 ]]
then
UNPAK_FILE=$1
UNPAK_FILE_NAME=$(echo "${FILE%%.*}")
UNPAK_FILE_TYPE=$(echo "${FILE#*.}")
UNPAK_TARGET_DIR=temp_unpak
else

if [[ $# == 2 ]]
then
UNPAK_FILE=$1
UNPAK_FILE_NAME=$(echo "${FILE%%.*}")
UNPAK_FILE_TYPE=$(echo "${FILE#*.}")
UNPAK_TARGET_DIR=$2
fi
fi
rm -rf ${UNPAK_TARGET_DIR}
mkdir -p ${UNPAK_TARGET_DIR}

case $UNPAK_FILE_TYPE in
".zip")
UNPAK ${UNPAK_FILE} ${UNPAK_TARGET_DIR}
;;
".rar")
unrar x ${UNPAK_FILE} ${UNPAK_TARGET_DIR}
;;
".tar")
tar -xvf ${UNPAK_FILE} -C ${UNPAK_TARGET_DIR}
;;
".tar.gz")
tar -xzvf ${UNPAK_FILE} -C ${UNPAK_TARGET_DIR}
;;
".tar.Z")
tar -xZvf ${UNPAK_FILE} -C ${UNPAK_TARGET_DIR}
;;
".tar.bz2")
tar -xjvf ${UNPAK_FILE} -C ${UNPAK_TARGET_DIR}
;;
*)
echo "cant parse file name"
;;
esac






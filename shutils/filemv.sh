#!/bin/bash

echo "this is a bash sh to copy file"

if [[ $# != 3 ]]
then
echo "please enter source file target file and dir"
exit 0
fi

FILEMV_SOURCE_FILE_NAME="$1"
FILEMV_TARGET_FILE_NAME="$2"
FILEMV_DIR="$3"


if [[ "${FILEMV_SOURCE_FILE_NAME:0:1}" == "*" ]]
then 
FILEMV_SOURCE_FILE_NAME="${FILEMV_SOURCE_FILE_NAME:1}"
fi


if [[ "${FILEMV_TARGET_FILE_NAME:0:1}" == "*" ]]
then 
FILEMV_TARGET_FILE_NAME="${FILEMV_TARGET_FILE_NAME:1}"
fi


#echo "FILEMV_SOURCE_FILE_NAME=${FILEMV_SOURCE_FILE_NAME}  FILEMV_TARGET_FILE_NAME=${FILEMV_TARGET_FILE_NAME}"
#echo "dir : ${FILEMV_DIR}   last char : ${FILEMV_DIR:${#FILEMV_DIR}-1}"

for file in $(find $FILEMV_DIR -name "*$FILEMV_SOURCE_FILE_NAME")
do
FILE_TEMP_NAME=$file
if [ -f "$file" ]
then
echo "${file} ==> ${file/%$FILEMV_SOURCE_FILE_NAME/$FILEMV_TARGET_FILE_NAME}"
mv ${file} ${file/%$FILEMV_SOURCE_FILE_NAME/$FILEMV_TARGET_FILE_NAME}
fi

done

ls $FILEMV_DIR


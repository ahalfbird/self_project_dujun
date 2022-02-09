#!/bin/bash

echo "this is a bash sh to clear edk2 compile path"

TEMP_DIR_NOW=$(pwd)
OPERATE_DIR_ROOT=

if [ $# = 0 ]
then
OPERATE_DIR_ROOT=$(pwd)
echo "operate dir is here"
else 
if [ $# = 1 ]
then
OPERATE_DIR_ROOT=$1
fi
fi

cd "$OPERATE_DIR_ROOT"
echo "step in work dir"

cd bootable/bootloader/edk2
echo "edk path now is as following:"
(bash edksetup.sh)

echo "start to clean edk path envirnoment"
rm -rf Conf/BuildEnv.sh
unset EDK_TOOLS_PATH
(bash ./edksetup.sh BaseTools)
echo "finish to clean edk path envirnoment"

cd "$TEMP_DIR_NOW"
echo "return origin dir"
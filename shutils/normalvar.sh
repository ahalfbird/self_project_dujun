#!/bin/bash

echo "this is a bash sh to save var"


#used by goremotedir.sh
REMOTE_SERVER=118
PASSWORD_NORMAL="123456"
REMOTE_SERVER_NORMAL="dujun@192.168.0.118 wangzhiwen@192.168.0.100 build3@192.168.0.51"

#judge is s1 contain or not
function judgeContainSubStr()
{
# $1 is base str
# $2 is sub str
s1=$1
s2=$2
result=$(echo "$1" | grep "$2")
if [[ "$result" == "" ]]
then 
#echo "${s1} not include $s2"
echo "-1"
else 
#echo "${s1} include $s2"
tmpstr="${s1%%$s2*}"
echo "${#s1}"
fi
}
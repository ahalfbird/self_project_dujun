#!/bin/bash

echo "this is a bash sh to go to remote server"

source normalvar.sh

if [[ $# == 0 ]]
then
echo "please enter server address"
exit 0
fi

if [[ $# == 1 ]]
then
REMOTE_SERVER=$1
#echo "server address is $REMOTE_SERVER"

IS_INCLUDE=$(judgeContainSubStr "$REMOTE_SERVER_NORMAL" "$REMOTE_SERVER")

if [[ $IS_INCLUDE == "-1" ]]
then
echo "cant find this server"
exit 0
fi

echo "IS_INCLUDE=$IS_INCLUDE"

REMOTE_SERVER_ALLNAME=

for arr_ss1 in $REMOTE_SERVER_NORMAL
do
IS_INCLUDE_TEMP=`judgeContainSubStr "$arr_ss1" "$REMOTE_SERVER"`
echo "this server $arr_ss1, IS_INCLUDE_TEMP=$IS_INCLUDE_TEMP"
   if [[ $IS_INCLUDE_TEMP != "-1" ]]
   then
   REMOTE_SERVER_ALLNAME=$arr_ss1
   break
   fi
done

echo "REMOTE_SERVER_ALLNAME = $REMOTE_SERVER_ALLNAME"
if [[ $REMOTE_SERVER_ALLNAME == "" ]]
then
echo "this server name is null"
exit 0
fi

echo "ssh connect $REMOTE_SERVER_ALLNAME"
sshpass -p $PASSWORD_NORMAL ssh $REMOTE_SERVER_ALLNAME

fi



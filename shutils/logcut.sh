#!/bin/bash

echo "this is a bash to cut log"


OPERATE_FILE_NAME=$1
TARGET_FILE_NAME="$OPERATE_FILE_NAME-tgf"

if [ ! -f "$OPERATE_FILE_NAME" ]
then
echo "$OPERATE_FILE_NAME does not exist"
exit 0
fi

if [ ! -f "$TARGET_FILE_NAME" ]
then
touch $TARGET_FILE_NAME
else 
rm -rf $TARGET_FILE_NAME
touch $TARGET_FILE_NAME
fi


function findSubStrPosition()
{
# $1 is base str
# $2 is sub str

s1=$1
s2=$2
tmppos=
result=$(echo "$1" | grep "$2")
if [[ "$result" == "" ]]
then 
#echo "$s1 not include $s2"
echo "-1"
else 
#echo "$s1 include $s2"
tmpstr="${s1%%$s2*}"
tmppos=`expr ${#tmpstr} + 1`
fi
echo $tmppos
}

function findsubstr()
{
str_base=$1
str_sub=$2
times_str=$3
str_pos="0"

tmptimes=0
tmp_str=$str_base
tmp_pos=0
while ((tmptimes<times_str))
do

tmp_pos=$(findSubStrPosition "$tmp_str" "$str_sub")

if [[ $tmp_pos != "-1" ]]
then
tmp_str=${tmp_str:$tmp_pos}

else
#echo "cannot fild enough $2 from $1, this just has $tmptimes substr"
str_pos="-1"
break
fi
#echo "tmp_str=$tmp_str  |  tmp_pos=$tmp_pos  |  tmptimes=$tmptimes"
((tmptimes++))
done

if [[ $str_pos == "-1" ]]
then
str_pos="-1"
else
str_pos=$(expr ${#str_base} - ${#tmp_str} + 18 )
fi
echo "$str_pos"
}

function newreplacefilelog()
{
times_file_line=0
while read line
do
tmpstr=$line
tmppos=$(findsubstr "$line" ":" 2)
if [[ $tmppos == "-1" ]]
then
tmppos="0"
fi
#echo "tmppos=$tmppos  times_file_line=$times_file_line"
echo ${line:$tmppos} >> $TARGET_FILE_NAME
((times_file_line++))
done < $OPERATE_FILE_NAME
echo "cut log ok"
}

newreplacefilelog


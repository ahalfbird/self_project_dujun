#!/bin/bash
#echo -e "\n\n\n"

:<<!

This is a script to generate dtsi structure.

The first parsm is the prefix of the project(dtsi).For example,
the SNM951 uses kona dts, so the first parsm is kona.This parsm is 
essential.

The second parsm is the directory of dtsi.If you dont input the parsm, this script will fill it with 'vendor/qcom/proprietary/devicetree-4.19/qcom'.

If the number of parsms is less than one or more than three, it will be exited. 

!



#kona lito bengal...
opeproj=
opedir=vendor/qcom/proprietary/devicetree-4.19/qcom
tmpstr=
tmpfilename=
TMPLOCALDIR=`pwd`

function newtmpfile()
{
if [ ! -f "$tmpfilename" ]; then
:
else 
rm -rf $tmpfilename
rm -rf $tmpfilename.bak
fi
touch $tmpfilename
}

if [[ $# -lt 1 ]]
then 
echo "parsm isnot enough to continue"
exit 0
fi

if [[ $# == 1 ]]
then 
opeproj=$1

else 
if [[ $# == 2 ]]
then 
opeproj=$1
opedir=$2

else if [[ $# -gt 2 ]]
then 
echo "parsm out of list len"
exit 0
fi
fi
fi

#echo "opeproj=$opeproj,opedir=$opedir"

#step into opedir
cd "$opedir"

#step1  get the include str
tmpstr=`grep -r "include" $opeproj*`
#echo "$tmpstr"
cd $TMPLOCALDIR
tmpfilename="get-include"
newtmpfile
 
 echo "$tmpstr" > "$tmpfilename"
cp "$tmpfilename" "$tmpfilename".bak
#echo "$tmpfilename"


#step2  rm include<...>
function rm_include()
{
times_file_line=0
tmpfilename="rm-leftright"
newtmpfile
while read line
do
tmpstr=$line

result=$(echo $line | grep -e "<" -e ">" -e "//")
if [[ "$result" != "" ]]
then
#    echo "$times_file_line:$result"
:
else
    echo $line >> $tmpfilename
fi

((times_file_line++))
done < get-include.bak

cp $tmpfilename $tmpfilename.bak
}
rm_include

#step3  merge common head
function merge_head()
{
times_file_line=0
tmpfilename="merge_head"
newtmpfile
tmphead=
lasthead=
while read line
do

if [[ $times_file_line == 0 ]];then
tmpstr=$line
lasthead=${tmpstr%%:*}
echo ${tmpstr%%:*} >> $tmpfilename
echo "${tmpstr##*:}" >> $tmpfilename
((times_file_line++))
continue
fi

tmpstr=$line
tmphead=${tmpstr%%:*}

if [[ $tmphead == $lasthead ]];then
echo "${tmpstr##*:}" >> $tmpfilename
#echo -e "[$times_file_line]    ${tmpstr##*:}"
else
echo "$tmphead" >> $tmpfilename
echo "${tmpstr##*:}" >> $tmpfilename
#echo -e "[$times_file_line]    $tmphead"
lasthead=$tmphead
fi

((times_file_line++))
done < rm-leftright.bak

cp $tmpfilename $tmpfilename.bak
}
merge_head


#step4  del include and add tab 

tmpfilename="del_include"
newtmpfile
cp merge_head $tmpfilename
sed -i 's/#include/\t/g' $tmpfilename

cp $tmpfilename $tmpfilename.bak

#step5 del tmp file
tmpfile="get-include merge_head rm-leftright.bak 
del-include del-include.bak get-include.bak merge_head.bak  rm-leftright
"
rm -rf $tmpfile
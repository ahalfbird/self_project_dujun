#!/bin/bash

echo "this is a bash sh to generate copy file"

AUTOSCP_SOURCE_FILE=
AUTOSCP_TARGET_FILE=

if [[ $# -lt 2 ]]
then 
echo "parsm isnot enough to continue"
exit 0
fi

if [[ $# == 2 ]]
then 
AUTOSCP_SOURCE_FILE=${1}
AUTOSCP_TARGET_FILE=${2}

/usr/bin/expect << EOF
        spawn scp -r "$AUTOSCP_SOURCE_FILE" "$AUTOSCP_TARGET_FILE"
        expect {
            "*password:" {send "123456\\r"}
        }
        expect eof
		exit
EOF

exit 0
fi

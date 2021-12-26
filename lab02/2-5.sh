#!/usr/bin/bash

HOUR=`date +%H`                 # date [OPTION]... [+FORMAT]
                                # %H: hour (00..23)

if (($HOUR <= 12))
then
    printf "Good morning\n"
elif (($HOUR <= 17))
then
    printf "Good afternoon\n"
else
    printf "Good night\n"
fi
exit 0
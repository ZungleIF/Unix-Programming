#!/usr/bin/bash

echo -n "Is it morning?"
read answer     # Reads an input from user
case $answer in 
    # If the answer starts with y or Y
    y* | Y* ) echo Good morning ;;             
    # If the answer starts with n or N
    n* | N* ) echo Have a good day ;;
    # Default case
    *) echo Sorry your answer is not proper ;;
esac
exit 0
#!/usr/bin/bash
echo number of argument is $#   # $#: the number of arguments
echo arguments are $*           # $*: every argements
echo command is $0              # $0: the first argument
echo first argument is $1
shift                           # shifts arguments to right by 1
echo number of argument is $#   
echo arguments are $*            
echo command is $0              
echo first argument is $1

exit 0
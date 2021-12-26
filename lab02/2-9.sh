#!/usr/bin/bash

# Defines a function called sum. Returns the sum value of two integers.
sum(){
    ((sum = $1 + $2))
    return $sum
}

sum 10 20
echo The result is $?   # The return value of sum is stored in $?

exit 0
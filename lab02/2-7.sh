#!/usr/bin/bash
i=2
j=1
while (( i <= 9 ))
do
    while (( j <= 9 ))
    do
        printf "%3d" $(( i * j ))
        ((j += 1 ))
    done
    echo 
    (( i += 1 ))
    ((j = 1))
done
exit 0
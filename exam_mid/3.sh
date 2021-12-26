#!/usr/bin/bash
# Define local env variables.
i=0
j=1
k=0
# Start of while-loop.
# Basically, prints Fibonacci Sequence.
while ((i < 100))
do
    echo $i         # Prints i.
    ((k = i + j))   # Needs (()) for arithmetic operations.
    ((i = j))
    ((j = k))
done
# End of while-loop.
exit 0
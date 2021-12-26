#!/usr/bin/bash

var=defined
echo $var                   # Print var to stdout.
echo ${var:-default}        # If var is not defined, print "default".
echo ${var1:-default}       # If var1 is not defined, print "default".
echo $var1                  # Print var1.
echo ${var:=string}         # If var is not defined, generate a variable called var,
                            # and initialize it with "string".
echo $var1                  
echo ${var:+new}            # If var is defined, print "new".
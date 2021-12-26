#!/bin/bash

make server client
./server &
ps
sleep 0.5
./client

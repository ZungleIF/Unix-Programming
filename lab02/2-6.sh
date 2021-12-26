#!/usr/bin/bash
for DIR in $(ls ~)      # for loop for directory list in ~/
do
    if [[ -d ~/$DIR ]]  # if it is a directory,
    then
        ls -R ~/$DIR    # print directory list recursively in it.
    fi
done
exit 0
#! /bin/bash

for file in $(ls f*.sh); do
    cat $file
done
exit 0

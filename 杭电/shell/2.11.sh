#! /bin/bash
if test $# -eq 0
then
    echo "please"
else
    gzip $1
    mv $1.gz $HOME/dustbin
    echo "deleted!"
fi
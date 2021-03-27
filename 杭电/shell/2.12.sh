#! /bin/bash
# -dir 目录 -file 文件; then
echo $(psw)
echo "please"
read DORF
if [ -d $DORF ]; then
    ls $DORF
elif [ -f $DORF ]; then
    cat $DORF
else
    echo "input"
fi

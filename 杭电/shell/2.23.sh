#! /bin/bash
until who -a | grep "$1" > /dev/aa
do
sleep 60
done
echo -e \\a
echo "$1 has just logged in"
exit 0
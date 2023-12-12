#!/bin/sh

if [ $# -ne 1 ]; then
    echo "Need a day's number" && exit 0
fi

day="day$1"
if [ -e "$day" ]; then
    echo "This day already exist" && exit 1
fi

mkdir "$day"
aoc d -I -d "$1" -i "$day/input" || exit 1
cp Makefile "$day"
cp main.c "$day"
sed -i "s/day.*$/$day/" "$day/Makefile"

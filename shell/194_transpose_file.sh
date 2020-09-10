#!/bin/sh

col=`head -n1 file_194.txt | wc -w`

for i in `seq 1 $col`
do
    echo `cut -d' ' -f$i file_194.txt`
done

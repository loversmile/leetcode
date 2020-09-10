#!/bin/sh
awk 'NR==10' file_195.txt
sed -n 10p file_195.txt 
tail -n+10 file_195.txt | head -1

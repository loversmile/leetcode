#!/bin/bash
cat words_192.txt | egrep -o "[a-z]{1,}?" | sort | uniq -c | sort -g -r | awk -F ' ' '{print $2,$1}' OFS=' '

#!/bin/sh

NOW=$(date +%s)
COO=$(stat coord.txt -c %X)
SUB=$((NOW-COO))
if [ "$SUB" -gt "60" ]; then
  rm -rf coord.txt
  . ./get_coord.sh >> coord.txt
fi

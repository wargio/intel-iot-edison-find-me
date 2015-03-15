#!/bin/sh

NOW=$(date +%s)
COO=$(stat coord.txt -c %X)
SUB=$((NOW-COO))
MAX=8


if [ "$SUB" -gt "$MAX" ]; then
  rm -rf coord.txt
  . ./get_coord.sh >> coord.txt
else
  ./lcd "#intelMaker" "wait "$((MAX-SUB))
fi

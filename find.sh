#!/bin/sh
DATA=$(. ./get_wifi.sh  | grep -E "$1|$2|$3")
MAC=""
FRQ=""
i=0
for D in $DATA
do
  k=$((i%3))
  if [ "$k" -eq "0" ]; then
    MAC=$D
  elif [ "$k" -eq "1" ]; then
    FRQ=$D
  else
    # Hack on that bad router
    if [ "$MAC" == "00:22:6B:F6:79:AF" ]; then
        D=$((D-10))
    fi
    echo $MAC $(./suDai "$FRQ" "$D")
  fi
  i=$((i+1)) 
done



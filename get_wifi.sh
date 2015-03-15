#!/bin/sh
i=0
MAC=""
FREQ=""
DB=""
./lcd "#intelMaker" "Scanning WiFi"
iwlist wlan0 scan | grep -E "Address|Signal|Frequency" >> tmp.txt
while read line;
do
    k=$((i%3))
    if [ "$k" -eq "0" ]; then
      #MAC
      MAC=$(echo $line | cut -d ' ' -f5)
    elif [ "$k" -eq "1" ]; then
      #Freq
      FREQ=$(echo $line | cut -d ':' -f2 | cut -d ' ' -f1)
    else
      #Sign
      DB=$(echo $line | cut -d '=' -f3 | cut -d ' ' -f1)

      echo "$MAC $FREQ $DB"
    fi
    i=$((i+1))
done < tmp.txt
  rm tmp.txt


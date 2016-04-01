#!/bin/bash

./ITGSend -poll -m rttm -T UDP -a 50.50.50.4 -c 64   -C 14880 -t 60000 -l sender64.log
./ITGSend -poll -m rttm -T UDP -a 50.50.50.4 -c 128  -C  8445 -t 60000 -l sender128.log
./ITGSend -poll -m rttm -T UDP -a 50.50.50.4 -c 256  -C  4528 -t 60000 -l sender256.log
./ITGSend -poll -m rttm -T UDP -a 50.50.50.4 -c 512  -C  2349 -t 60000 -l sender512.log
./ITGSend -poll -m rttm -T UDP -a 50.50.50.4 -c 768  -C  1586 -t 60000 -l sender768.log
./ITGSend -poll -m rttm -T UDP -a 50.50.50.4 -c 1024 -C  1197 -t 60000 -l sender1024.log
./ITGSend -poll -m rttm -T UDP -a 50.50.50.4 -c 1280 -C   961 -t 60000 -l sender1280.log
./ITGSend -poll -m rttm -T UDP -a 50.50.50.4 -c 1518 -C   812 -t 60000 -l sender1518.log

./ITGDec   sender64.log >   c64.txt
./ITGDec  sender128.log >  c128.txt
./ITGDec  sender256.log >  c256.txt
./ITGDec  sender512.log >  c512.txt
./ITGDec  sender768.log >  c768.txt
./ITGDec sender1024.log > c1024.txt
./ITGDec sender1280.log > c1280.txt
./ITGDec sender1518.log > c1518.txt

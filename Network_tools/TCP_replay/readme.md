
#How to use tcpprep, tcprewrite & tcpreplay - simple examples
##Case 1:
```
+---------+             +---------+ 
|   src   |<----------->|   dst   |
+---------+             +---------+
```

1.  `tcpprep --auto=client --pcap=getall.pcap --cachefile=input.cache`

2.  `sudo tcprewrite --enet-smac=[src.MAC] --enet-dmac=[dst.MAC] --endpoints=[src.IP]:[dst.IP] --skipbroadcast --cachefile=input.cache -i getall.pcap -o output.pcap`
    * example:
      *sudo tcprewrite --enet-smac=FA:16:3E:CA:EA:2E --enet-dmac=FA:16:3E:13:26:B6 --endpoints=172.4.4.8:172.4.4.13 --skipbroadcast --cachefile=input.cache -i getall.pcap -o output.pcap*

3.  `sudo tcpreplay -i eth0 --loop=0 output.pcap    # --loop=0 to send continuously`<br>
    `sudo tcpreplay -i eth0 --loop=0 -t output.pcap # -t or --topspeed to replay packets as fast as possible`
    

##Case 2:
```
+---------+             +---------+             +---------+ 
|   src   |<----------->|   gtw   |<----------->|   dst   |
+---------+             +---------+             +---------+
```

1.  // see case 1...
2.  `sudo tcprewrite --enet-smac=[src.MAC] --enet-dmac=[gtw.MAC] --endpoints=[src.IP]:[dst.IP] --skipbroadcast --cachefile=input.cache -i getall.pcap -o output.pcap`
3.  // see case 1...

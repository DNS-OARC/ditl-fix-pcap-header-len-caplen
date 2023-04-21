# ditl-fix-pcap-header-len-caplen

Quick hack to fix `len` and `caplen` in `pcap_pkthdr` for PCAPs generated
by `tcpdump` with the bug [libpcap version 1.5.3 causes the creation of invalid pcap files with packet length < capture length when capturing on the "any" interface](https://github.com/the-tcpdump-group/libpcap/issues/1071).

Usage:
```
cat file.pcap | ditl-fix-pcap-header-len-caplen > fixed.pcap
```

You can pipeline compression also:
```
gzip -cd file.pcap.gz | ditl-fix-pcap-header-len-caplen | gzip > fixed.pcap.gz
```

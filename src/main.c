#include <pcap/pcap.h>
#include <stdio.h>

int main(void) {
    char errbuf[PCAP_ERRBUF_SIZE] = {0};

    pcap_t* in = pcap_fopen_offline(stdin, errbuf);
    if (!in) {
        fprintf(stderr, "pcap_fopen_offline(stdin): %s\n", errbuf);
        return 1;
    }
    pcap_t* out = pcap_open_dead(pcap_datalink(in), pcap_snapshot(in));
    if (!out) {
        fprintf(stderr, "pcap_open_dead() failed\n");
        return 1;
    }
    pcap_dumper_t* dumper = pcap_dump_fopen(out, stdout);
    if (!dumper) {
        pcap_perror(out, "pcap_dump_fopen(): ");
        return 1;
    }

    for (;;) {
        struct pcap_pkthdr* h;
        const u_char* d;
        int ret = pcap_next_ex(in, &h, &d);
        if (ret == PCAP_ERROR) {
            pcap_perror(in, "pcap_next_ex(): ");
            return 1;
        } else if (ret == PCAP_ERROR_BREAK) {
            break;
        }

        if (h->caplen > h->len) {
            h->caplen = h->len;
        }
        pcap_dump((void*)dumper, h, d);
    }

    pcap_dump_close(dumper);
    pcap_close(out);
    pcap_close(in);

    return 0;
}
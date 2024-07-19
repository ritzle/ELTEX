#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdint.h> 
#include <stdbool.h>

#define IPV4 4

#define LEN_IPV4 16

void parserIP(int arr[], char inputStr[]) {
    char *token;
    char delim[] = ".";
    int i = 0;

    token = strtok(inputStr, delim);
    while (token != NULL) {
        arr[i] = atoi(token);
        token = strtok(NULL, delim);
        i++;
    }
}

int32_t randIP() {
    int32_t IP = 0;
    for (int i = 0; i < IPV4; i++) { 
        IP |= (rand() % 256) << (8 * (IPV4 - 1 - i));
    }
    return IP;
}

int32_t bytesToIP(int mas[]) {
    int32_t ip = 0;
    for (int i = 0; i < IPV4; i++) { 
        ip |= (int32_t)mas[i] << (8 * (IPV4 - 1 - i));
    }
    return ip;
}

bool analyzeIPNetwork(int32_t ipAddress, int32_t subnetMask, int32_t networkPrefix) {
    int32_t networkAddress = ipAddress & subnetMask;
    int32_t networkPrefixAddress = ipAddress & networkPrefix;

    return networkAddress == networkPrefixAddress;
}

int main() {
    srandom(time(NULL));
    
    int nPacet;
    printf("Ввидите количсетво сгенерированных IP: ");
    scanf("%d",&nPacet);

    printf("enter IP maska(XXX.XXX.XXX.XXX): ");
    char IpMaska[LEN_IPV4];
    scanf("%s", IpMaska);

    int ParIpMaskaMas[IPV4]; // Уже разбитая маска в массив
    parserIP(ParIpMaskaMas, IpMaska);

    int32_t dIpMask = bytesToIP(ParIpMaskaMas);


    printf("enter IP tire(XXX.XXX.XXX.XXX): ");
    char IpTire[LEN_IPV4];
    scanf("%s", IpTire);

    int ParIpTireMas[IPV4]; // Уже разбитый ip шины в массив
    parserIP(ParIpTireMas, IpTire);

    int32_t dIpTire = bytesToIP(ParIpTireMas);




    int32_t masIP[nPacet]; // Массив сгенерированных ip

    for (int i = 0; i < nPacet; i++) {
        masIP[i] = randIP();
    }

    int counterIP = 0;

    for (int i = 0; i < nPacet; i++) {
        if (analyzeIPNetwork(masIP[i], dIpMask, dIpTire)) {
            counterIP++;
        }
    }

    printf("------%d\n", counterIP);

    return 0;
}







    // printf("Сгенерированный IPv4-адрес: %d.%d.%d.%d\n",
    //        (dIpMask >> 24) & 0xFF,
    //        (dIpMask >> 16) & 0xFF,
    //        (dIpMask >> 8) & 0xFF,
    //        dIpMask & 0xFF);
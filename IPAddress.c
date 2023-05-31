#include "IPAddress.h"

#define IP_ADDRESS_MIN_LENGTH 7
#define IP_ADDRESS_OCTET_MAX_VALUE 255

IPAddress ipAddressOf(uint8_t firstOctet, uint8_t secondOctet, uint8_t thirdOctet, uint8_t fourthOctet) {
    IPAddress ipAddress = {0};
    ipAddress.octetsIPv4[0] = firstOctet;
    ipAddress.octetsIPv4[1] = secondOctet;
    ipAddress.octetsIPv4[2] = thirdOctet;
    ipAddress.octetsIPv4[3] = fourthOctet;
    return ipAddress;
}

IPAddress ipAddressFromString(const char *address) {
    IPAddress ipAddress = {0};
    uint32_t ipAddressLength = address != NULL ? strlen(address) : 0;
    if (ipAddressLength != 0) {
        if (ipAddressLength < IP_ADDRESS_MIN_LENGTH || ipAddressLength > IP_ADDRESS_LENGTH) {
            return ipAddress;
        }

        char tail[IP_ADDRESS_LENGTH + 1] = {0};
        uint16_t ipSegmentArray[IP_ADDRESS_OCTETS_COUNT];
        const char ipPattern[] = "%3hu.%3hu.%3hu.%3hu%s";
        int32_t conversionResult = sscanf(address, ipPattern, &ipSegmentArray[0], &ipSegmentArray[1], &ipSegmentArray[2], &ipSegmentArray[3], tail);

        if (conversionResult != IP_ADDRESS_OCTETS_COUNT || tail[0] != 0) {
            return ipAddress;
        }

        for (uint8_t i = 0; i < IP_ADDRESS_OCTETS_COUNT; i++) {
            if (ipSegmentArray[i] > IP_ADDRESS_OCTET_MAX_VALUE) {
                return ipAddressOf(0, 0, 0, 0);
            }
            ipAddress.octetsIPv4[i] = ipSegmentArray[i];
        }
    }
    return ipAddress;
}

uint32_t ipAddressToU32(IPAddress *ip) {
    uint32_t a = ip->octetsIPv4[0];
    uint32_t b = (uint32_t) ip->octetsIPv4[1] << 8;
    uint32_t c = (uint32_t) ip->octetsIPv4[2] << 16;
    uint32_t d = (uint32_t) ip->octetsIPv4[3] << 24;
    return a + b + c + d;
}

IPAddress ipAddressFromU32(uint32_t ip) {
    IPAddress resultIp = {0};
    resultIp.octetsIPv4[0] = (ip & 0xFF);
    resultIp.octetsIPv4[1] = (ip >> 8) & 0xFF;
    resultIp.octetsIPv4[2] = (ip >> 16) & 0xFF;
    resultIp.octetsIPv4[3] = (ip >> 24) & 0xFF;
    return resultIp;
}

void ipAddressToString(IPAddress *address, char *buffer) {
    if (address != NULL && buffer != NULL) {
        sprintf(buffer, "%hd.%hd.%hd.%hd",
                address->octetsIPv4[0],
                address->octetsIPv4[1],
                address->octetsIPv4[2],
                address->octetsIPv4[3]);
    }
}

bool isIPv4AddressValid(const char *address) {
    IPAddress ipAddress = ipAddressFromString(address);
    return ipAddress.octetsIPv4[0] != '\0';
}
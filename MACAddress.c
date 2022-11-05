#include "MACAddress.h"

#define MAC_ADDRESS_OCTET_MAX_VALUE 255

MACAddress macAddressOf(uint8_t firstOctet, uint8_t secondOctet, uint8_t thirdOctet, uint8_t fourthOctet, uint8_t fifthOctet, uint8_t sixthOctet) {
    MACAddress macAddress = {0};
    macAddress.octets[0] = firstOctet;
    macAddress.octets[1] = secondOctet;
    macAddress.octets[2] = thirdOctet;
    macAddress.octets[3] = fourthOctet;
    macAddress.octets[4] = fifthOctet;
    macAddress.octets[5] = sixthOctet;
    return macAddress;
}

MACAddress macAddressFromString(const char *address) {
    MACAddress macAddress = {0};
    if (isStringNotBlank(address)) {
        uint32_t macAddressLength = strlen(address);
        if (macAddressLength != MAC_ADDRESS_LENGTH) {
            return macAddress;
        }

        uint32_t macBytes[MAC_ADDRESS_OCTETS_COUNT];
        int32_t conversionResult = sscanf(address, "%x:%x:%x:%x:%x:%x", &macBytes[0], &macBytes[1], &macBytes[2], &macBytes[3], &macBytes[4], &macBytes[5]);
        if (conversionResult != MAC_ADDRESS_OCTETS_COUNT) {
            return macAddress;
        }

        for (uint8_t i = 0; i < MAC_ADDRESS_OCTETS_COUNT; i++) {
            if (macBytes[i] > MAC_ADDRESS_OCTET_MAX_VALUE) {
                return macAddressOf(0, 0, 0, 0, 0, 0);
            }
            macAddress.octets[i] = macBytes[i];
        }
    }
    return macAddress;
}

void macAddressToString(MACAddress *address, char *buffer) {
    if (address != NULL && buffer != NULL) {
        sprintf(buffer, "%02x:%02x:%02x:%02x:%02x:%02x",
                address->octets[0],
                address->octets[1],
                address->octets[2],
                address->octets[3],
                address->octets[4],
                address->octets[5]);
    }
}

bool isMacAddressValid(const char *address) {
    return macAddressFromString(address).octets[0] != '\0';
}

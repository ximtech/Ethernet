#pragma once

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>

#define MAC_ADDRESS_OCTETS_COUNT 6
#define MAC_ADDRESS_LENGTH 17

typedef struct MACAddress {
    uint8_t octets[MAC_ADDRESS_OCTETS_COUNT];
} MACAddress;

MACAddress macAddressOf(uint8_t firstOctet, uint8_t secondOctet, uint8_t thirdOctet, uint8_t fourthOctet, uint8_t fifthOctet, uint8_t sixthOctet);
MACAddress macAddressFromString(const char *address);   // Example: "84:cc:a8:af:33:d1" if not valid return "0:0:0:0:0:0"
void macAddressToString(MACAddress *address, char *buffer);
bool isMacAddressValid(const char *address);

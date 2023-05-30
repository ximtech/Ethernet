#pragma once

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>

#define IP_ADDRESS_OCTETS_COUNT 4
#define IP_ADDRESS_LENGTH 15

typedef struct IPAddress {
    uint8_t octetsIPv4[IP_ADDRESS_OCTETS_COUNT];
} IPAddress;

IPAddress ipAddressOf(uint8_t firstOctet, uint8_t secondOctet, uint8_t thirdOctet, uint8_t fourthOctet);
IPAddress ipAddressFromString(const char *address);
void ipAddressToString(IPAddress *address, char *buffer);
bool isIPv4AddressValid(const char *address);

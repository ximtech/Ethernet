# Ethernet

Base utils and constants for Internet library development

### Package contains

- `HTTPHeader.h` - Predefined HTTP headers key definitions("Transfer-Encoding", "Accept" etc.)
- `HTTPMethod.h` - HTTP method definitions("GET", "POST", "PUT" etc.)
- `HTTPStatus.h` - HTTP status codes as enum and code meaning text
- `IPAddress.h` - IP creation from octets, string and address validation
- `MACAddress.h` - MAC creation from octets, string and validation

### Add as CPM project dependency

How to add CPM to the project, check the [link](https://github.com/cpm-cmake/CPM.cmake)

```cmake
CPMAddPackage(
        NAME Ethernet
        GITHUB_REPOSITORY ximtech/Ethernet
        GIT_TAG origin/main)

target_link_libraries(${PROJECT_NAME} Ethernet)
```

```cmake
add_executable(${PROJECT_NAME}.elf ${SOURCES} ${LINKER_SCRIPT})
# For Clion STM32 plugin generated Cmake use 
target_link_libraries(${PROJECT_NAME}.elf Ethernet)
```

### Usage

```c
// HTTP status code helpers
printf("Code: %d\n", HTTP_OK);
printf("Meaning: %s\n", getHttpStatusCodeMeaning(HTTP_OK));

// HTTP headers helpers
printf("Header number: %d\n", ACCEPT);
printf("Header number by name: %d\n", getHttpHeaderKeyByValue("Accept"));
printf("Header value: %s\n", getHeaderValueByKey(ACCEPT));

// HTTP method helpers
printf("Method number: %d\n", HTTP_POST);
printf("Method number by name: %d\n", getHttpMethodByName("POST"));
printf("Method value: %s\n", getHttpMethodName(HTTP_POST));


// create IP from octets
IPAddress ipAddress1 = ipAddressOf(255, 124, 12, 56);
char buffer[10];
ipAddressToString(&ipAddress1, buffer);
printf("IP: [%s]\n", buffer);

// create IP from string
IPAddress ipAddress2 = ipAddressFromString("255.12.121.254");
for (int i = 0; i < IP_ADDRESS_OCTETS_COUNT; i++) {
    printf("%d.", ipAddress2.octetsIPv4[i]);
}

printf("\n");

// IP validation
printf("Ip valid: %s\n", isIPv4AddressValid("127.0.0.1") ? "Yes" : "No");

// create MAC address from octets
MACAddress macAddress1 = macAddressOf(0x84, 0xcc, 0xa8, 0xaf, 0x33, 0xd1);
for (int i = 0; i < MAC_ADDRESS_OCTETS_COUNT; i++) {
    printf("%02x:", macAddress1.octets[i]);
}

printf("\n");

// create MAC address from string
MACAddress macAddress2 = macAddressFromString("84:cc:a8:af:33:d1"); // 84:cc:a8:af:33:d1
for (int i = 0; i < MAC_ADDRESS_OCTETS_COUNT; i++) {
    printf("%02x:", macAddress2.octets[i]);
}

printf("\n");

char buffer2[50];
MACAddress macAddress3 = macAddressOf(0x84, 0xcc, 0xa8, 0xaf, 0x33, 0xd1);
macAddressToString(&macAddress3, buffer2);
printf("%s\n", buffer2);
```
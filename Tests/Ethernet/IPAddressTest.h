#pragma once

#include "BaseTestTemplate.h"
#include "IPAddress.h"


static void checkForNullIP(IPAddress *testIP) {
    for (int i = 0; i < IP_ADDRESS_OCTETS_COUNT; i++) {
        assert_uint8(testIP->octetsIPv4[i], ==, 0);
    }
}

static MunitResult ipAddressOfTest(const MunitParameter params[], void *data) {
    IPAddress address = ipAddressOf(255, 124, 12, 56);
    assert_uint8(address.octetsIPv4[0], ==, 255);
    assert_uint8(address.octetsIPv4[1], ==, 124);
    assert_uint8(address.octetsIPv4[2], ==, 12);
    assert_uint8(address.octetsIPv4[3], ==, 56);

    IPAddress address2 = ipAddressOf(0, 0, 0, 0);
    checkForNullIP(&address2);
    return MUNIT_OK;
}

static MunitResult ipAddressFromStringTest(const MunitParameter params[], void *data) {
    IPAddress address = ipAddressFromString("255.12.121.254");
    assert_uint8(address.octetsIPv4[0], ==, 255);
    assert_uint8(address.octetsIPv4[1], ==, 12);
    assert_uint8(address.octetsIPv4[2], ==, 121);
    assert_uint8(address.octetsIPv4[3], ==, 254);

    IPAddress address2 = ipAddressFromString(NULL);
    IPAddress address3 = ipAddressFromString("    ");
    IPAddress address4 = ipAddressFromString("   \t ");
    IPAddress address5 = ipAddressFromString("NULL");

    checkForNullIP(&address2);
    checkForNullIP(&address3);
    checkForNullIP(&address4);
    checkForNullIP(&address5);
    return MUNIT_OK;
}

static MunitResult ipAddressToStringTest(const MunitParameter params[], void *data) {
    IPAddress address = ipAddressOf(255, 124, 12, 56);
    char buffer[10];
    ipAddressToString(&address, buffer);
    assert_string_equal(buffer, "255.124.12.56");
    return MUNIT_OK;
}

static MunitResult ipAddressValidationTest(const MunitParameter params[], void *data) {
    assert_false(isIPv4AddressValid("255.124.12!.56"));
    assert_false(isIPv4AddressValid("255.1242.122.56"));
    assert_false(isIPv4AddressValid("-2.233.253.133"));
    assert_false(isIPv4AddressValid("255.233.253.13a"));
    assert_false(isIPv4AddressValid("127.0.0.1:80"));   // at now, IP address with port is not valid
    assert_false(isIPv4AddressValid("   \t"));
    assert_false(isIPv4AddressValid(""));
    assert_false(isIPv4AddressValid("NULL"));
    assert_false(isIPv4AddressValid(0));

    assert_true(isIPv4AddressValid("127.0.0.1"));
    assert_true(isIPv4AddressValid("10.8.0.1"));
    return MUNIT_OK;
}

static MunitTest ipAddressTests[] = {
        {.name = "Test OK ipAddressOf() - should create IP from octets", .test = ipAddressOfTest},
        {.name = "Test OK ipAddressFromString() - should create IP from string", .test = ipAddressFromStringTest},
        {.name = "Test OK ipAddressToString() - should convert IP to string", .test = ipAddressToStringTest},
        {.name = "Test OK isIPv4AddressValid() - validate IPv4", .test = ipAddressValidationTest},

        END_OF_TESTS
};

static const MunitSuite ipAddressTestSuite = {
        .prefix = "IP address: ",
        .tests = ipAddressTests,
        .suites = NULL,
        .iterations = 1,
        .options = MUNIT_SUITE_OPTION_NONE
};
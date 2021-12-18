#pragma once

#include "BaseTestTemplate.h"
#include "MACAddress.h"

static void checkForNullMac(MACAddress *testMac) {
    for (int i = 0; i < MAC_ADDRESS_OCTETS_COUNT; i++) {
        assert_uint8(testMac->octets[i], ==, 0);
    }
}

static MunitResult macAddressOfTest(const MunitParameter params[], void *data) {
    MACAddress address = macAddressOf(0x84, 0xcc, 0xa8, 0xaf, 0x33, 0xd1);
    assert_uint8(address.octets[0], ==, 0x84);
    assert_uint8(address.octets[1], ==, 0xcc);
    assert_uint8(address.octets[2], ==, 0xa8);
    assert_uint8(address.octets[3], ==, 0xaf);
    assert_uint8(address.octets[4], ==, 0x33);
    assert_uint8(address.octets[5], ==, 0xd1);

    MACAddress address2 = macAddressOf(0, 0, 0, 0, 0, 0);
    checkForNullMac(&address2);
    return MUNIT_OK;
}

static MunitResult macAddressFromStringTest(const MunitParameter params[], void *data) {
    MACAddress address = macAddressFromString("84:cc:a8:af:33:d1");
    assert_uint8(address.octets[0], ==, 0x84);
    assert_uint8(address.octets[1], ==, 0xcc);
    assert_uint8(address.octets[2], ==, 0xa8);
    assert_uint8(address.octets[3], ==, 0xaf);
    assert_uint8(address.octets[4], ==, 0x33);
    assert_uint8(address.octets[5], ==, 0xd1);

    MACAddress address2 = macAddressFromString(NULL);
    MACAddress address3 = macAddressFromString("    ");
    MACAddress address4 = macAddressFromString("   \t ");
    MACAddress address5 = macAddressFromString("NULL");

    checkForNullMac(&address2);
    checkForNullMac(&address3);
    checkForNullMac(&address4);
    checkForNullMac(&address5);
    return MUNIT_OK;
}

static MunitResult macAddressToStringTest(const MunitParameter params[], void *data) {
    MACAddress address = macAddressOf(0x84, 0xcc, 0xa8, 0xff, 0x33, 0xd1);
    char buffer[50];
    macAddressToString(&address, buffer);
    assert_string_equal(buffer, "84:cc:a8:ff:33:d1");
    return MUNIT_OK;
}

static MunitResult macAddressValidationTest(const MunitParameter params[], void *data) {
    assert_false(isMacAddressValid("45:5d:654:aa:56:33"));
    assert_false(isMacAddressValid("45:5d:65:a!:56:33"));
    assert_false(isMacAddressValid("45:5d:65:a!:56: 3"));
    assert_false(isMacAddressValid("45:5d:65:a!:56:33 "));
    assert_false(isMacAddressValid("84:cc:a8:af:33"));
    assert_false(isMacAddressValid("84:cc:a8:af:33:d1:32"));
    assert_false(isMacAddressValid("ff.ff.ff.ff.ff.ff"));
    assert_false(isMacAddressValid(""));
    assert_false(isMacAddressValid(0));
    assert_false(isMacAddressValid("  \t"));

    assert_true(isMacAddressValid("45:5d:65:aa:56:33"));
    assert_true(isMacAddressValid("84:cc:a8:af:33:d1"));
    assert_true(isMacAddressValid("ff:ff:ff:ff:ff:ff"));
    return MUNIT_OK;
}

static MunitTest macAddressTests[] = {
        {.name = "Test OK macAddressOf() - should create MAC from octets", .test = macAddressOfTest},
        {.name = "Test OK macAddressFromString() - should create MAC from string", .test = macAddressFromStringTest},
        {.name = "Test OK macAddressToString() - should convert MAC to string", .test = macAddressToStringTest},
        {.name = "Test OK isMacAddressValid() - validate MAC address", .test = macAddressValidationTest},

        END_OF_TESTS
};

static const MunitSuite macAddressTestSuite = {
        .prefix = "MAC address: ",
        .tests = macAddressTests,
        .suites = NULL,
        .iterations = 1,
        .options = MUNIT_SUITE_OPTION_NONE
};
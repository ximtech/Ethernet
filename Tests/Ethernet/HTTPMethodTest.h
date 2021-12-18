#pragma once

#include "BaseTestTemplate.h"
#include "HTTPMethod.h"


static MunitResult getHttpMethodNameTest(const MunitParameter params[], void *data) {
    assert_string_equal(getHttpMethodName(HTTP_POST), "POST");
    assert_string_equal(getHttpMethodName(HTTP_GET), "GET");
    assert_string_equal(getHttpMethodName(HTTP_PUT), "PUT");
    assert_string_equal(getHttpMethodName(HTTP_DELETE), "DELETE");
    assert_string_equal(getHttpMethodName(HTTP_HEAD), "HEAD");
    assert_string_equal(getHttpMethodName(HTTP_PATCH), "PATCH");
    assert_string_equal(getHttpMethodName(HTTP_OPTIONS), "OPTIONS");
    assert_string_equal(getHttpMethodName(HTTP_TRACE), "TRACE");
    return MUNIT_OK;
}

static MunitResult getHttpMethodByNameTest(const MunitParameter params[], void *data) {
    assert_uint8(getHttpMethodByName("POST"), ==, HTTP_POST);
    assert_uint8(getHttpMethodByName("GET"), ==, HTTP_GET);
    assert_uint8(getHttpMethodByName("PUT"), ==, HTTP_PUT);
    assert_uint8(getHttpMethodByName("DELETE"), ==, HTTP_DELETE);
    assert_uint8(getHttpMethodByName("HEAD"), ==, HTTP_HEAD);
    assert_uint8(getHttpMethodByName("PATCH"), ==, HTTP_PATCH);
    assert_uint8(getHttpMethodByName("OPTIONS"), ==, HTTP_OPTIONS);
    assert_uint8(getHttpMethodByName("TRACE"), ==, HTTP_TRACE);
    return MUNIT_OK;
}


static MunitTest httpMethodTests[] = {
//        {.name = "Test OK getHttpMethodName() - should return method name by key", .test = getHttpMethodNameTest},
//        {.name = "Test OK getHttpMethodByName() - should return method key by name", .test = getHttpMethodByNameTest},

        END_OF_TESTS
};

static const MunitSuite httpMethodTestSuite = {
        .prefix = "HTTP method: ",
        .tests = httpMethodTests,
        .suites = NULL,
        .iterations = 1,
        .options = MUNIT_SUITE_OPTION_NONE
};

#pragma once

#include "BaseTestTemplate.h"
#include "HTTPStatus.h"

static MunitResult getHttpStatusCodeMeaningTest(const MunitParameter params[], void *data) {
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_CONTINUE), "Continue");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_SWITCHING_PROTOCOL), "Switching protocols");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_PROCESSING), "Processing");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_CHECKPOINT), "Early Hints");

    assert_string_equal(getHttpStatusCodeMeaning(HTTP_OK), "OK");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_CREATED), "Created");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_ACCEPTED), "Accepted");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_NON_AUTHORITATIVE_INFORMATION), "Non-Authoritative Information");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_NO_CONTENT), "No Content");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_RESET_CONTENT), "Reset Content");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_PARTIAL_CONTENT), "Partial Content");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_MULTI_STATUS), "Multi-Status");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_ALREADY_REPORTED), "Already Reported");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_IM_USED), "IM Used");

    assert_string_equal(getHttpStatusCodeMeaning(HTTP_MULTIPLE_CHOICES), "Multiple Choices");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_MOVED_PERMANENTLY), "Moved Permanently");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_FOUND), "Found");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_SEE_OTHER), "See Other");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_NOT_MODIFIED), "Not Modified");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_USE_PROXY), "Use Proxy");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_SWITCH_PROXY), "Switch Proxy");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_TEMPORARY_REDIRECT), "Temporary Redirect");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_PERMANENT_REDIRECT), "Permanent Redirect");

    assert_string_equal(getHttpStatusCodeMeaning(HTTP_BAD_REQUEST), "Bad Request");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_UNAUTHORIZED), "Unauthorized");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_PAYMENT_REQUIRED), "Payment Required");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_FORBIDDEN), "Forbidden");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_NOT_FOUND), "Not Found");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_METHOD_NOT_ALLOWED), "Method Not Allowed");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_NOT_ACCEPTABLE), "Not Acceptable");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_PROXY_AUTHENTICATION_REQUIRED), "Proxy Authentication Required");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_REQUEST_TIMEOUT), "Request Timeout");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_CONFLICT), "Conflict");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_GONE), "Gone");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_LENGTH_REQUIRED), "Length Required");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_PRECONDITION_FAILED), "Precondition Failed");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_PAYLOAD_TOO_LARGE), "Payload Too Large");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_URI_TOO_LONG), "URI Too Long");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_UNSUPPORTED_MEDIA_TYPE), "Unsupported Media Type");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_REQUESTED_RANGE_NOT_SATISFIABLE), "Range Not Satisfiable");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_EXPECTATION_FAILED), "Expectation Failed");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_I_AM_A_TEAPOT), "I'm a Teapot");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_METHOD_FAILURE), "Method Failure");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_MISDIRECTED_REQUEST), "Misdirected Request");

    assert_string_equal(getHttpStatusCodeMeaning(HTTP_UNPROCESSABLE_ENTITY), "Unprocessable Entity");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_LOCKED), "Locked");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_FAILED_DEPENDENCY), "Failed Dependency");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_TOO_EARLY), "Too Early");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_UPGRADE_REQUIRED), "Upgrade Required");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_PRECONDITION_REQUIRED), "Precondition Required");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_TOO_MANY_REQUESTS), "Too Many Requests");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_REQUEST_HEADER_FIELDS_TOO_LARGE), "Request Header Fields Too Large");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_UNAVAILABLE_FOR_LEGAL_REASONS), "Unavailable For Legal Reasons");

    assert_string_equal(getHttpStatusCodeMeaning(HTTP_INTERNAL_SERVER_ERROR), "Internal Server Error");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_NOT_IMPLEMENTED), "Not Implemented");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_BAD_GATEWAY), "Bad Gateway");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_SERVICE_UNAVAILABLE), "Service Unavailable");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_GATEWAY_TIMEOUT), "Gateway Timeout");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_VERSION_NOT_SUPPORTED), "HTTP Version Not Supported");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_VARIANT_ALSO_NEGOTIATES), "Variant Also Negotiates");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_INSUFFICIENT_STORAGE), "Insufficient Storage");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_LOOP_DETECTED), "Loop Detected");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_BANDWIDTH_LIMIT_EXCEEDED), "Bandwidth Limit Exceeded");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_NOT_EXTENDED), "Not Extended");
    assert_string_equal(getHttpStatusCodeMeaning(HTTP_NETWORK_AUTHENTICATION_REQUIRED), "Network Authentication Required");
    return MUNIT_OK;
}

static MunitTest httpStatusTests[] = {
        {.name = "Test OK getHttpStatusCodeMeaning() - should return status value by key", .test = getHttpStatusCodeMeaningTest},

        END_OF_TESTS
};

static const MunitSuite httpStatusTestSuite = {
        .prefix = "HTTP status: ",
        .tests = httpStatusTests,
        .suites = NULL,
        .iterations = 1,
        .options = MUNIT_SUITE_OPTION_NONE
};
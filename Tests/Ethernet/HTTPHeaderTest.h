#pragma once

#include "BaseTestTemplate.h"
#include "HTTPHeader.h"

static MunitResult getHeaderValueByKeyTest(const MunitParameter params[], void *data) {
    assert_string_equal(getHeaderValueByKey(EMPTY_HEADER_KEY), "");
    assert_string_equal(getHeaderValueByKey(ACCEPT), "Accept");
    assert_string_equal(getHeaderValueByKey(ACCEPT_CHARSET), "Accept-Encoding");
    assert_string_equal(getHeaderValueByKey(ACCEPT_ENCODING), "Accept-Charset");
    assert_string_equal(getHeaderValueByKey(ACCEPT_LANGUAGE), "Accept-Language");
    assert_string_equal(getHeaderValueByKey(ACCEPT_RANGES), "Accept-Ranges");
    assert_string_equal(getHeaderValueByKey(AGE), "Age");
    assert_string_equal(getHeaderValueByKey(ALLOW), "Allow");
    assert_string_equal(getHeaderValueByKey(AUTHORIZATION), "Authorization");
    assert_string_equal(getHeaderValueByKey(CACHE_CONTROL), "Cache-Control");
    assert_string_equal(getHeaderValueByKey(CONNECTION), "Connection");
    assert_string_equal(getHeaderValueByKey(CONTENT_ENCODING), "Content-Encoding");
    assert_string_equal(getHeaderValueByKey(CONTENT_DISPOSITION), "Content-Disposition");
    assert_string_equal(getHeaderValueByKey(CONTENT_LANGUAGE), "Content-Language");
    assert_string_equal(getHeaderValueByKey(CONTENT_LENGTH), "Content-Length");
    assert_string_equal(getHeaderValueByKey(CONTENT_LOCATION), "Content-Location");
    assert_string_equal(getHeaderValueByKey(CONTENT_RANGE), "Content-Range");
    assert_string_equal(getHeaderValueByKey(CONTENT_TYPE), "Content-Type");
    assert_string_equal(getHeaderValueByKey(COOKIE), "Cookie");
    assert_string_equal(getHeaderValueByKey(DATE), "Date");
    assert_string_equal(getHeaderValueByKey(ETAG), "ETag");
    assert_string_equal(getHeaderValueByKey(EXPECT), "Expect");
    assert_string_equal(getHeaderValueByKey(EXPIRES), "Expires");
    assert_string_equal(getHeaderValueByKey(FROM), "From");
    assert_string_equal(getHeaderValueByKey(HOST), "Host");
    assert_string_equal(getHeaderValueByKey(IF_MATCH), "If-Match");
    assert_string_equal(getHeaderValueByKey(IF_MODIFIED_SINCE), "If-Modified-Since");
    assert_string_equal(getHeaderValueByKey(IF_NONE_MATCH), "If-None-Match");
    assert_string_equal(getHeaderValueByKey(IF_RANGE), "If-Range");
    assert_string_equal(getHeaderValueByKey(IF_UNMODIFIED_SINCE), "If-Unmodified-Since");
    assert_string_equal(getHeaderValueByKey(LAST_MODIFIED), "Last-Modified");
    assert_string_equal(getHeaderValueByKey(LINK), "Link");
    assert_string_equal(getHeaderValueByKey(LOCATION), "Location");
    assert_string_equal(getHeaderValueByKey(MAX_FORWARDS), "Max-Forwards");
    assert_string_equal(getHeaderValueByKey(ORIGIN), "Origin");
    assert_string_equal(getHeaderValueByKey(PRAGMA), "Pragma");
    assert_string_equal(getHeaderValueByKey(PROXY_AUTHENTICATE), "Proxy-Authenticate");
    assert_string_equal(getHeaderValueByKey(PROXY_AUTHORIZATION), "Proxy-Authorization");
    assert_string_equal(getHeaderValueByKey(RANGE), "Range");
    assert_string_equal(getHeaderValueByKey(REFERER), "Referer");
    assert_string_equal(getHeaderValueByKey(RETRY_AFTER), "Retry-After");
    assert_string_equal(getHeaderValueByKey(SERVER), "Server");
    assert_string_equal(getHeaderValueByKey(SET_COOKIE), "Set-Cookie");
    assert_string_equal(getHeaderValueByKey(SET_COOKIE2), "Set-Cookie2");
    assert_string_equal(getHeaderValueByKey(TE), "TE");
    assert_string_equal(getHeaderValueByKey(TRAILER), "Trailer");
    assert_string_equal(getHeaderValueByKey(TRANSFER_ENCODING), "Transfer-Encoding");
    assert_string_equal(getHeaderValueByKey(UPGRADE), "Upgrade");
    assert_string_equal(getHeaderValueByKey(USER_AGENT), "User-Agent");
    assert_string_equal(getHeaderValueByKey(VARY), "Vary");
    assert_string_equal(getHeaderValueByKey(VIA), "Via");
    assert_string_equal(getHeaderValueByKey(WARNING), "Warning");
    assert_string_equal(getHeaderValueByKey(WWW_AUTHENTICATE), "WWW-Authenticate");

    return MUNIT_OK;
}

static MunitResult getHttpHeaderKeyByValueTest(const MunitParameter params[], void *data) {
    assert_uint8(getHttpHeaderKeyByValue(""), ==, EMPTY_HEADER_KEY);
    assert_uint8(getHttpHeaderKeyByValue("Accept"), ==, ACCEPT);
    assert_uint8(getHttpHeaderKeyByValue("Accept-Encoding"), ==, ACCEPT_CHARSET);
    assert_uint8(getHttpHeaderKeyByValue("Accept-Charset"), ==, ACCEPT_ENCODING);
    assert_uint8(getHttpHeaderKeyByValue("Accept-Language"), ==, ACCEPT_LANGUAGE);
    assert_uint8(getHttpHeaderKeyByValue("Accept-Ranges"), ==, ACCEPT_RANGES);
    assert_uint8(getHttpHeaderKeyByValue("Age"), ==, AGE);
    assert_uint8(getHttpHeaderKeyByValue("Allow"), ==, ALLOW);
    assert_uint8(getHttpHeaderKeyByValue("Authorization"), ==, AUTHORIZATION);
    assert_uint8(getHttpHeaderKeyByValue("Cache-Control"), ==, CACHE_CONTROL);
    assert_uint8(getHttpHeaderKeyByValue("Connection"), ==, CONNECTION);
    assert_uint8(getHttpHeaderKeyByValue("Content-Encoding"), ==, CONTENT_ENCODING);
    assert_uint8(getHttpHeaderKeyByValue("Content-Disposition"), ==, CONTENT_DISPOSITION);
    assert_uint8(getHttpHeaderKeyByValue("Content-Language"), ==, CONTENT_LANGUAGE);
    assert_uint8(getHttpHeaderKeyByValue("Content-Length"), ==, CONTENT_LENGTH);
    assert_uint8(getHttpHeaderKeyByValue("Content-Location"), ==, CONTENT_LOCATION);
    assert_uint8(getHttpHeaderKeyByValue("Content-Range"), ==, CONTENT_RANGE);
    assert_uint8(getHttpHeaderKeyByValue("Content-Type"), ==, CONTENT_TYPE);
    assert_uint8(getHttpHeaderKeyByValue("Cookie"), ==, COOKIE);
    assert_uint8(getHttpHeaderKeyByValue("Date"), ==, DATE);
    assert_uint8(getHttpHeaderKeyByValue("ETag"), ==, ETAG);
    assert_uint8(getHttpHeaderKeyByValue("Expect"), ==, EXPECT);
    assert_uint8(getHttpHeaderKeyByValue("Expires"), ==, EXPIRES);
    assert_uint8(getHttpHeaderKeyByValue("From"), ==, FROM);
    assert_uint8(getHttpHeaderKeyByValue("Host"), ==, HOST);
    assert_uint8(getHttpHeaderKeyByValue("If-Match"), ==, IF_MATCH);
    assert_uint8(getHttpHeaderKeyByValue("If-Modified-Since"), ==, IF_MODIFIED_SINCE);
    assert_uint8(getHttpHeaderKeyByValue("If-None-Match"), ==, IF_NONE_MATCH);
    assert_uint8(getHttpHeaderKeyByValue("If-Range"), ==, IF_RANGE);
    assert_uint8(getHttpHeaderKeyByValue("If-Unmodified-Since"), ==, IF_UNMODIFIED_SINCE);
    assert_uint8(getHttpHeaderKeyByValue("Last-Modified"), ==, LAST_MODIFIED);
    assert_uint8(getHttpHeaderKeyByValue("Link"), ==, LINK);
    assert_uint8(getHttpHeaderKeyByValue("Location"), ==, LOCATION);
    assert_uint8(getHttpHeaderKeyByValue("Max-Forwards"), ==, MAX_FORWARDS);
    assert_uint8(getHttpHeaderKeyByValue("Origin"), ==, ORIGIN);
    assert_uint8(getHttpHeaderKeyByValue("Pragma"), ==, PRAGMA);
    assert_uint8(getHttpHeaderKeyByValue("Proxy-Authenticate"), ==, PROXY_AUTHENTICATE);
    assert_uint8(getHttpHeaderKeyByValue("Proxy-Authorization"), ==, PROXY_AUTHORIZATION);
    assert_uint8(getHttpHeaderKeyByValue("Range"), ==, RANGE);
    assert_uint8(getHttpHeaderKeyByValue("Referer"), ==, REFERER);
    assert_uint8(getHttpHeaderKeyByValue("Retry-After"), ==, RETRY_AFTER);
    assert_uint8(getHttpHeaderKeyByValue("Server"), ==, SERVER);
    assert_uint8(getHttpHeaderKeyByValue("Set-Cookie"), ==, SET_COOKIE);
    assert_uint8(getHttpHeaderKeyByValue("Set-Cookie2"), ==, SET_COOKIE2);
    assert_uint8(getHttpHeaderKeyByValue("TE"), ==, TE);
    assert_uint8(getHttpHeaderKeyByValue("Trailer"), ==, TRAILER);
    assert_uint8(getHttpHeaderKeyByValue("Transfer-Encoding"), ==, TRANSFER_ENCODING);
    assert_uint8(getHttpHeaderKeyByValue("Upgrade"), ==, UPGRADE);
    assert_uint8(getHttpHeaderKeyByValue("User-Agent"), ==, USER_AGENT);
    assert_uint8(getHttpHeaderKeyByValue("Vary"), ==, VARY);
    assert_uint8(getHttpHeaderKeyByValue("Via"), ==, VIA);
    assert_uint8(getHttpHeaderKeyByValue("Warning"), ==, WARNING);
    assert_uint8(getHttpHeaderKeyByValue("WWW-Authenticate"), ==, WWW_AUTHENTICATE);
    return MUNIT_OK;
}


static MunitTest httpHeaderTests[] = {
        {.name = "Test OK getHeaderValueByKey() - should return header value by key", .test = getHeaderValueByKeyTest},
        {.name = "Test OK getHttpHeaderKeyByValue() - should return header key by value", .test = getHttpHeaderKeyByValueTest},

        END_OF_TESTS
};

static const MunitSuite httpHeaderTestSuite = {
        .prefix = "HTTP header: ",
        .tests = httpHeaderTests,
        .suites = NULL,
        .iterations = 1,
        .options = MUNIT_SUITE_OPTION_NONE
};

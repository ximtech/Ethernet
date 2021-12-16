#pragma once

#include <string.h>

#define HTTP_METHOD_MAX_VALUES (sizeof(HTTP_METHOD_NAME_ARRAY) / sizeof(char *))

typedef enum HTTPMethod {
    HTTP_NO_METHOD = -1,
    HTTP_POST = 0,
    HTTP_GET = 1,
    HTTP_PUT = 2,
    HTTP_DELETE = 3,
    HTTP_HEAD = 4,
    HTTP_PATCH = 5,
    HTTP_OPTIONS = 6,
    HTTP_TRACE = 7
} HTTPMethod;

static const char *const HTTP_METHOD_NAME_ARRAY[] = {
        [HTTP_POST] = "POST",
        [HTTP_GET] = "GET",
        [HTTP_PUT] = "PUT",
        [HTTP_DELETE] = "DELETE",
        [HTTP_HEAD] = "HEAD",
        [HTTP_PATCH] = "PATCH",
        [HTTP_OPTIONS] = "OPTIONS",
        [HTTP_TRACE] = "TRACE"
};

static const char *getHttpMethodName(HTTPMethod method) {
    if(method > HTTP_NO_METHOD && method < HTTP_METHOD_MAX_VALUES) {
        return HTTP_METHOD_NAME_ARRAY[method];
    }
    return NULL;
}

static HTTPMethod getHttpMethodByName(const char *methodName) {
    for (int i = 0; i < HTTP_METHOD_MAX_VALUES; i++) {
        if (!strcmp(HTTP_METHOD_NAME_ARRAY[i], methodName)) {
            return i;
        }
    }
    return HTTP_NO_METHOD;
}
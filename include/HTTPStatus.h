#pragma once

#define HTTP_STATUS_LENGTH 3
#define HTTP_STATUS_CODE_MAX_VALUE (sizeof(HTTP_RESPONSE_STATUS_DEFINITION_ARRAY) / sizeof(char *))

typedef enum HTTPStatus {
    HTTP_NO_STATUS = 0,
    HTTP_CONTINUE = 100,
    HTTP_SWITCHING_PROTOCOL = 101,
    HTTP_PROCESSING = 102,
    HTTP_CHECKPOINT = 103,

    HTTP_OK = 200,
    HTTP_CREATED = 201,
    HTTP_ACCEPTED = 202,
    HTTP_NON_AUTHORITATIVE_INFORMATION = 203,
    HTTP_NO_CONTENT = 204,
    HTTP_RESET_CONTENT = 205,
    HTTP_PARTIAL_CONTENT = 206,
    HTTP_MULTI_STATUS = 207,
    HTTP_ALREADY_REPORTED = 208,
    HTTP_IM_USED = 226,

    HTTP_MULTIPLE_CHOICES = 300,
    HTTP_MOVED_PERMANENTLY = 301,
    HTTP_FOUND = 302,
    HTTP_SEE_OTHER = 303,
    HTTP_NOT_MODIFIED = 304,
    HTTP_USE_PROXY = 305,
    HTTP_SWITCH_PROXY = 306,
    HTTP_TEMPORARY_REDIRECT = 307,
    HTTP_PERMANENT_REDIRECT = 308,

    HTTP_BAD_REQUEST = 400,
    HTTP_UNAUTHORIZED = 401,
    HTTP_PAYMENT_REQUIRED = 402,
    HTTP_FORBIDDEN = 403,
    HTTP_NOT_FOUND = 404,
    HTTP_METHOD_NOT_ALLOWED = 405,
    HTTP_NOT_ACCEPTABLE = 406,
    HTTP_PROXY_AUTHENTICATION_REQUIRED = 407,
    HTTP_REQUEST_TIMEOUT = 408,
    HTTP_CONFLICT = 409,
    HTTP_GONE = 410,
    HTTP_LENGTH_REQUIRED = 411,
    HTTP_PRECONDITION_FAILED = 412,
    HTTP_PAYLOAD_TOO_LARGE = 413,
    HTTP_URI_TOO_LONG = 414,
    HTTP_UNSUPPORTED_MEDIA_TYPE = 415,
    HTTP_REQUESTED_RANGE_NOT_SATISFIABLE = 416,
    HTTP_EXPECTATION_FAILED = 417,
    HTTP_I_AM_A_TEAPOT = 418,
    HTTP_METHOD_FAILURE = 420,
    HTTP_MISDIRECTED_REQUEST = 421,
    HTTP_UNPROCESSABLE_ENTITY = 422,
    HTTP_LOCKED = 423,
    HTTP_FAILED_DEPENDENCY = 424,
    HTTP_TOO_EARLY = 425,
    HTTP_UPGRADE_REQUIRED = 426,
    HTTP_PRECONDITION_REQUIRED = 428,
    HTTP_TOO_MANY_REQUESTS = 429,
    HTTP_REQUEST_HEADER_FIELDS_TOO_LARGE = 431,
    HTTP_UNAVAILABLE_FOR_LEGAL_REASONS = 451,

    HTTP_INTERNAL_SERVER_ERROR = 500,
    HTTP_NOT_IMPLEMENTED = 501,
    HTTP_BAD_GATEWAY = 502,
    HTTP_SERVICE_UNAVAILABLE = 503,
    HTTP_GATEWAY_TIMEOUT = 504,
    HTTP_VERSION_NOT_SUPPORTED = 505,
    HTTP_VARIANT_ALSO_NEGOTIATES = 506,
    HTTP_INSUFFICIENT_STORAGE = 507,
    HTTP_LOOP_DETECTED = 508,
    HTTP_BANDWIDTH_LIMIT_EXCEEDED = 509,
    HTTP_NOT_EXTENDED = 510,
    HTTP_NETWORK_AUTHENTICATION_REQUIRED = 511
} HTTPStatus;


static const char *const HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[] = {
        "Continue",
        "Switching protocols",
        "Processing",
        "Early Hints",

        "OK",
        "Created",
        "Accepted",
        "Non-Authoritative Information",
        "No Content",
        "Reset Content",
        "Partial Content",
        "Multi-Status",
        "Already Reported",
        "IM Used",

        "Multiple Choices",
        "Moved Permanently",
        "Found",
        "See Other",
        "Not Modified",
        "Use Proxy",
        "Switch Proxy",
        "Temporary Redirect",
        "Permanent Redirect",

        "Bad Request",
        "Unauthorized",
        "Payment Required",
        "Forbidden",
        "Not Found",
        "Method Not Allowed",
        "Not Acceptable",
        "Proxy Authentication Required",
        "Request Timeout",
        "Conflict",
        "Gone",
        "Length Required",
        "Precondition Failed",
        "Payload Too Large",
        "URI Too Long",
        "Unsupported Media Type",
        "Range Not Satisfiable",
        "Expectation Failed",
        "I'm a Teapot",
        "Method Failure",
        "Misdirected Request",

        "Unprocessable Entity",
        "Locked",
        "Failed Dependency",
        "Too Early",
        "Upgrade Required",
        "Precondition Required",
        "Too Many Requests",
        "Request Header Fields Too Large",
        "Unavailable For Legal Reasons",

        "Internal Server Error",
        "Not Implemented",
        "Bad Gateway",
        "Service Unavailable",
        "Gateway Timeout",
        "HTTP Version Not Supported",
        "Variant Also Negotiates",
        "Insufficient Storage",
        "Loop Detected",
        "Bandwidth Limit Exceeded",
        "Not Extended",
        "Network Authentication Required"
};

static const char *getHttpStatusCodeMeaning(HTTPStatus httpStatus) {
    switch (httpStatus) {
        case HTTP_CONTINUE:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[0];
        case HTTP_SWITCHING_PROTOCOL:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[1];
        case HTTP_PROCESSING:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[2];
        case HTTP_CHECKPOINT:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[3];

        case HTTP_OK:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[4];
        case HTTP_CREATED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[5];
        case HTTP_ACCEPTED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[6];
        case HTTP_NON_AUTHORITATIVE_INFORMATION:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[7];
        case HTTP_NO_CONTENT:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[8];
        case HTTP_RESET_CONTENT:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[9];
        case HTTP_PARTIAL_CONTENT:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[10];
        case HTTP_MULTI_STATUS:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[11];
        case HTTP_ALREADY_REPORTED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[12];
        case HTTP_IM_USED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[13];

        case HTTP_MULTIPLE_CHOICES:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[14];
        case HTTP_MOVED_PERMANENTLY:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[15];
        case HTTP_FOUND:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[16];
        case HTTP_SEE_OTHER:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[17];
        case HTTP_NOT_MODIFIED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[18];
        case HTTP_USE_PROXY:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[19];
        case HTTP_SWITCH_PROXY:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[20];
        case HTTP_TEMPORARY_REDIRECT:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[21];
        case HTTP_PERMANENT_REDIRECT:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[22];

        case HTTP_BAD_REQUEST:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[23];
        case HTTP_UNAUTHORIZED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[24];
        case HTTP_PAYMENT_REQUIRED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[25];
        case HTTP_FORBIDDEN:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[26];
        case HTTP_NOT_FOUND:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[27];
        case HTTP_METHOD_NOT_ALLOWED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[28];
        case HTTP_NOT_ACCEPTABLE:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[29];
        case HTTP_PROXY_AUTHENTICATION_REQUIRED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[30];
        case HTTP_REQUEST_TIMEOUT:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[31];
        case HTTP_CONFLICT:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[32];
        case HTTP_GONE:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[33];
        case HTTP_LENGTH_REQUIRED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[34];
        case HTTP_PRECONDITION_FAILED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[35];
        case HTTP_PAYLOAD_TOO_LARGE:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[36];
        case HTTP_URI_TOO_LONG:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[37];
        case HTTP_UNSUPPORTED_MEDIA_TYPE:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[38];
        case HTTP_REQUESTED_RANGE_NOT_SATISFIABLE:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[39];
        case HTTP_EXPECTATION_FAILED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[40];
        case HTTP_I_AM_A_TEAPOT:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[41];
        case HTTP_METHOD_FAILURE:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[42];
        case HTTP_MISDIRECTED_REQUEST:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[43];

        case HTTP_UNPROCESSABLE_ENTITY:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[44];
        case HTTP_LOCKED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[45];
        case HTTP_FAILED_DEPENDENCY:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[46];
        case HTTP_TOO_EARLY:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[47];
        case HTTP_UPGRADE_REQUIRED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[48];
        case HTTP_PRECONDITION_REQUIRED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[49];
        case HTTP_TOO_MANY_REQUESTS:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[50];
        case HTTP_REQUEST_HEADER_FIELDS_TOO_LARGE:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[51];
        case HTTP_UNAVAILABLE_FOR_LEGAL_REASONS:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[52];

        case HTTP_INTERNAL_SERVER_ERROR:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[53];
        case HTTP_NOT_IMPLEMENTED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[54];
        case HTTP_BAD_GATEWAY:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[55];
        case HTTP_SERVICE_UNAVAILABLE:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[56];
        case HTTP_GATEWAY_TIMEOUT:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[57];
        case HTTP_VERSION_NOT_SUPPORTED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[58];
        case HTTP_VARIANT_ALSO_NEGOTIATES:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[59];
        case HTTP_INSUFFICIENT_STORAGE:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[60];
        case HTTP_LOOP_DETECTED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[61];
        case HTTP_BANDWIDTH_LIMIT_EXCEEDED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[62];
        case HTTP_NOT_EXTENDED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[63];
        case HTTP_NETWORK_AUTHENTICATION_REQUIRED:
            return HTTP_RESPONSE_STATUS_DEFINITION_ARRAY[64];
        default:
            return NULL;
    }
}
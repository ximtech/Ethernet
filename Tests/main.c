#include "Ethernet/IPAddressTest.h"
#include "Ethernet/MacAddressTest.h"
#include "Ethernet/HTTPHeaderTest.h"
#include "Ethernet/HTTPMethodTest.h"
#include "Ethernet/HTTPStatusTest.h"


int main(int argc, char *argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    MunitTest emptyTests[] = {END_OF_TESTS};
    MunitSuite testSuitArray[] = {
            ipAddressTestSuite,
            macAddressTestSuite,
            httpHeaderTestSuite,
            httpMethodTestSuite,
            httpStatusTestSuite
    };

    MunitSuite baseSuite = {
            .prefix = "",
            .tests = emptyTests,
            .suites = testSuitArray,
            .iterations = 1,
            .options = MUNIT_SUITE_OPTION_NONE
    };
    return munit_suite_main(&baseSuite, (void *) "µnit", argc, argv);
}

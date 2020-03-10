#define BOOST_TEST_MODULE test_version

#include "version.h"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(boost_test)

BOOST_AUTO_TEST_CASE(test_version)
{
    BOOST_CHECK(version() > 0);
}
}

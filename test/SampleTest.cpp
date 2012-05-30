#include <cppunit/extensions/HelperMacros.h>
#include <vector>
#include "TestUtils.hpp"



class classUnderTestTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(classUnderTestTest);
    CPPUNIT_TEST(testFunctionOrMethod);
    CPPUNIT_TEST_SUITE_END();

    public:

    void setUp(){
    }

    void tearDown(){
    }

    void testFunctionOrMethod(){
        std::vector<int> a = {1,2,3};
        std::vector<int> b = {4,5,6};
        CPPUNIT_ASSERT_EQUAL(a,b);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(classUnderTestTest);





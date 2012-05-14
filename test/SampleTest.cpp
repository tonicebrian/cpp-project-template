#include <cppunit/extensions/HelperMacros.h>

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
        CPPUNIT_ASSERT_EQUAL(1,0);
    }
};

CPPUNIT_TEST_SUITE_REGISTRATION(classUnderTestTest);





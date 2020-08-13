#include <cppunit/TestFixture.h>
#include <cppunit/TestCase.h>
#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include <vector2d.h>

using namespace CppUnit;
using namespace std;

class TestVector2d : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestVector2d);
    CPPUNIT_TEST(testDefaultConstructor);
    CPPUNIT_TEST(testConstructor);

    CPPUNIT_TEST(testAddition);
    CPPUNIT_TEST(testSubtraction);

    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testDefaultConstructor(void);
    void testConstructor(void);

    void testAddition(void);
    void testSubtraction(void);

private:
    Vector2d *testVector2d;
    Vector2d *testVector2d_1;
    Vector2d *testVector2d_2;
};

void TestVector2d::testDefaultConstructor(void)
{
    Vector2d testVector2d;
    CPPUNIT_ASSERT(0 == testVector2d.getX());
    CPPUNIT_ASSERT(0 == testVector2d.getY());
}

void TestVector2d::testConstructor(void)
{
    Vector2d testVector2d(3,3);
    CPPUNIT_ASSERT(3 == testVector2d.getX());
    CPPUNIT_ASSERT(3 == testVector2d.getY());
}

void TestVector2d::testAddition(void)
{
    Vector2d testVector2d_1(2,2);
    Vector2d testVector2d_2(3,3);

    CPPUNIT_ASSERT(5 == (testVector2d_1 + testVector2d_2).getX());
    CPPUNIT_ASSERT(5 == (testVector2d_1 + testVector2d_2).getY());

}

void TestVector2d::testSubtraction(void)
{
    Vector2d testVector2d_1(2,2);
    Vector2d testVector2d_2(3,3);

    CPPUNIT_ASSERT(-1 == (testVector2d_1 - testVector2d_2).getX());
    CPPUNIT_ASSERT(-1 == (testVector2d_1 - testVector2d_2).getY());

}

void TestVector2d::setUp(void)
{
    testVector2d = new Vector2d();
    testVector2d_1 = new Vector2d();
    testVector2d_2 = new Vector2d();

}

void TestVector2d::tearDown(void)
{
    delete testVector2d;
    delete testVector2d_1;
    delete testVector2d_2;

}

CPPUNIT_TEST_SUITE_REGISTRATION( TestVector2d );

int main(int argc, char* argv[])
{
    CPPUNIT_NS::TestResult testresult;
    CPPUNIT_NS::TestResultCollector collectedresults;

    testresult.addListener (&collectedresults);

    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    CPPUNIT_NS::TestRunner testrunner;

    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());

    testrunner.run(testresult);

    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();
    
    ofstream xmlFileOut("cppTestBasicMathResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut); 
    xmlOut.write();

    return collectedresults.wasSuccessful() ? 0 : 1;
}
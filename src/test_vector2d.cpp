#include <cppunit/TestFixture.h>

#include <vector2d.h>

using namespace CppUnit;
using namespace std;

class TestVector2d : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestVector2d);
    CPPUNIT_TEST(testConstructor);
    CPPUNIT_TEST(testAddition);

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testConstructor(void);
    void testAddition(void);
}
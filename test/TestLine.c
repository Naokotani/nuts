#include "../src/Line.h"
#include "unity.h"
#include "unity_fixture.h"

Line *line1;
Line *line2;
Line *line3;

TEST_GROUP(Line);

TEST_SETUP(Line) {
  line1 = initLine(1);
  line2 = initLine(2);
  line3 = initLine(3);
}

TEST_TEAR_DOWN(Line) {
  freeLine(line1);
  freeLine(line2);
  freeLine(line3);
}

TEST(Line, TestLineInitialized) {
  TEST_ASSERT_EQUAL(1, line1->lineNum);
  TEST_ASSERT_EQUAL(2, line2->lineNum);
  TEST_ASSERT_EQUAL(3, line3->lineNum);
}

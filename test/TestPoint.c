#include "../src/Buffer.h"
#include "../src/Line.h"
#include "../src/Point.h"
#include "unity.h"
#include "unity_fixture.h"

Point *point1;
Point *point2;
Point *point3;

TEST_GROUP(Point);

TEST_SETUP(Point) {
  Buffer *buffer1 = initBuffer((char *)"test");
  Buffer *buffer2 = initBuffer((char *)"test1");
  Buffer *buffer3 = initBuffer((char *)"test2");

  Line *line1 = initLine(1);
  Line *line2 = initLine(2);
  Line *line3 = initLine(3);

  point1 = initPoint(buffer1, line1);
  point2 = initPoint(buffer2, line2);
  point3 = initPoint(buffer3, line3);
}

TEST_TEAR_DOWN(Point) {
  freeLine(point1->line);
  freeBuffer(point1->buffer);
  freePoint(point1);
  freeLine(point2->line);
  freeBuffer(point2->buffer);
  freePoint(point2);
  freeLine(point3->line);
  freeBuffer(point3->buffer);
  freePoint(point3);
}

TEST(Point, TestLineInitialized) {
  TEST_ASSERT_EQUAL(0, point1->col);
  TEST_ASSERT_EQUAL(1, point1->line->lineNum);
  TEST_ASSERT_EQUAL_STRING("test", point1->buffer->name);

  TEST_ASSERT_EQUAL(0, point2->col);
  TEST_ASSERT_EQUAL(2, point2->line->lineNum);
  TEST_ASSERT_EQUAL_STRING("test1", point2->buffer->name);

  TEST_ASSERT_EQUAL(0, point3->col);
  TEST_ASSERT_EQUAL(3, point3->line->lineNum);
  TEST_ASSERT_EQUAL_STRING("test2", point3->buffer->name);
}

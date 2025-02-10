#include "../src/Buffer.h"
#include "unity.h"
#include "unity_fixture.h"

Buffer *buffer1;
Buffer *buffer2;
Buffer *buffer3;

TEST_GROUP(Buffer);

TEST_SETUP(Buffer) {
  buffer1 = initBuffer((char *)"foo");
  buffer2 = initBuffer((char *)"bar");
  buffer3 = initBuffer((char *)"baz");
}

/* Ensure buffers are freed */
TEST_TEAR_DOWN(Buffer) {
  freeBuffer(buffer1);
  freeBuffer(buffer2);
  freeBuffer(buffer3);
}

/* Test to ensure buffer is initialized and the name is correct. */
TEST(Buffer, TestBufferIniatialzed) {
  TEST_ASSERT_EQUAL_STRING("foo", buffer1->name);
  TEST_ASSERT_EQUAL_STRING("bar", buffer2->name);
  TEST_ASSERT_EQUAL_STRING("baz", buffer3->name);
}

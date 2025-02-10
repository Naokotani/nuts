#include "../src/Buffer.h"
#include "unity.h"
#include "unity_fixture.h"

Buffer buffer1;
Buffer buffer2;
Buffer buffer3;

TEST_GROUP(Buffer);

TEST_SETUP(Buffer) {
  char buffName1[] = "foo";
  char buffName2[] = "bar";
  char buffName3[] = "baz";

  buffer1 = initBuffer(buffName1);
  buffer2 = initBuffer(buffName2);
  buffer3 = initBuffer(buffName3);
}

/* Ensure buffers are freed */
TEST_TEAR_DOWN(Buffer) {}

/* Test to ensure buffer is initialized and the name is correct. */
TEST(Buffer, TestBufferIniatialzed) {
  TEST_ASSERT_EQUAL_STRING("foo", buffer1.name);
  TEST_ASSERT_EQUAL_STRING("bar", buffer2.name);
  TEST_ASSERT_EQUAL_STRING("baz", buffer3.name);
}

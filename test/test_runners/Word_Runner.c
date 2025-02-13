#include "../unity_fixture.h"

TEST_GROUP_RUNNER(Word) {
  RUN_TEST_CASE(Word, TestWordInitialized);
  RUN_TEST_CASE(Word, TestCharAdded);
}

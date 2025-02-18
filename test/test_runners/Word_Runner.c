#include "../unity_fixture.h"

TEST_GROUP_RUNNER(Word) {
  RUN_TEST_CASE(Word, CharAdded);
  RUN_TEST_CASE(Word, CharDeleted);
  RUN_TEST_CASE(Word, AddString);
  RUN_TEST_CASE(Word, DeleteRegion);
  RUN_TEST_CASE(Word, AddStringExample);
  RUN_TEST_CASE(Word, AddCharExample);
  RUN_TEST_CASE(Word, DelCharExample);
  RUN_TEST_CASE(Word, DelRegionExample);
}

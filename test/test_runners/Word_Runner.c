#include "../unity_fixture.h"

TEST_GROUP_RUNNER(Word) {
  RUN_TEST_CASE(Word, WordInitialized);
  RUN_TEST_CASE(Word, CharAdded);
  RUN_TEST_CASE(Word, CharDeleted);
  RUN_TEST_CASE(Word, AddString);
  RUN_TEST_CASE(Word, DeleteRegion);
}

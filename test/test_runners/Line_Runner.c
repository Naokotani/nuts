#include "../unity_fixture.h"

TEST_GROUP_RUNNER(Line) {
  RUN_TEST_CASE(Line, LineInitialized);
  RUN_TEST_CASE(Line, AddWord);
}

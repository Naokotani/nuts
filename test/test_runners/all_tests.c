/* =========================================================================
    Unity - A Test Framework for C
    ThrowTheSwitch.org
    Copyright (c) 2007-25 Mike Karlesky, Mark VanderVoord, & Greg Williams
    SPDX-License-Identifier: MIT
========================================================================= */

#include "../unity_fixture.h"

static void RunAllTests(void) {
  RUN_TEST_GROUP(Buffer);
  RUN_TEST_GROUP(Line);
  RUN_TEST_GROUP(Word);
  RUN_TEST_GROUP(Point);
}

int main(int argc, const char *argv[]) {
  return UnityMain(argc, argv, RunAllTests);
}

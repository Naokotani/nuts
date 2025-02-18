#include "../src/Line.h"
#include "../src/Word.h"
#include "unity.h"
#include "unity_fixture.h"
#include <stdio.h>

Line *line1, *line2, *line3;

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

TEST(Line, LineInitialized) {
  TEST_ASSERT_EQUAL(1, line1->lineNum);
  TEST_ASSERT_EQUAL(2, line2->lineNum);
  TEST_ASSERT_EQUAL(3, line3->lineNum);
}

TEST(Line, AddWord) {
  Word *word1;
  Word *word2;
  Word *word3;
  Word *word4;
  Word *word5;

  word1 = initWord();
  word2 = initWord();
  word3 = initWord();
  word4 = initWord();
  word5 = initWord();

  addString((char *)"Hello", 0, 0, word1);
  addString((char *)",", 0, 0, word2);
  addString((char *)" ", 0, 0, word3);
  addString((char *)"World", 0, 0, word4);
  addString((char *)"!", 0, 0, word5);

  appendWord(word1, line1);
  TEST_ASSERT_EQUAL_STRING("Hello", getLast(line1)->string);

  putchar('\n');
  printLine(line1);
  appendWord(word2, line1);
  TEST_ASSERT_EQUAL_STRING(",", getLast(line1)->string);

  printLine(line1);
  appendWord(word3, line1);
  TEST_ASSERT_EQUAL_STRING(" ", getLast(line1)->string);

  printLine(line1);
  appendWord(word4, line1);
  TEST_ASSERT_EQUAL_STRING("World", getLast(line1)->string);

  printLine(line1);
  appendWord(word5, line1);
  TEST_ASSERT_EQUAL_STRING("!", getLast(line1)->string);

  printLine(line1);
}

#include "../src/Line.h"
#include "../src/Word.h"
#include "unity.h"
#include "unity_fixture.h"

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
  Word *word1, *word2, *word3, *word4, *word5, *move;

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

  appendWord(word2, line1);
  TEST_ASSERT_EQUAL_STRING(",", getLast(line1)->string);
  TEST_ASSERT_EQUAL_STRING("Hello", getLast(line1)->prev->string);

  appendWord(word3, line1);
  TEST_ASSERT_EQUAL_STRING(" ", getLast(line1)->string);
  TEST_ASSERT_EQUAL_STRING(",", getLast(line1)->prev->string);

  appendWord(word4, line1);
  TEST_ASSERT_EQUAL_STRING("World", getLast(line1)->string);
  TEST_ASSERT_EQUAL_STRING(" ", getLast(line1)->prev->string);

  appendWord(word5, line1);
  TEST_ASSERT_EQUAL_STRING("!", getLast(line1)->string);
  TEST_ASSERT_EQUAL_STRING("World", getLast(line1)->prev->string);

  putchar('\n');
  printLine(line1);

  move = forwardWord(line1->head);
  TEST_ASSERT_EQUAL_STRING(",", move->string);

  move = forwardWord(move);
  TEST_ASSERT_EQUAL_STRING(" ", move->string);

  move = forwardWord(move);
  TEST_ASSERT_EQUAL_STRING("World", move->string);

  move = forwardWord(move);
  TEST_ASSERT_EQUAL_STRING("!", move->string);

  move = forwardWord(move);
  TEST_ASSERT_EQUAL_STRING("!", move->string);

  move = backWord(move);
  TEST_ASSERT_EQUAL_STRING("World", move->string);

  move = backWord(move);
  TEST_ASSERT_EQUAL_STRING(" ", move->string);

  move = backWord(move);
  TEST_ASSERT_EQUAL_STRING(",", move->string);

  move = forwardWord(move);
  TEST_ASSERT_EQUAL_STRING(" ", move->string);

  move = removeWord(line1, move);
  TEST_ASSERT_EQUAL_STRING("World", move->string);

  move = removeWord(line1, move);
  TEST_ASSERT_EQUAL_STRING("!", move->string);

  move = removeWord(line1, move);
  TEST_ASSERT_EQUAL_STRING(",", move->string);

  move = removeWord(line1, move);
  TEST_ASSERT_EQUAL_STRING("Hello", move->string);

  Word *newWord = initWord();
  addString((char *)"There", 0, 0, newWord);

  appendWord(newWord, line1);
  TEST_ASSERT_EQUAL_STRING("There", getLast(line1)->string);

  move = forwardWord(move);
  TEST_ASSERT_EQUAL_STRING("There", move->string);

  Word *space = initWord();
  Word *comma = initWord();
  Word *bang = initWord();
  addChar(' ', 0, space);
  addChar(',', 0, comma);
  addChar('!', 0, bang);

  move = insertWord(line1, space, move);
  TEST_ASSERT_EQUAL_STRING(" ", move->string);

  move = insertWord(line1, comma, move);
  appendWord(bang, line1);

  printLine(line1);
}

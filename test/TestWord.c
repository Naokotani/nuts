#include "../src/Word.h"
#include "unity.h"
#include "unity_fixture.h"

Word *word1;
Word *word2;
Word *word3;

TEST_GROUP(Word);

TEST_SETUP(Word) {
  word1 = initWord('H');
  word2 = initWord(' ');
  word3 = initWord('W');
}

TEST_TEAR_DOWN(Word) {
  freeWord(word1);
  freeWord(word2);
  freeWord(word3);
}

TEST(Word, TestWordInitialized) {
  TEST_ASSERT_EQUAL_STRING("H", word1->string);
  TEST_ASSERT_EQUAL_STRING(" ", word2->string);
  TEST_ASSERT_EQUAL_STRING("W", word3->string);
}

TEST(Word, TestCharAdded) {
  TEST_ASSERT_EQUAL_STRING("He", word1->string = addChar('e', 1, word1));
  TEST_ASSERT_EQUAL_STRING("Hel", word1->string = addChar('l', 2, word1));
  TEST_ASSERT_EQUAL_STRING("Helo", word1->string = addChar('o', 3, word1));
  TEST_ASSERT_EQUAL_STRING("Hello", word1->string = addChar('l', 3, word1));
  TEST_ASSERT_EQUAL_STRING("Hello,", word1->string = addChar(',', 5, word1));
  TEST_ASSERT_EQUAL_STRING("W!", word3->string = addChar('!', 1, word3));
  TEST_ASSERT_EQUAL_STRING("Wd!", word3->string = addChar('d', 1, word3));
  TEST_ASSERT_EQUAL_STRING("Wld!", word3->string = addChar('l', 1, word3));
  TEST_ASSERT_EQUAL_STRING("Wrld!", word3->string = addChar('r', 1, word3));
  TEST_ASSERT_EQUAL_STRING("World!", word3->string = addChar('o', 1, word3));
  TEST_ASSERT_EQUAL_STRING("!World!", word3->string = addChar('!', 0, word3));
}

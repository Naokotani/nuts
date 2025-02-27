#include "../src/Word.h"
#include "unity.h"
#include "unity_fixture.h"

Word *word1, *word2, *word3;

TEST_GROUP(Word);

TEST_SETUP(Word) {
  word1 = initWord();
  word2 = initWord();
  word3 = initWord();
}

TEST_TEAR_DOWN(Word) {
  freeWord(word1);
  freeWord(word2);
  freeWord(word3);
}

TEST(Word, CharAdded) {
  TEST_ASSERT_EQUAL_STRING("H", word1->string = addChar('H', 0, word1));
  TEST_ASSERT_EQUAL_STRING("He", word1->string = addChar('e', 1, word1));
  TEST_ASSERT_EQUAL_STRING("Hel", word1->string = addChar('l', 2, word1));
  TEST_ASSERT_EQUAL_STRING("Helo", word1->string = addChar('o', 3, word1));
  TEST_ASSERT_EQUAL_STRING("Hello", word1->string = addChar('l', 3, word1));
  TEST_ASSERT_EQUAL_STRING("Hello,", word1->string = addChar(',', 5, word1));
  TEST_ASSERT_EQUAL_STRING("Hello,!", word1->string = addChar('!', 6, word1));
  TEST_ASSERT_EQUAL_STRING("Hello,!!", word1->string = addChar('!', 7, word1));
  TEST_ASSERT_EQUAL_STRING("Hello,!!!", word1->string = addChar('!', 8, word1));
  TEST_ASSERT_EQUAL_STRING("Hello,!!!!",
                           word1->string = addChar('!', 9, word1));
  TEST_ASSERT_EQUAL_STRING("Hello,!!!!!",
                           word1->string = addChar('!', 10, word1));
  TEST_ASSERT_EQUAL_STRING("Hello,!!!!!!",
                           word1->string = addChar('!', 11, word1));
  TEST_ASSERT_EQUAL_STRING("W", word3->string = addChar('W', 0, word3));
  TEST_ASSERT_EQUAL_STRING("W!", word3->string = addChar('!', 1, word3));
  TEST_ASSERT_EQUAL_STRING("Wd!", word3->string = addChar('d', 1, word3));
  TEST_ASSERT_EQUAL_STRING("Wld!", word3->string = addChar('l', 1, word3));
  TEST_ASSERT_EQUAL_STRING("Wrld!", word3->string = addChar('r', 1, word3));
  TEST_ASSERT_EQUAL_STRING("World!", word3->string = addChar('o', 1, word3));
  TEST_ASSERT_EQUAL_STRING("!World!", word3->string = addChar('!', 0, word3));
}

TEST(Word, CharDeleted) {
  TEST_ASSERT_EQUAL_STRING("H", word1->string = addChar('H', 0, word1));
  TEST_ASSERT_EQUAL_STRING("He", word1->string = addChar('e', 1, word1));
  TEST_ASSERT_EQUAL_STRING("Hel", word1->string = addChar('l', 2, word1));
  TEST_ASSERT_EQUAL_STRING("Helo", word1->string = addChar('o', 3, word1));
  TEST_ASSERT_EQUAL_STRING("Hello", word1->string = addChar('l', 3, word1));
  TEST_ASSERT_EQUAL_STRING("Hello,", word1->string = addChar(',', 5, word1));
  TEST_ASSERT_EQUAL_STRING("Hello", word1->string = delChar(5, word1));
  TEST_ASSERT_EQUAL_STRING("Hllo", word1->string = delChar(1, word1));
  TEST_ASSERT_EQUAL_STRING("llo", word1->string = delChar(0, word1));
  TEST_ASSERT_EQUAL_STRING("Hllo", word1->string = addChar('H', 0, word1));
  TEST_ASSERT_EQUAL_STRING("Hello", word1->string = addChar('e', 1, word1));
  TEST_ASSERT_EQUAL_STRING("Hello,", word1->string = addChar(',', 5, word1));
}

TEST(Word, AddString) {
  TEST_ASSERT_EQUAL_STRING("H", word1->string = addChar('H', 0, word1));
  TEST_ASSERT_EQUAL_STRING("He", word1->string = addChar('e', 1, word1));
  TEST_ASSERT_EQUAL_STRING("Hel", word1->string = addChar('l', 2, word1));
  TEST_ASSERT_EQUAL_STRING("Helo", word1->string = addChar('o', 3, word1));
  TEST_ASSERT_EQUAL_STRING("Hello", word1->string = addChar('l', 3, word1));
  TEST_ASSERT_EQUAL_STRING(
      "Heltherelo", word1->string = addString((char *)"there", 3, 3, word1));
  TEST_ASSERT_EQUAL_STRING(
      "Helthereloboo", word1->string = addString((char *)"boo", 10, 10, word1));
  TEST_ASSERT_EQUAL_STRING(
      "Helsnareloboo", word1->string = addString((char *)"snare", 3, 8, word1));
}

TEST(Word, DeleteRegion) {
  TEST_ASSERT_EQUAL_STRING("Hello!", addString((char *)"Hello!", 0, 0, word1));
  TEST_ASSERT_EQUAL_STRING("He!", delRegion(2, 5, word1));
  TEST_ASSERT_EQUAL_STRING("He", delChar(2, word1));
  TEST_ASSERT_EQUAL_STRING("Hercules",
                           addString((char *)"rcules", 2, 2, word1));
  // this test actual fails so it returns the input.
  TEST_ASSERT_EQUAL_STRING("Hercules", delRegion(3, 9, word1));
  TEST_ASSERT_EQUAL_STRING("Her", delRegion(3, 8, word1));
}

TEST(Word, AddStringExample) {
  TEST_ASSERT_EQUAL_STRING("Hear", addString((char *)"Hear", 0, 0, word1));
  TEST_ASSERT_EQUAL_STRING("Hello", addString((char *)"llo", 2, 4, word1));
}

TEST(Word, AddCharExample) {
  TEST_ASSERT_EQUAL_STRING("Hs", addString((char *)"Hs", 0, 0, word1));
  TEST_ASSERT_EQUAL_STRING("His", addChar('i', 1, word1));
}

TEST(Word, DelCharExample) {
  TEST_ASSERT_EQUAL_STRING("Her", addString((char *)"Her", 0, 0, word1));
  TEST_ASSERT_EQUAL_STRING("He", delChar(2, word1));
}

TEST(Word, DelRegionExample) {
  TEST_ASSERT_EQUAL_STRING("Peanuts",
                           addString((char *)"Peanuts", 0, 0, word1));
  TEST_ASSERT_EQUAL_STRING("nuts", delRegion(0, 3, word1));
}

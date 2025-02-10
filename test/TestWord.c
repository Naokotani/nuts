#include "../src/Word.h"
#include "unity.h"
#include "unity_fixture.h"

Word *word1;
Word *word2;
Word *word3;

TEST_GROUP(Word);

TEST_SETUP(Word) {
  word1 = initWord((char *)"Hello,");
  word2 = initWord((char *)" ");
  word3 = initWord((char *)"World!");
}

TEST_TEAR_DOWN(Word) {
  freeWord(word1);
  freeWord(word2);
  freeWord(word3);
}

TEST(Word, TestWordInitialized) {
  TEST_ASSERT_EQUAL_STRING("Hello,", word1->string);
  TEST_ASSERT_EQUAL_STRING(" ", word2->string);
  TEST_ASSERT_EQUAL_STRING("World!", word3->string);
}

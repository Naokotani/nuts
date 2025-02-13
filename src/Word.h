#include "Types.h"
#ifndef WORD
#define WORD

Word *initWord(char c);
void freeWord(Word *word);
char *addChar(char c, size_t index, Word *word);
#endif

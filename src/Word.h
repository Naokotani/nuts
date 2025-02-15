#include "Types.h"
#ifndef WORD
#define WORD

Word *initWord(char c);
void freeWord(Word *word);
char *addChar(char c, int index, Word *word);
#endif

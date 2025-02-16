#include "Types.h"
#ifndef WORD
#define WORD

Word *initWord(void);
void freeWord(Word *word);
char *addChar(char c, int index, Word *word);
char *delChar(int index, Word *word);
char *addString(char *string, int start, int end, Word *word);
char *delRegion(int start, int end, Word *word);
#endif

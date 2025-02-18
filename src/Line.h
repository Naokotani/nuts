#include "Types.h"
#ifndef LINE
#define LINE

Line *initLine(int lineNum);
void freeLine(Line *line);
Line *appendWord(Word *word, Line *line);
void printLine(Line *line);
Word *getLast(Line *line);
Word *forwardWord(Word *word);
Word *backWord(Word *word);
Word *removeWord(Line *line, Word *word);
Word *insertWord(Line *line, Word *word, Word *loc);

#endif

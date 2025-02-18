#include "Types.h"
#ifndef LINE
#define LINE

Line *initLine(int lineNum);
void freeLine(Line *line);
Line *appendWord(Word *word, Line *line);
void printLine(Line *line);
Word *getLast(Line *line);

#endif

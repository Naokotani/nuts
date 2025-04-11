#ifndef BUFFER
#define BUFFER
#include "Types.h"

Buffer *initBuffer(char *name);
void freeBuffer(Buffer *buffer);
void printBuffer(Buffer *buffer);

// Insert and remove.
Line *appendLine(Line *line, Buffer *buffer);
Line *insertLine(Line *line, Buffer *buffer, Line *loc);
Line *removeLine(Line *line, Buffer *buffer);

// navigation
Line *getLastLine(Buffer *buffer);
Line *nextLine(Line *line);
Line *previousLine(Line *line);

// utility
int wordCount(Buffer *buffer);
int lineCount(Buffer *buffer);
int charCount(Buffer *buffer);

#endif

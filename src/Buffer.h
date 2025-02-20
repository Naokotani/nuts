#ifndef BUFFER
#define BUFFER
#include "Types.h"

Buffer *initBuffer(char *name);
void freeBuffer(Buffer *buffer);

// Insert and remove.
Line *appendLine(Line *line, Buffer *buffer);
Line *insertLine(Line *line, Buffer *buffer);
Line *removeLine(Line *line, Buffer *buffer);

// navigation
Line *getLastLine(Buffer *buffer);
Line *nextLine(Buffer *buffer);
Line *previousLine(Buffer *buffer);

// utility
int wordCount(Buffer *buffer);
int lineCount(Buffer *buffer);
int charCount(Buffer *buffer);

#endif

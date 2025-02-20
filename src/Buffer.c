#include "Buffer.h"
#include "Line.h"
#include "Types.h"
#include <string.h>

/*
Functions for initalizing, destroying and maninpulating `Buffer`.

 TODO: old struct, update

typedef struct Buffer {
  Line *fl;   // First line in the buffer.
  Line *ll;   // Last line in the buffer.
  int nl;     // Total number of lines in the buffer.
  int nw;     // Total number of words in the buffer.
  int nc;     // Total number of characterse in the buffer.
  char *name; // Name of the buffer.
  char *path; // file path associated with the buffer. This is optional.
} Buffer;

Buffers represent the largest building block of the text editing interface. They
are composed of Lines and words. A buffer may optionally be pointed to buy
a 'Point' which represents the users position in NUTS.

*/

Buffer *initBuffer(char *name) {
  Buffer *buffer = malloc(sizeof(Buffer));
  buffer->head = NULL;
  buffer->size = 0;
  buffer->name = calloc(strlen(name) + 1, sizeof(char));
  strcpy(buffer->name, name);
  buffer->path = NULL;
  return buffer;
}

void freeBuffer(Buffer *buffer) {
  free(buffer->name);
  if (buffer->path != NULL) {
    free(buffer->path);
  }
  Line *freeLine;
  Line *currLine = buffer->head;
  while (currLine != NULL) {
    freeLine = currLine;
    // TODO use freeLine function
    free(freeLine);
    currLine = currLine->next;
  }
  free(buffer);
}

Line *appendLine(Line *line, Buffer *buffer) {
  if (!line->head) {
    buffer->head = line;
  } else {
    Line *curr, *prev;
    curr = prev = buffer->head;
    while ((curr = curr->next)) {
      if (curr->next == NULL)
        prev = curr;
    }

    prev->next = line;
    line->prev = prev;
  }

  buffer->size++;
  return line;
}

Line *insertLine(Line *line, Buffer *buffer, Line *loc) {
  if (loc->prev) {
    // If loc is not the first word in the list.
    line->prev = loc->prev;
    line->next = loc;
    loc->prev->next = line;
    loc->prev = line;
    // If loc is the first word in the list.
  } else {
    line->prev = NULL;
    loc->prev = line;
    line->next = loc;
  }

  buffer->size++;
  return line;
}

Line *removeLine(Line *line, Buffer *buffer) {
  Line *next, *prev, *move;
  prev = line->prev;
  next = line->next;

  if (line->next)
    move = line->next;
  else if (line->prev)
    move = line->prev;
  else
    move = NULL;

  if (next && prev) {
    prev->next = next;
    next->prev = prev;
  } else if (next) {
    buffer->head = next;
    next->prev = NULL;
  } else if (prev) {
    prev->next = NULL;
  } else if (!next && !prev) {
    buffer->head = NULL;
  }

  freeLine(line);

  buffer->size--;
  return move;
}

Line *getLastLine(Buffer *buffer) {
  Line *line;
  if (!buffer->head->next)
    line = buffer->head;

  Line *curr = buffer->head;
  while ((curr = curr->next))
    if (!curr->next)
      line = curr;

  return line;

  return buffer->head;
}

Line *nextLine(Line *line) {
  if (line->next)
    return line->next;
  else
    return line;
}

Line *prevLine(Line *line) {
  if (line->prev)
    return line->prev;
  else
    return line;
}

// TODO:
int wordCount(Buffer *buffer) { return 0; }
// TODO:
int lineCount(Buffer *buffer) { return 0; }
// TODO:
int charCount(Buffer *buffer) { return 0; }

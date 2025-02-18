#include "Buffer.h"
#include "Types.h"
#include <string.h>

/*
Functions for initalizing, destroying and maninpulating `Buffer`.

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
  buffer->nl = 0;
  buffer->nc = 0;
  buffer->nw = 0;
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

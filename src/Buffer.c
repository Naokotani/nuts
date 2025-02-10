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

Buffer initBuffer(char *name) {
  Buffer buffer;
  buffer.fl = NULL;
  buffer.ll = NULL;
  buffer.nl = 0;
  buffer.nc = 0;
  buffer.nw = 0;
  buffer.name = malloc(sizeof(char) * strlen(name));
  strcpy(buffer.name, name);
  buffer.path = NULL;
  return buffer;
}

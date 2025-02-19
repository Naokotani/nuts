#include <stdbool.h>
#include <stdlib.h>
#define CHAR_BUFFER 5

#ifndef TYPES
#define TYPES

typedef struct Word {
  char *string;      // The character sequence that compreises the word.
  unsigned int size; // Number of characters in the word.
  struct Word *next; // Next word in the line.
  struct Word *prev; // Previous word in the line.
  bool whiteSpace;   // Is the word whitespace? (tabs and/or spaces)
} Word;

typedef struct Line {
  Word *head;        // First word in the line.
  unsigned int size; // Number of Words in list
  struct Line *next; // Pointer to the next line in the buffer.
  struct Line *prev; // Pointer to the previous line in the buffer.
  int lineNum;       // currect line number
} Line;

typedef struct Buffer {
  Line *head; // First line in the buffer.
  int nl;     // Total number of lines in the buffer.
  char *name; // Name of the buffer.
  char *path; // file path associated with the buffer.
} Buffer;

typedef struct Point {
  Buffer *buffer; // Buffer the point is currently located in.
  Line *line;     // Line where the point is located.
  int col;        // Character where the point is located
} Point;

#endif

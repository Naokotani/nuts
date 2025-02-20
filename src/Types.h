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
  int size;   // Total number of lines in the buffer.
  char *name; // Name of the buffer.
  char *path; // file path associated with the buffer.
} Buffer;

typedef struct Point {
  Buffer *buffer; // Buffer the point is currently located in.
  Line *line;     // Line where the point is located.
  Word *word;     // `Word` where the point is located.
  int strIndex;   // Index of the points location is located (IE string[i]).
  int col; // The column the point is located in. Determined as a sum of the
           // `Word` sizes before the current word + `strIndex` + 1. The plus
           // one accounts for 0 index, while `Word->size` is an absolute size).
} Point;

/*
Conecpt of "Region" similar to vi "visual mode" or Emacs region. The beginning
refers to the lowest `Line` > `Word` > `Word->string` value in that order of
precedence, with the end being the highest `Line` > `Word` > `Word->string` in
the same order of precedence.

For example: line 3 word 4 char 4 would refer to, starting from the top of the
screen, the 4th line (index 0, 1 etc.), from the left of the screen the 5th word
and from the beginneing of the 5th word the 5th character (IE. Word->string[5]).
 */
typedef struct Region {
  Point beginning;
  Point end;
} Region;

#endif

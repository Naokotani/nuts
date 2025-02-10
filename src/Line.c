#include "Line.h"
#include "Types.h"

/*
  Functions for initalizing, destroying and manipulating `Line`:

  typedef struct Line {
    Word *first;       // First word in the line.
    Word *last;        // Last word in the line.
    struct Line *next; // Pointer to the next line in the buffer.
    struct Line *prev; // Pointer to the previous line in the buffer.
    int lineNum;       // currect line number
  } Line;

  A line is the larger construct in a buffer. It represents a line in the file
  and stores information about the line number, the location of the first and
  last word on the line and the next and previous lines in the buffer. The next
  line represents line down in the buffer and the prev line represents a line up
  in the buffer.
*/

Line *initLine(int linNum) {
  Line *line = malloc(sizeof(Line));
  line->fw = NULL;
  line->lw = NULL;
  line->next = NULL;
  line->prev = NULL;
  line->lineNum = linNum;
  return line;
}

void freeLine(Line *line) {
  if (line->fw != NULL) {
    Word *freeWord;
    Word *currWord = line->fw;
    while (currWord != NULL) {
      freeWord = currWord;
      // user freeWord() function
      free(freeWord);
      currWord = currWord->next;
    }
  }
  free(line);
}

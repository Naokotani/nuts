#include "Line.h"
#include "Types.h"
#include "Word.h"
#include <stdio.h>

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

Line *appendWord(Word *word, Line *line) {
  if (line->fw == NULL) {
    line->fw = word;
    line->lw = word;
    return line;
  } else {
  }

  return line;
}

void printLine(Line *line) {
  int i = 0;
  for (Word *ptr = line->fw;; ptr = ptr->next) {
    printf("%s", ptr->string);
    if (ptr->next == NULL || i > 10)
      break;

    i++;
  }
  printf("\n");
}

void freeLine(Line *line) {
  if (line->fw != NULL) {
    // Word *fWord;
    // Word *currWord = line->fw;
    // while (currWord != NULL) {
    //   fWord = currWord;
    //   freeWord(fWord);
    //   currWord = currWord->next;
    // }
  }
  free(line);
}

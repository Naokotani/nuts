#include "Line.h"
#include "Types.h"
#include "Word.h"
#include <stdio.h>

/*
  Functions for initalizing, destroying and manipulating `Line`:

  typedef struct Line {
    Word *head;        // First word in the line.
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
  line->head = NULL;
  line->next = NULL;
  line->prev = NULL;
  line->lineNum = linNum;
  return line;
}

Line *appendWord(Word *word, Line *line) {
  if (!line->head) {
    line->head = word;
  } else {
    Word *curr, *prev;
    curr = prev = line->head;
    while ((curr = curr->next)) {
      if (curr->next == NULL)
        prev = curr;
    }

    prev->next = word;
    word->prev = prev;
  }

  return line;
}

Word *getLast(Line *line) {
  Word *word;
  if (!line->head->next)
    word = line->head;

  Word *curr = line->head;
  while ((curr = curr->next))
    if (!curr->next)
      word = curr;

  return word;
}

Word *forwardWord(Word *word) {
  if (word->next)
    return word->next;
  else
    return word;
}

Word *backWord(Word *word) {
  if (word->prev)
    return word->prev;
  else
    return word;
}

void printLine(Line *line) {
  int i = 0;
  for (Word *ptr = line->head;; ptr = ptr->next) {
    printf("%s", ptr->string);
    if (ptr->next == NULL)
      break;

    i++;
  }
  printf("\n");
}

void freeLine(Line *line) {
  while (line->head) {
    Word *ptr = line->head;
    line->head = line->head->next;
    free(ptr->string);
    free(ptr);
  }
  free(line);
}

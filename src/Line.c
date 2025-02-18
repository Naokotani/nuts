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

/*
Appeneds a word to a line by adding a node to the doubly linked list of `Word`
that the `Line` points to. `Line`.

Example: appendWord(exampleWord, exampleLine);
*/
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

// Gets the last node in the linked list.
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

// Given a `Word` move to the next `Word` in the list of words. If `Word` is the
// final word, return the argument directly.
Word *forwardWord(Word *word) {
  if (word->next)
    return word->next;
  else
    return word;
}

// Given a `Word` move to the previous `Word` in the list of words. If `Word` is
// the first word(IE. line->head), return the argument directly.
Word *backWord(Word *word) {
  if (word->prev)
    return word->prev;
  else
    return word;
}

/*
Remove a `Word` from the linked list. Checks if it is at the beginning, middle
or end of the list and sets next/prev to or to the appropriate nodes.

example: removeWord(exampleLine, exampleWord);

*/
Word *removeWord(Line *line, Word *word) {
  Word *next, *prev, *move;
  prev = word->prev;
  next = word->next;

  if (word->next)
    move = word->next;
  else if (word->prev)
    move = word->prev;
  else
    move = NULL;

  if (next && prev) {
    prev->next = next;
    next->prev = prev;
  } else if (next) {
    line->head = next;
    next->prev = NULL;
  } else if (prev) {
    prev->next = NULL;
  } else if (!next && !prev) {
    line->head = NULL;
  }

  freeWord(word);

  return move;
}

Word *insertWord(Line *line, Word *word, Word *loc) {
  if (loc->prev) {
    // Set new words prev and next.
    word->prev = loc->prev;
    word->next = loc;

    // Set locs old previous' new next.
    loc->prev->next = word;
    // Set locs new prevoius
    loc->prev = word;
  } else {
    word->prev = NULL;
    loc->prev = word;
    word->next = loc;
  }

  return word;
}

// Prints all nodes in a linked list. Should be mostly for debuggin.
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

// Frees the line and all words contained in the line, add all strings in the
// words.
void freeLine(Line *line) {
  while (line->head) {
    Word *ptr = line->head;
    line->head = line->head->next;
    freeWord(ptr);
  }
  free(line);
}

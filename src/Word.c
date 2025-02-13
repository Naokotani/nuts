#include "Word.h"
#include "Types.h"
#include <cstdlib>
#include <stdlib.h>
#include <string.h>

/*
Functions for initalizing, destroying and maniputing a 'Word':

typedef struct Word {
  char *string;      // The character sequence that compreises the word.
  unsigned int size; // Number of characters in the word.
  struct Word *next; // Next word in the line.
  struct Word *prev; // Previous word in the line.
  bool whiteSpace;   // Is the word whitespace? (tabs and/or spaces)
} Word;

A `Word` smaller construct in a `Buffer`. A `Line` is composed of 0
or more words which can be either whitespace or characters. words are initilized
as white space and `whiteSpace` is set to false after a non whitespace character
is added. If a white space character or a new line is added, the word ends and a
new white space begins in vice versa.
*/

Word *initWord(char *c) {
  Word *word = malloc(sizeof(Word));
  word->size = strlen(c) + 1;
  word->string = calloc(CHAR_BUFFER, sizeof(char));
  strcpy(word->string, c);
  word->next = NULL;
  word->prev = NULL;
  return word;
}

char *addChar(char c, int index, Word *word) {
  char *newString;
  if (word->size % CHAR_BUFFER == 0) {
    newString = calloc(word->size + CHAR_BUFFER, sizeof(char));
    word->string =
        reallocarray(word->string, word->size + CHAR_BUFFER, sizeof(char));
  } else {
    newString = calloc(word->size, sizeof(char));
  }

  int i = 0;
  while ((*newString++ = *word->string++) != '\0' && i < index)
    i++;

  newString[index + 1] = c;

  return word->string;
}

void freeWord(Word *word) {
  free(word->string);
  free(word);
}

#include "Types.h"
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

Word initWord(char *c) {
  Word word;
  word.size = strlen(c);
  word.string = calloc(word.size, sizeof(char));
  strcpy(word.string, c);
  word.next = NULL;
  word.prev = NULL;
  return word;
}

#include "Word.h"
#include "Types.h"
#include <stddef.h>
#include <stdio.h>
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

Word *initWord(char c) {
  Word *word = malloc(sizeof(Word));
  word->size = 2;
  word->string = calloc(CHAR_BUFFER, sizeof(char));
  word->string[0] = c;
  word->string[1] = '\0';
  word->next = NULL;
  word->prev = NULL;
  return word;
}

char *addChar(char c, size_t index, Word *word) {
  char *newString =
      malloc(sizeof(char) * ((word->size + 1 / CHAR_BUFFER) + 1) * CHAR_BUFFER);
  char *incString = newString;
  char *oldString = word->string;

  size_t i = 0;
  while (i < index && (*incString++ = *oldString++))
    i++;

  newString[index] = c;

  if (index < word->size) {
    incString++;
    while ((*incString++ = *oldString++) != '\0')
      ;
  } else if (index == word->size) {

  } else {
    perror("Not enough space in word");
  }
  incString[index + 2] = '\0';
  word->size += 1;
  strcpy(word->string, newString);
  free(newString);
  return word->string;
}

void freeWord(Word *word) {
  free(word->string);
  free(word);
}

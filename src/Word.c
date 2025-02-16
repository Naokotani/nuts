#include "Word.h"
#include "Types.h"
#include <malloc.h>
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

size_t getNmemb(size_t size_t);

Word *initWord(char c) {
  Word *word = malloc(sizeof(Word));
  word->size = 2;
  word->string = malloc(CHAR_BUFFER * sizeof(char));
  word->string[0] = c;
  word->string[1] = '\0';
  word->next = NULL;
  word->prev = NULL;
  return word;
}

char *addString(char *string, int start, int end, Word *word) {
  if (end < start) {
    perror("String start cannot be less than end");
    return word->string;
  }
  int strLength = strlen(string);
  int length = end - start;
  /*
   NOTE: This calculation is word size + the length of the new string - length,
   which is the part of the old string being copied over.
  */
  size_t nmemb =
      ((word->size + strLength - length) / CHAR_BUFFER + 1) * CHAR_BUFFER;
  char *newString = malloc(nmemb * sizeof(char));
  char *incNew = newString;
  char *incOld = word->string;

  int i = start;
  int index = 0;
  while (i-- && (*incNew++ = *incOld++))
    index++;

  while ((*incNew++ = *string++))
    ;

  incOld += length;
  index += length;
  // NOTE: need to decrement here because the pointer is after the null in the
  // last copy.
  incNew--;

  if (index < (int)word->size) {
    strcpy(incNew, incOld);
  }
  word->size = word->size + strLength - length;
  free(word->string);
  word->string = newString;

  return word->string;
}

/*
  Added a single character to a word at `index`
  @param c character to add
  @param index location in side the word. must be <= to word size + 1
  @param word to add the character.
  NOTE: The address of the pointer will change in most cases
*/
char *addChar(char c, int index, Word *word) {
  if (index > (int)word->size + 1) {
    perror("Index out of range to add to word\n");
    return word->string;
  }

  size_t nmemb = ((word->size + 1) / CHAR_BUFFER + 1) * CHAR_BUFFER;
  // NOTE: Early return if adding to the end of the string.
  if (index == (int)word->size - 1) {
    if ((word->size + 1) % CHAR_BUFFER == 0) {
      word->string = reallocarray(word->string, nmemb, sizeof(char));
    }

    if (word->string == NULL) {
      perror("Not enough memory to realloc string");
      return word->string;
    }

    word->string[index] = c;
    word->string[index + 1] = '\0';
    word->size++;
    return word->string;
  }

  char *newString = malloc(nmemb * sizeof(char));
  char *incNew = newString;
  char *incOld = word->string;

  int i = index;
  while (i-- && (*incNew++ = *incOld++))
    ;

  newString[index] = c;

  incNew++;
  while ((*incNew++ = *incOld++))
    ;

  word->size += 1;
  free(word->string);
  word->string = newString;
  return word->string;
}

/*
Deletes a character from the char * in a word.
@param The index to be deleted.
@param The struct holding the word to be deleted.
NOTE: I believe this should resize at most every 5 deletes
if the char is deleted from the end, it should hit the resize inevitably
and deleting mid word will resize regardless.
*/
char *delChar(int index, Word *word) {
  size_t nmemb = ((word->size - 1) / CHAR_BUFFER + 1) * CHAR_BUFFER;

  // NOTE: Early return if final letter is deleted.
  if (index == (int)word->size - 2) {
    if ((word->size) % CHAR_BUFFER == 0) {
      word->string = reallocarray(word->string, nmemb, sizeof(char));
    }

    word->string[index] = '\0';
    word->size--;
    return word->string;
  }

  char *newString = malloc(sizeof(char) * nmemb);
  char *incNew = newString;
  char *incOld = word->string;

  int i = index;
  while (i-- && (*incNew++ = *incOld++))
    ;

  incOld++;
  while ((*incNew++ = *incOld++))
    ;

  word->size--;
  free(word->string);
  word->string = newString;
  return word->string;
}

void freeWord(Word *word) {
  free(word->string);
  free(word);
}

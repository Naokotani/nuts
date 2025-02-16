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
bool checkIndices(int start, int end, size_t size);
bool checkIndex(int index, size_t size);

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

/*
Add a string to an existing word. The new string can optionally erase a
substring of the old string be making the `end` greater than `start`. For a
simple insert with no replace, end should be equal to start.

Example: The string "Hear" can be replaced with "Hello" with:
`addString("llo", 2, 4, exampleWord)`
Important to note that 4 is the index just part the "r" in her. the final
possible index that can be accessed (IE. word size - 1).
 */
char *addString(char *string, int start, int end, Word *word) {
  if (!checkIndices(start, end, word->size))
    return word->string;

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
  Add a single character, `c` to a `word` (IE. Word.string is added to) at
  `index`.

  Example: To change "hs" to "His":
  addChar('i', 1, exampleWord);

  NOTE: The address of the pointer will change in most cases
*/
char *addChar(char c, int index, Word *word) {
  if (!checkIndex(index, word->size))
    return word->string;

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
Deletes a character from the char * (IE. Word.string) in a `Word` at `index`

Example: to change "Her" to "He"
delChar(2, exampleWord);

NOTE: I believe this should resize at most every 5 deletes
if the char is deleted from the end, it should hit the resize inevitably
and deleting mid word will resize regardless.
*/
char *delChar(int index, Word *word) {
  if (!checkIndex(index, word->size))
    return word->string;

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

/*
Deletes a region of the string in a `Word` (IE. Word.string) from index `start`
to index `end`. It will return the original string if there is an issue with how
'start' or 'end' is passed.

Example: to turn "Peanuts" into "nuts"
delRegion(0, 2, exampleWord);

*/
char *delRegion(int start, int end, Word *word) {
  if (!checkIndices(start, end, word->size))
    return word->string;

  int length = end - start;
  size_t nmemb = ((word->size - length) / CHAR_BUFFER + 1) * CHAR_BUFFER;
  char *incOld = word->string;
  char *newString = malloc(nmemb * sizeof(char));
  char *incNew = newString;

  while (start-- && (*incNew++ = *incOld++))
    ;

  incOld += length;

  strcpy(incNew, incOld);
  free(word->string);
  word->string = newString;
  word->size -= length;

  return word->string;
}

bool checkIndex(int index, size_t size) {
  bool valid = 0;

  if (index < 0)
    perror("Index cannot be less than zero");
  else if (index >= (int)size)
    perror("Index is exceeds size of string");
  else
    valid = 1;

  return valid;
}

bool checkIndices(int start, int end, size_t size) {
  bool valid = 0;

  if (start > end)
    perror("Start index cannot be greater than end index");
  else if (start < 0)
    perror("Start index cannot be less than zero");
  else if (end >= (int)size)
    perror("End index exceeds size of string");
  else if (start > end)
    perror("Start index cannot be greater than end index");
  else
    valid = 1;

  return valid;
}

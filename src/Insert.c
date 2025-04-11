#include "Buffer.h"
#include "Character.h"
#include "Line.h"
#include "Types.h"
#include "Word.h"
#include <stdio.h>

// typedef struct Point {
//   Buffer *buffer; // Buffer the point is currently located in.
//   Line *line;     // Line where the point is located.
//   Word *word;     // `Word` where the point is located.
//   int strIndex;   // Index of the points location is located (IE string[i]).
//   int col; // The column the point is located in. Determined as a sum of the
//            // `Word` sizes before the current word + `strIndex` + 1. The plus
//            // one accounts for 0 index, while `Word->size` is an absolute
//            size).
// } Point;

Point *insertChar(Point *point, char newCh) {

  if (point->word == NULL) {
    perror("Word not initizlied for point.\n");
    return point;
  }

  char oldCh;

  if (point->word->size == 0) {
    oldCh = '\0';
    addChar(newCh, point->strIndex, point->word);
    point->strIndex += 1;
  } else {
    oldCh = point->word->string[point->strIndex - 1];

    CharType oldCharType = getCharType(oldCh);
    CharType newCharType = getCharType(newCh);

    if (newCharType == LETTER && oldCharType == WHITESPACE ||
        newCharType == WHITESPACE && oldCharType == LETTER ||
        newCharType == SPECIAL) {
      Word *newWord = initWord();
      addChar(newCh, 0, newWord);
      appendWord(newWord, point->line);
      point->word = newWord;
      point->strIndex = 1;
    } else if (newCharType == NEWLINE) {
      Line *newLine = initLine(point->line->lineNum + 1);
      appendLine(newLine, point->buffer);
      point->line = newLine;
      Word *newWord = initWord();
      addChar(newCh, 0, newWord);
      appendWord(newWord, point->line);
      point->word = newWord;
      point->strIndex = 1;
    } else {
      addChar(newCh, point->strIndex, point->word);
      point->strIndex += 1;
    }
  }

  printBuffer(point->buffer);

  return point;
}

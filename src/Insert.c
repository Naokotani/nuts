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

  char oldCh = point->word->string[point->strIndex];
  CharType oldCharType = getCharType(oldCh);
  CharType newCharType = getCharType(newCh);

  if (newCharType == LETTER && oldCharType == LETTER ||
      newCharType == WHITESPACE && oldCharType == WHITESPACE) {
    addChar(newCh, point->strIndex + 1, point->word);
    point->strIndex += 1;
  } else if (newCharType == LETTER && oldCharType == WHITESPACE ||
             newCharType == WHITESPACE && oldCharType == LETTER ||
             newCharType == SPECIAL) {
    Word *newWord = initWord();
    addChar(newCh, 1, newWord);
    appendWord(newWord, point->line);
    point->word = newWord;
    point->strIndex = 1;
  } else if (newCharType == NEWLINE) {
    if (newCh == 10) {
      if (point->word->prev == NULL &&
          getLastWord(point->line)->string[0] == 13) {
        addChar(newCh, 2, getLastWord(point->line));
        // Early return to handle windows new lines.
        return point;
        addChar(newCh, 2, point->word);
      } else {
        Word *word = initWord();
        Word *newLineWord = initWord();
        addChar(newCh, 1, word);
        appendWord(word, point->line);
        point->line = initLine(point->line->lineNum + 1);
      }
    }
  }

  return point;
}

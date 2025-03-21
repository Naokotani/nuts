#include "Character.h"
#include "Types.h"

bool isLetter(char ch) {
  if (ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122) {
    return true;
  } else {
    return false;
  }
}

bool isWhiteSpace(char ch) {
  bool whitespace;
  switch (ch) {
  case 32:
  case 9:
  case 11:
  case 12:
    whitespace = true;
    break;
  default:
    whitespace = false;
  }
  return whitespace;
}

bool isNewLine(char ch) {
  bool newline;

  switch (ch) {
  case 10:
  case 13:
    newline = true;
    break;
  default:
    newline = false;
  }
  return newline;
}

bool isSpecialChar(char ch) {
  bool special;
  if (!isNewLine(ch) && !isLetter(ch) && !isWhiteSpace(ch)) {
    special = true;
  } else {
    special = false;
  }
  return special;
}

CharType getCharType(char ch) {
  CharType charType;

  if (isLetter(ch)) {
    charType = LETTER;
  } else if (isWhiteSpace(ch)) {
    charType = WHITESPACE;
  } else if (isSpecialChar(ch)) {
    charType = SPECIAL;
  } else if (isNewLine(ch)) {
    charType = NEWLINE;
  }

  return charType;
}

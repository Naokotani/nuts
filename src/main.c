#include "Buffer.h"
#include "Insert.h"
#include "Line.h"
#include "Point.h"
#include "Types.h"
#include "Word.h"
#include <stdio.h>

int main() {
  Buffer *buffer = initBuffer("scratch");
  Line *line = initLine(1);
  Word *word = initWord();
  appendLine(line, buffer);
  appendWord(word, line);

  system("stty raw -echo");
  Point *point = initPoint(buffer, line, word);
  system("clear");
  int index = 1;

  while (1) {
    int input = getchar();
    system("clear");
    fflush(stdout);
    char ch = (char)input;
    if (ch == 27) {
      printf("have nice day.\n");
      system("stty cooked echo");
      return 0;
    }

    insertChar(point, ch);
  }

  system("stty cooked echo");
  return 0;
}

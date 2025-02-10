#include "Point.h"
#include "Types.h"

/*
Functions for initalizing and moving the `Point`:

typedef struct Point {
  Buffer *buffer; // Buffer the point is currently located in.
  Line *line;     // Line where the point is located.
  int col;        // Character where the point is located
} Point;

The point is the user's location in the text editor in general and a buffer in
specific. It must be associated with a buffer even if it is totally empty.
*/

Point *initPoint(Buffer *buffer, Line *line) {
  Point *point = malloc(sizeof(Point));
  point->line = line;
  point->col = 0;
  point->buffer = buffer;
  return point;
}

void freePoint(Point *point) { free(point); }

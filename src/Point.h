#include "Types.h"
#ifndef POINT
#define POINT

/*typedef struct Point {*/
/*  Buffer *buffer; // Buffer the point is currently located in.*/
/*  Line *line;     // Line where the point is located.*/
/*  Word *word;     // `Word` where the point is located.*/
/*  int strIndex;   // Index of the points location is located (IE string[i]).*/
/*  int col; // The column the point is located in. Determined as a sum of the*/
/*           // `Word` sizes before the current word + `strIndex` + 1. The
 * plus*/
/*           // one accounts for 0 index, while `Word->size` is an absolute
 * size).*/
/*} Point;*/

Point *initPoint(Buffer *buffer, Line *line, Word *word);
void freePoint(Point *point);
Point *charForward(Point *point);
Point *charBackward(Point *point);
Point *wordForward(Point *point);
Point *WordBackward(Point *point);

#endif

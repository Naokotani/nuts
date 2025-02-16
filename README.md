# Naokotani's Unusable Text Software (NUTS)

This is an attempt to create a rudimentary text editor in C, largely as a
learning exercise. The plan is for it to be a TUI style editor, similar in
nature to VI.

## Current State

I have created generalized types in `Types.h` and files for operating on the
types in corresponding .c and .h files. In Word.c I have created two functions.
One for adding and deleting characters. Currently the implementation should
dynamically resize the char * buffer, if the new will be a multiple of
CHAR_BUFFER, which is defined in `Types.h` as 5 currently. It would need to be
set to 2 at a bare minimum (A character plus a null character), in which case
memory should reallocate at minimum every add or delete.

I debated whether or not to add the complexity of the oversized buffer for
strings. The advantage is it should avoid the overhead of reallocating on most
deletions or additions. This is assuming that most additions and deletions are
at the end of a word. Currently, I am forced to copy and move the pointer for
additions and deleted in the middle of the word. This would mean that for very
large "Words" (Word is just the current name of type, it can be white space,
special characters etc.), the entire string would need to be copied if
deletions or additions were not at the end of the word.

## Todo

I am pretty happy with the functions for manipulating words. Next I should try
to build the functions to construct lines. I should also add to the
documentation for the `Word` functions. I also need to create tests to ensure
that all example code in `Word.c` is correct and will work as expected.

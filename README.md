# NUTS — C Text Buffer Prototype

NUTS is a low-level text manipulation project written in C. It’s an experiment in building the kinds of text data structures you’d need for an editor, without jumping straight to a UI or pretending this is going to be the next Vim.

The focus here is on **how text is represented and mutated at a low level**: inserting, deleting, and replacing small regions of text repeatedly, while managing memory manually and keeping behavior predictable.

## Motivation

NUTS exists to poke at the following questions:

- Who owns memory, and when?
- How do you avoid reallocating on every tiny edit?
- What indexing rules actually make sense once text starts changing?
- What breaks when you do this thousands of times in a row?

The goal is not to compete with Vim or Emacs, but to **understand the engineering trade-offs they’re built on**, from the bottom up.

## What’s implemented so far

- A `Word` abstraction with functions to:
  - insert characters or strings
  - replace regions
  - delete characters or ranges
- Dynamic string storage using **chunked allocation** (`CHAR_BUFFER`) to reduce realloc churn during repeated edits
- Explicit ownership rules: mutation functions allocate new buffers and free old ones
- Unit tests that exercise edge cases and boundary conditions
- A Valgrind runner to catch leaks and invalid memory access as the code evolves

Conceptually, the code is moving toward a structure like:

Buffer → Line → Word → character data

Right now, the work is focused on making the lowest layer correct and understandable before building upward.

## Repository layout

- `src/` — core implementation (data structures and mutation logic)
- `test/` — unit tests and test helpers
- `makefile` — build and test automation
- `all_tests.out` — compiled test runner
- `memtest.sh` — Valgrind memory-check helper
- `test/valgrind/` — Valgrind output logs

## Build

Build the project using the provided Makefile: `make`


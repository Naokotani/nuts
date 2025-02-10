#!/bin/bash

mkdir -p test/valgrind

valgrind --leak-check=full \
  --show-leak-kinds=all \
  --track-origins=yes \
  --verbose \
  --log-file=test/valgrind/valgrind-out.txt \
  ./all_tests.out

cat test/valgrind/valgrind-out.txt | sed --unbuffered \
  -e 's/\(.*errors in.*\)/\o033[31m\1\o033[39m/'

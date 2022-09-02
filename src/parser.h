#ifndef SRC_PARSER_H
#define SRC_PARSER_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_matrix.h"

typedef struct Data {
  unsigned int count;
  matrix_t matrix;
} Data;

int parser(char *filePath, Data *vertexes, Data *facets);

#endif  // SRC_PARSER_H

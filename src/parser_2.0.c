#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "s21_matrix.h"

int pre_parser(char *filePath, Vertexes *vertexes, Facets *facets) {
  int error = 0;
  //************************
  FILE *f = fopen(filePath, "r");
  char *temp_string = NULL;
  size_t len = 0;
  ssize_t lineSize = 0;

  //************************

  // первый проход с подсчетом строк v f
  while ((int)(lineSize = getline(&temp_string, &len, f)) != EOF) {
    if (temp_string[0] == 'v' && temp_string[1] == ' ') vertexes->count++;
    if (temp_string[0] == 'f' && temp_string[1] == ' ') facets->count++;

    // printf("%s", temp_string);
  }

  free(temp_string);

  if (f) fclose(f);

  return error;
}
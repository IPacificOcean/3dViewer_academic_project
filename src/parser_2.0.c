#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

int parser(char *filePath, Vertexes *vertexes, Facets *facets) {
  int error = 0;
  //************************
  FILE *f = fopen(filePath, "r");
  // char *temp_string = NULL;
  // size_t len = 0;
  // ssize_t lineSize = 0;
  // int space_count = 0;

  //************************

  // первый проход с подсчетом строк v f
  error = pre_parser(f, vertexes, facets);

  if (f) fclose(f);

  return error;
}

int pre_parser(FILE *f, Vertexes *vertexes, Facets *facets) {
  int error = 0;
  //************************
  char *temp_string = NULL;
  size_t len = 0;
  ssize_t lineSize = 0;
  int space_count = 0;
  //************************

  // первый проход с подсчетом строк v f
  while ((int)(lineSize = getline(&temp_string, &len, f)) != EOF) {
    if (temp_string[0] == 'v' && temp_string[1] == ' ') {
      vertexes->count++;
    }

    if (temp_string[0] == 'f' && temp_string[1] == ' ') {
      count_space_in_str(&space_count, temp_string);
    }
  }

  vertexes->count *= 3;
  facets->count += space_count * 2;

  free(temp_string);

  return error;
}

/*

# Apple ModelIO OBJ File: cube
mtllib cube.mtl
g
v 0 0 0
v 2 2 0
v 2 0 0
v 0 2 0
v 0 2 2
v 0 0 2
v 2 2 2
v 2 0 2
usemtl material_1
f 1 2 3
f 1 4 2
f 1 5 4
f 1 6 5
f 4 7 2
f 4 5 7
f 3 2 7
f 3 7 8
f 1 3 8
f 1 8 6
s off


*/

int count_space_in_str(int *count, char *str) {
  int error = 0;
  int temp_count = 0;
  char *tmp = str;
  while (*tmp) {
    // printf("%c", *tmp);
    if (*tmp == ' ') {
      temp_count++;
    }
    tmp++;
  }
  *count += temp_count;
  return error;
}
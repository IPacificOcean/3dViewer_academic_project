#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix.h"

typedef struct Vertexes {
  unsigned int count_of_vertexes;
  matrix_t matrix;
} Vertexes;

typedef struct Facets {
  unsigned int count_of_facets;
  matrix_t matrix;
} Facets;

int main(int argc, char *argv[]) {
  FILE *f = fopen("cube.obj", "r");
  char *temp_string = NULL;
  size_t len = 0;
  ssize_t lineSize = 0;

  Vertexes vertexes;
  vertexes.count_of_vertexes = 0;

  Facets facets;
  facets.count_of_facets = 0;

  while ((int)(lineSize = getline(&temp_string, &len, f)) != EOF) {
    if (temp_string[0] == 'v' && temp_string[1] == ' ')
      vertexes.count_of_vertexes++;
    if (temp_string[0] == 'f' && temp_string[1] == ' ')
      facets.count_of_facets++;

    // printf("%s", temp_string);
  }

  printf("count_of_vertexes = %d\n", vertexes.count_of_vertexes);
  printf("count_of_facets = %d\n", facets.count_of_facets);

  s21_create_matrix(vertexes.count_of_vertexes, 3, &vertexes.matrix);
  print_matrix(&vertexes.matrix);

  s21_remove_matrix(&vertexes.matrix);

  free(temp_string);

  if (f) fclose(f);
  return 0;
}
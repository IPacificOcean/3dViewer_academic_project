#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_matrix.h"

int main(int argc, char *argv[]) {
  //************************
  FILE *f = fopen("cube.obj", "r");
  char *temp_string = NULL;
  size_t len = 0;
  ssize_t lineSize = 0;

  matrix_t vertexes = {NULL, 0, 0};
  matrix_t facets = {NULL, 0, 0};
  int count_of_vertexes = 0;
  int count_of_facets = 0;

  //************************

  // первый проход с подсчетом строк v f
  while ((int)(lineSize = getline(&temp_string, &len, f)) != EOF) {
    if (temp_string[0] == 'v' && temp_string[1] == ' ') count_of_vertexes++;
    if (temp_string[0] == 'f' && temp_string[1] == ' ') count_of_facets++;

    // printf("%s", temp_string);
  }

  // второй проход заполняем данные
  //************************
  //************************
  rewind(f);
  s21_create_matrix(count_of_vertexes, 3, &vertexes);
  s21_create_matrix(count_of_facets, 3, &facets);

  char seps[] = " ";
  char *token = NULL;
  int rowsV = 0;
  int rowsF = 0;
  while ((int)(lineSize = getline(&temp_string, &len, f)) != EOF) {
    if (temp_string[0] == 'v' && temp_string[1] == ' ') {
      int columns = 0;
      printf("Tokens:\n");
      token = strtok(temp_string, seps);  // C4996
      while (token != NULL) {
        // While there are tokens in "string"
        printf(" %s\n", token);

        // Get next token:
        token = strtok(NULL, seps);  // C4996
        if (token == NULL) break;
        vertexes.matrix[rowsV][columns] = atof(token);
        columns++;
      }
      rowsV++;
    }

    if (temp_string[0] == 'f' && temp_string[1] == ' ') {
      int columns = 0;
      printf("Tokens:\n");
      token = strtok(temp_string, seps);  // C4996
      while (token != NULL) {
        // While there are tokens in "string"
        printf(" %s\n", token);

        // Get next token:
        token = strtok(NULL, seps);  // C4996
        if (token == NULL) break;
        facets.matrix[rowsF][columns] = atof(token);
        columns++;
      }
      rowsF++;
    }

    // printf("%s", temp_string);
  }
  //************************
  //************************

  printf("count_of_vertexes = %d\n", count_of_vertexes);
  printf("count_of_facets = %d\n", count_of_facets);

  printf("print vertex\n");
  print_matrix(&vertexes);
  printf("print facets\n");
  print_matrix(&facets);

  //************************
  s21_remove_matrix(&vertexes);
  s21_remove_matrix(&facets);

  free(temp_string);

  if (f) fclose(f);
  //************************
  return 0;
}
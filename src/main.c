#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_matrix.h"

typedef struct Data {
  unsigned int count;
  matrix_t matrix;
} Data;

int main(int argc, char *argv[]) {
  //************************
  FILE *f = fopen("cube.obj", "r");
  char *temp_string = NULL;
  size_t len = 0;
  ssize_t lineSize = 0;

  Data vertexes = {0};
  Data facets = {0};

  //   matrix_t vertexes = {NULL, 0, 0};
  //   matrix_t facets = {NULL, 0, 0};
  //   int vertexes.count = 0;
  //   int facets.count = 0;

  //************************

  // первый проход с подсчетом строк v f
  while ((int)(lineSize = getline(&temp_string, &len, f)) != EOF) {
    if (temp_string[0] == 'v' && temp_string[1] == ' ') vertexes.count++;
    if (temp_string[0] == 'f' && temp_string[1] == ' ') facets.count++;

    // printf("%s", temp_string);
  }

  // второй проход заполняем данные
  //************************
  //************************
  rewind(f);
  s21_create_matrix(vertexes.count, 3, &vertexes.matrix);
  s21_create_matrix(facets.count, 3, &facets.matrix);

  char seps[] = " ";
  char *token = NULL;
  int rowsV = 0;
  int rowsF = 0;
  while ((int)(lineSize = getline(&temp_string, &len, f)) != EOF) {
    if (temp_string[0] == 'v' && temp_string[1] == ' ') {
      int columns = 0;
      //   printf("Tokens:\n");
      token = strtok(temp_string, seps);  // C4996
      while (token != NULL) {
        // While there are tokens in "string"
        // printf(" %s\n", token);

        // Get next token:
        token = strtok(NULL, seps);  // C4996
        if (token == NULL) break;
        vertexes.matrix.matrix[rowsV][columns] = atof(token);
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
        // printf(" %s\n", token);

        // Get next token:
        token = strtok(NULL, seps);  // C4996
        if (token == NULL) break;
        facets.matrix.matrix[rowsF][columns] = atof(token);
        columns++;
      }
      rowsF++;
    }

    // printf("%s", temp_string);
  }
  //************************
  //************************

  printf("vertexes.count = %d\n", vertexes.count);
  printf("facets.count = %d\n", facets.count);

  printf("print vertex\n");
  print_matrix(&vertexes.matrix);
  printf("print facets\n");
  print_matrix(&facets.matrix);

  //************************
  s21_remove_matrix(&vertexes.matrix);
  s21_remove_matrix(&facets.matrix);

  free(temp_string);

  if (f) fclose(f);
  //************************
  return 0;
}
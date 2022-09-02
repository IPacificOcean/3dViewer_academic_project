#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_matrix.h"

// int parser(char *filePath, Data *vertexes, Data *facets);

// // int argc, char *argv[]
// int main() {
//   int error = 0;

//   Data vertexes = {0};
//   Data facets = {0};

//   parser("cube.obj", &vertexes, &facets);
//   //   parser("lamp.obj");

//   return error;
// }

int parser(char *filePath, Data *vertexes, Data *facets) {
  int error = 0;

  //************************
  FILE *f = fopen(filePath, "r");
  char *temp_string = NULL;
  size_t len = 0;
  ssize_t lineSize = 0;

  //   Data vertexes = {0};
  Data tmp_facets = {0};
  //   Data facets = {0};

  //************************

  // первый проход с подсчетом строк v f
  while ((int)(lineSize = getline(&temp_string, &len, f)) != EOF) {
    if (temp_string[0] == 'v' && temp_string[1] == ' ') vertexes->count++;
    if (temp_string[0] == 'f' && temp_string[1] == ' ') tmp_facets.count++;

    // printf("%s", temp_string);
  }

  facets->count = tmp_facets.count;

  // второй проход заполняем данные
  //************************
  //************************
  rewind(f);
  s21_create_matrix(vertexes->count, 3, &vertexes->matrix);
  s21_create_matrix(tmp_facets.count, 3, &tmp_facets.matrix);

  char seps[] = " ";
  char *token = NULL;
  int rowsV = 0;
  int rowsF = 0;
  while ((int)(lineSize = getline(&temp_string, &len, f)) != EOF) {
    if (temp_string[0] == 'v' && temp_string[1] == ' ') {
      int columns = 0;
      token = strtok(temp_string, seps);  // C4996
      while (token != NULL) {
        token = strtok(NULL, seps);  // C4996
        if (token == NULL) break;
        vertexes->matrix.matrix[rowsV][columns] = atof(token);
        columns++;
      }
      rowsV++;
    }

    if (temp_string[0] == 'f' && temp_string[1] == ' ') {
      int columns = 0;
      token = strtok(temp_string, seps);  // C4996
      while (token != NULL) {
        token = strtok(NULL, seps);  // C4996
        if (token == NULL) break;
        tmp_facets.matrix.matrix[rowsF][columns] = atof(token);
        columns++;
      }
      rowsF++;
    }
  }
  //************************
  //************************

  s21_create_matrix(facets->count, tmp_facets.matrix.columns * 2,
                    &facets->matrix);

  for (unsigned int i = 0; i < facets->count; i++) {
    for (int j = 0; j < facets->matrix.columns - 1; j++) {
      facets->matrix.matrix[i][j] = tmp_facets.matrix.matrix[i][((j + 1) / 2)];
    }
    facets->matrix.matrix[i][facets->matrix.columns - 1] =
        tmp_facets.matrix.matrix[i][0];
  }

  printf("vertexes->count = %d\n", vertexes->count);
  printf("tmp_facets.count = %d\n", tmp_facets.count);

  printf("print vertex\n");
  print_matrix(&vertexes->matrix);
  printf("print tmp_facets\n");
  print_matrix(&tmp_facets.matrix);
  printf("print tmp_facets\n");
  print_matrix(&facets->matrix);

  //************************
  s21_remove_matrix(&vertexes->matrix);
  s21_remove_matrix(&facets->matrix);
  s21_remove_matrix(&tmp_facets.matrix);

  free(temp_string);

  if (f) fclose(f);
  //************************

  return error;
}
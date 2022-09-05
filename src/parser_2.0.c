#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

int parser(char *filePath, Vertexes *vertexes, Facets *facets) {
  int error = 0;
  //************************
  FILE *f = fopen(filePath, "r");
  char *temp_string = NULL;
  size_t len = 0;
  ssize_t lineSize = 0;
  // int space_count = 0;

  //************************

  // первый проход с подсчетом строк v f

  error = pre_parser(f, vertexes, facets);

  // первый проход с подсчетом строк v f

  rewind(f);

  // ******* заполнение данных ********

  vertexes->arg_v = (double *)malloc(vertexes->count * sizeof(double));
  facets->arg_f = (unsigned int *)malloc(facets->count * sizeof(unsigned int));

  vertexes->arg_v[0] = 0;
  facets->arg_f[0] = 0;

  char seps[] = " ";
  char *token = NULL;
  int arg_v_index = 1;
  unsigned int arg_f_index = 1;
  char temp[32];
  int count = 0;

  while ((int)(lineSize = getline(&temp_string, &len, f)) != EOF) {
    if (temp_string[0] == 'v' && temp_string[1] == ' ') {
      token = strtok(temp_string, seps);

      while (token != NULL) {
        token = strtok(NULL, seps);
        if (token == NULL) break;
        vertexes->arg_v[arg_v_index] = atof(token);
        arg_v_index++;
      }
    }

    if (temp_string[0] == 'f' && temp_string[1] == ' ') {
      count = 0;
      token = strtok(temp_string, seps);
      count++;

      while (token != NULL) {
        token = strtok(NULL, seps);
        count++;
        if (count == 2) {
          memset(temp, 0, 32);
          strcpy(temp, token);
        }
        if (token == NULL) break;
        if (arg_f_index == 1) {
          facets->arg_f[arg_f_index] = atoi(token);
          arg_f_index++;
        } else {
          facets->arg_f[arg_f_index] = atoi(token);
          arg_f_index++;
          facets->arg_f[arg_f_index] = atoi(token);
          arg_f_index++;
          if (arg_f_index == facets->count - 1) {
            facets->arg_f[arg_f_index] = atoi(temp);
          }
        }
        // printf("arg_f_index %d\n", arg_f_index);
      }
    }
  }

  // ******* заполнение данных ********

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

  vertexes->count = vertexes->count * 3 + 1;
  facets->count = space_count * 2 + 1;

  free(temp_string);

  return error;
}

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
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"

int parser(char *filePath, Vertexes *vertexes, Facets *facets) {
  int error = 0;
  //************************
  FILE *f = fopen(filePath, "r");
  if (!f) {
      error = 1;
  } else {
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
      int arg_v_index = 3;
      unsigned int arg_f_index = 0;
      char temp[32];
      int countTokes = 0;
      int numberOfTokens = 0;

      // vertex
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

        // facets
        if (temp_string[0] == 'f' && temp_string[1] == ' ') {
          numberOfTokens = 1;
          countTokes = 0;
          count_number_in_string(&numberOfTokens, temp_string);
          token = strtok(temp_string, seps);
          countTokes++;

          while (token != NULL) {
            token = strtok(NULL, seps);
            countTokes++;
            if (countTokes == 2) {
              memset(temp, 0, 32);
              strcpy(temp, token);
            }
            if (token == NULL) break;
            if (countTokes == 2) {
              facets->arg_f[arg_f_index] = atoi(token);
              arg_f_index++;
            } else {
              facets->arg_f[arg_f_index] = atoi(token);
              arg_f_index++;
              facets->arg_f[arg_f_index] = atoi(token);
              arg_f_index++;
            }
            if (numberOfTokens == countTokes) {
              facets->arg_f[arg_f_index] = atoi(temp);
              arg_f_index++;
            }
            // printf("arg_f_index %d\n", arg_f_index);
          }
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
      count_number_in_string(&space_count, temp_string);
    }
  }

  vertexes->count = vertexes->count * 3 + 3;
  facets->count = space_count * 2;

  free(temp_string);

  return error;
}

int count_number_in_string(int *count, char *str) {
  int error = 0;
  int temp_count = 0;
  char *tmp = str;
  while (*tmp) {
    // printf("%c", *tmp);
    if (*tmp == ' ' && isdigit(*(tmp + 1))) {
      temp_count++;
    }
    tmp++;
  }
  *count += temp_count;
  return error;
}

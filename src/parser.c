#include "parser.h"

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parser(char *filePath, Vertexes *vertexes, Facets *facets) {
  int error = 0;
  //************************
  FILE *f = fopen(filePath, "r");

  if (!f) error = 1;

  if (!error) error = pre_parser(f, vertexes, facets);

  if (!error) error = getDataVetrtexAndFacet(f, vertexes, facets);

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

int getDataVetrtexAndFacet(FILE *f, Vertexes *vertexes, Facets *facets) {
  int error = 0;

  rewind(f);

  vertexes->arg = (double *)malloc(vertexes->count * sizeof(double));
  facets->arg = (unsigned int *)malloc(facets->count * sizeof(unsigned int));

  if (!vertexes->arg || !facets->arg) error = 2;

  // printf("vertexes->arg_v %p\n", vertexes->arg);
  // printf("vertexes->arg_v %p\n", facets->arg);

  if (!error) {
    vertexes->arg[0] = 0;
    vertexes->arg[1] = 0;
    vertexes->arg[2] = 0;
    facets->arg[0] = 0;

    char *temp_string = NULL;
    size_t len = 0;
    ssize_t lineSize = 0;
    char seps[] = " ";
    char *token = NULL;
    unsigned int arg_v_index = 3;
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
          if (token == NULL || *token == '\n') break;
          vertexes->arg[arg_v_index] = atof(token);
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
          if (token == NULL || *token == '\n') break;
          if (countTokes == 2) {
            facets->arg[arg_f_index] = atoi(token);
            arg_f_index++;
          } else {
            facets->arg[arg_f_index] = atoi(token);
            arg_f_index++;
            facets->arg[arg_f_index] = atoi(token);
            arg_f_index++;
          }
          if (numberOfTokens == countTokes) {
            facets->arg[arg_f_index] = atoi(temp);
            arg_f_index++;
          }
        }
      }
    }
  }

  return error;
}

/*
Перемещение
Матрица перемещения в однородных двумерных координатах :
 1 0 a
 0 1 b
 0 0 1
где a и b - величины по x и y,
на которые необходимо переместить исходную точку.Таким образом,
чтобы переместить точку необходимо умножить матрицу перемещения на нее:
x1      1 0 a   x
y1 =    0 1 b   * y
1       0 0 1   1
где x и y - исходные координаты точки, а x1 и y1 -
полученные координаты новой точки после перемещения.

Поворот
Матрица поворота по часовой стрелке в однородных двумерных координатах :
 cos(a) sin(a) 0
-sin(a) cos(a) 0
0       0      1
где a - угол поворота в двумерном пространстве.Для получения
координат новой точки необходимо также, как и матрицу перемещения,
перемножить матрицу поворота на исходную точку:
x1      cos(a)  sin(a) 0    x
y1 =    -sin(a) cos(a) 0 *  y
1       0       0      1    1

Масштабирование
Матрица масштабирования в однородных двумерных координатах:
a 0 0
0 b 0
0 0 1
где a и b - коэффициенты масштабирования соответственно по осям OX
и OY.Получение координат новой точки происходит аналогично описанным выше
случаям.
*/

int moveObj(Vertexes *vertex, Move move) {
  int error = 0;

  // double Mtmp[4][1] = {{0}, {0}, {0}, {1}};
  // double Mrez[4][1] = {{0}, {0}, {0}, {1}};
  // double Mmove[4][4] = {{1, 0, 0, move->dx},
  //                       {0, 1, 0, move->dy},
  //                       {0, 0, 1, move->dz},
  //                       {0, 0, 0, 1}};

  // for (unsigned int i = 3; i < vertex->count; i += 3) {
  //   Mtmp[0][0] = vertex->arg[i];
  //   Mtmp[1][0] = vertex->arg[i + 1];
  //   Mtmp[2][0] = vertex->arg[i + 2];
  //   for (int i = 0; i < 4; i++) {
  //     for (int j = 0; j < 1; j++) {
  //       double res = 0;
  //       for (int k = 0; k < 4; k++) {
  //         res += Mmove[i][k] * Mtmp[k][j];
  //       }
  //       Mrez[i][j] = res;
  //     }
  //   }
  //   vertex->arg[i] = Mrez[0][0];
  //   vertex->arg[i + 1] = Mrez[1][0];
  //   vertex->arg[i + 2] = Mrez[2][0];
  // }

  for (unsigned int i = 3; i < vertex->count; i += 3) {
    vertex->arg[i] += move.dx;
    vertex->arg[i + 1] += move.dy;
    vertex->arg[i + 2] += move.dz;
  }

  return error;
}

int turnObj() {
  int error = 0;

  return error;
}

int scaleObj(Vertexes *vertex, double scale) {
  int error = 0;

  for (unsigned int i = 3; i < vertex->count; i += 3) {
    vertex->arg[i] *= scale;
    vertex->arg[i + 1] *= scale;
    vertex->arg[i + 2] *= scale;
  }

  return error;
}
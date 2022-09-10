#include "affine_transformations.h"

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "parser.h"
#include "s21_matrix.h"

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

int moveObj(Vertexes *vertex) {
  int error = 0;

  // массив даблов / столбуы / колонки

  //   matrix_t Mtmp = {NULL, 0, 0};
  //   matrix_t Mmove = {NULL, 0, 0};
  //   error = s21_create_matrix(4, 1, &Mtmp);
  //   error = s21_create_matrix(4, 1, &Mmove);

  double x, y, z;
  double dx, dy, dz;

  //   Mtmp.matrix[0] = 1;
  //   Mtmp[0] = x;
  double Mtmp[4][1] = {{x}, {y}, {z}, {1}};
  double Mrez[4][1] = {{0}, {0}, {0}, {1}};
  double Mmove[4][4] = {
      {1, 0, 0, dx}, {0, 1, 0, dy}, {0, 0, 1, dz}, {0, 0, 0, 1}};

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 1; j++) {
      double res = 0;
      for (int k = 0; k < 4; k++) {
        res += Mmove[i][k] * Mmove[k][j];
      }
      Mrez[i][j] = res;
    }
  }

  //   s21_remove_matrix(&Mtmp);
  //   s21_remove_matrix(&Mmove);

  return error;
}

int turnObj() {
  int error = 0;

  return error;
}

int scaleObj() {
  int error = 0;

  return error;
}
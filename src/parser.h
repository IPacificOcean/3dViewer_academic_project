#ifndef SRC_PARSER_H
#define SRC_PARSER_H

#include "s21_matrix.h"

typedef struct Data {
  unsigned int count;
  matrix_t matrix;
} Data;

/**
 * @brief хранит кординаты вершин точек в одномерном массиве в формате x, y, z,
 * ... xn, yn, xn.
 *
 */
typedef struct Vretex {
  unsigned int count;
  double *vretexes;
} Vertexes;

/**
 * @brief хранит попарно номера вершин для построения линии фасетов в одноменом
 * массиве в формате v1, v2, v,2, v4, v4, v5, v5, vn.
 *
 */
typedef struct Facet {
  unsigned int count;
  unsigned int *vretexes;
} Facets;

/**
 * @brief функция для парсинга .obj файлов.
 *
 * @param filePath путь и имя файла
 * @param vertexes структура с массивом вершин
 * @param facets структура с массивом фасетов
 * @return int код ошибки
 */
// int parser(char *filePath, Data *vertexes, Data *facets);

/**
 * @brief функция для парсинга .obj файлов.
 *
 * @param filePath путь и имя файла
 * @param vertexes структура с массивом вершин
 * @param facets структура с массивом фасетов
 * @return int код ошибки
 */
int pre_parser(char *filePath, Vertexes *vertexes, Facets *facets);

#endif  // SRC_PARSER_H

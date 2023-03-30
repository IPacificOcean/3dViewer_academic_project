//
// Created by Tysane Norine on 3/29/23.
//

#ifndef INC_3DVIEWER_V2_0_SRC_MODEL_OLD_BACKEND_STRUCT_DATA_H_
#define INC_3DVIEWER_V2_0_SRC_MODEL_OLD_BACKEND_STRUCT_DATA_H_

typedef struct Vretex {
  unsigned int count;
  double *arg;
} Vertexes;

/**
 * @brief хранит попарно номера вершин для построения линии фасетов в одноменом
 * массиве в формате v1, v2, v,2, v4, v4, v5, v5, vn.
 *
 */
typedef struct Facet {
  unsigned int count;
  unsigned int *arg;
} Facets;



typedef struct Move {
  double dx;
  double dy;
  double dz;
} Move;

/**
 * @brief
 *
 */
typedef struct Scale {
  double dx;
  double dy;
  double dz;
} Scale;

/**
 * @brief
 *
 */
typedef struct Rotate {
  double dx;
  double dy;
  double dz;
} Rotate;

#endif  // INC_3DVIEWER_V2_0_SRC_MODEL_OLD_BACKEND_STRUCT_DATA_H_

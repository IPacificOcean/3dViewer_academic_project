#include "parser.h"
#include "s21_matrix.h"

int main() {
  int error = 0;

  // Data vertexes = {0};
  // Data facets = {0};

  Vertexes vertexes;
  Facets facets;

  error = pre_parser("cube.obj", &vertexes, &facets);
  //   parser("lamp.obj");

  printf("vertexes->count = %d\n", vertexes.count);
  printf("tmp_facets.count = %d\n", facets.count);

  return error;
}
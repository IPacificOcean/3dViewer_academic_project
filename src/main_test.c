#include "parser.h"
#include "s21_matrix.h"

int main() {
  int error = 0;

  // Data vertexes = {0};
  // Data facets = {0};

  Vertexes vertexes;
  Facets facets;
  // FILE *f = fopen("cube.obj", "r");

  // error = parser("cube.obj", &vertexes, &facets);
  error = parser("lamp.obj", &vertexes, &facets);
  //   parser("lamp.obj");

  printf("vertexes->count = %d\n", vertexes.count);
  printf("facets.count = %d\n", facets.count);

  print_vertex(vertexes);

  // if (f) fclose(f);

  return error;
}
#include "parser.h"
#include "s21_matrix.h"

int main() {
  int error = 0;

  // Data vertexes = {0};
  // Data facets = {0};

  Vertexes vertexes;
  Facets facets;
  // FILE *f = fopen("cube.obj", "r");

  error = parser("cube.obj", &vertexes, &facets);
  // error = parser("lamp.obj", &vertexes, &facets);
  //   parser("lamp.obj");

  printf("vertexes->count = %d\n", vertexes.count);
  printf("facets.count = %d\n", facets.count);

  printf("vertexes print\n");
  print_vertex(vertexes);
  printf("facets print\n");
  print_facets(facets);

  // if (f) fclose(f);

  return error;
}
#include "parser.h"
#include "s21_matrix.h"

int main() {
  int error = 0;

  Data vertexes = {0};
  Data facets = {0};

  parser("cube.obj", &vertexes, &facets);
  //   parser("lamp.obj");

  return error;
}
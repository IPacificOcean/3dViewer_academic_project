#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int main(int argc, char *argv[]) {
  FILE *f = fopen("cube.obj", "r");

  char *temp_string = NULL;

  size_t len = 0;
  ssize_t lineSize = 0;

  while ((int)(lineSize = getline(&temp_string, &len, f)) != EOF) {
    printf("%s", temp_string);
  }

  free(temp_string);

  if (f) fclose(f);
  return 0;
}
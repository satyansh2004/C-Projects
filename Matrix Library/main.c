#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void mat_display(_MAT *a) {
  for (int i = 0; i < a->rows; ++i) {
    for (int j = 0; j < a->cols; ++j) {
      printf("%d ", a->data[(i * a->cols) + j]);
    }
    printf("\n");
  }
}

_MAT *mat_addition(_MAT *dest, _MAT *a, _MAT *b) {
  int *addition_of_matrix = malloc((a->rows * a->cols) * sizeof(a[0]));

  if (a->rows == 0 || a->cols == 0) {
    printf("Not a Matrix\n");
    return NULL;
  }

  if (a->rows != a->cols) {
    printf("Rows and Columns should be equal\n");
    return NULL;
  }

  for (int i = 0; i < a->rows; ++i) {
    for (int j = 0; j < a->cols; ++j) {
      addition_of_matrix[(i * a->cols) + j] = a->data[(i * a->cols) + j] + b->data[(i * a->cols) + j];
    }
  }

  dest->data = addition_of_matrix;
  dest->cols = a->cols;
  dest->rows = a->rows;

  return dest;
}

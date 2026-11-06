#ifndef _MAT_ADD
#define _MAT_ADD

typedef struct {
  int *data;
  int rows;
  int cols;
} _MAT;

void mat_display(_MAT *a);
_MAT *mat_addition(_MAT *dest, _MAT *a, _MAT *b);

#endif
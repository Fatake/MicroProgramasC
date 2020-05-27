#include <stdio.h>

#define TRUE 1
#define FALSE 0

struct struct_matrix {
    int nrow;
    int ncol;
    float **data;
};

typedef struct struct_matrix Matrix; 

void create_matrix(Matrix *m, int nrow, int ncol);
void populate_matrix(Matrix *m);
void print_matrix(Matrix *m, char iden);
void shift_matrix_left(Matrix *m, int block_sz, int initial);
void shift_matrix_up(Matrix *m, int block_sz, int initial);
void matrix_product(Matrix *c, Matrix *a, Matrix *b);
float* create_array_as_matrix(int r, int c);
void populate_array_as_matrix(float *arr, int r, int c);
float array_as_matrix_equals(float *a, float *b, int r, int c);
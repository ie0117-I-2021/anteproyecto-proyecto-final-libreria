#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define USER "USER"

#define NO_ERROR 0;
#define ERROR 1;

typedef struct matrix_t
{	
    int rows;
    int cols;
    double *data;
} matrix_t;


/*
 *	Matrix operations
 */

/* 
 *	New matrix
 */
matrix_t *new_matrix(const int rows, const int cols);

/* 
 *	Identity matrix 
 */
matrix_t *identity(const int size);

/* 
 *	Matrix of ones 
 */
matrix_t *ones(const int rows, const int cols);

/* 
 *	Matrix sum 
 */
matrix_t *add(const matrix_t *matrixA, const matrix_t *matrixB);

/* 
 *	Matrix subtraction 
 */
matrix_t *sub(const matrix_t *matrixA, const matrix_t *matrixB);

/* 
 *	Matrix multiplication 
 */
matrix_t *mul(const matrix_t *matrixA, const matrix_t *matrixB);

/* 
 *	Multiplication of a matrix by a scalar 
 */
matrix_t *scalar_mul(const matrix_t *matrix, const double x);

/*
 *	Transpose of a matrix
 */

matrix_t *transpose(const matrix_t *matrix);

/*	
 *	Row and column configuration 
 */
void set(const matrix_t *matrix, const int i, const int j, const double x);
double get(const matrix_t *matrix, const int i, const int j);


/*
 *	Support functions
 */

void matrix_free(matrix_t *matrix);
void matrix_print(const matrix_t *matrix);
void set_row(const matrix_t *matrix, const int i, const double *elem);
void fill_matrix(const matrix_t *matrix);

/*
 *	Support functions for file handling
 */
int save_matrix(const matrix_t *matrix, const char * label, const char * file_name);
void remove_file(const char * file_name);

void clean_stdin();

/*
 *	Bibliography
 *
 *	https://stackoverflow.com/questions/41128608/c-matrix-struct
 *	https://codereview.stackexchange.com/questions/179405/matrix-implementation-using-struct-in-c
 */

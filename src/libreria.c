/*
 *	libreria.c
 *
 *	Created on: August 06, 2021
 *	Last modified on: August 06, 2021
 *  Adapted from: https://codereview.stackexchange.com/questions/179405/matrix-implementation-using-struct-in-c
 *		Author: Carlos Alberto Caravaca Mora. B61512
 *		Last modifier: Carlos Alberto Caravaca Mora
 *  
 *  Description: It is a library that contains matrix operations, which are: 
 *  calculation of the identity matrix, calculation of the matrix of ones, addition, 
 *  subtraction and multiplication of matrices,  also the multiplication of a scalar 
 *  by a matrix and finally the calculation of the transpose.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libreria.h"

#ifndef OUT_OF_MEMORY
#define OUT_OF_MEMORY "ERROR: Insufficient space in memory.\n"
#endif

/*
 *  Function for the dimensions of a new matrix
 */
matrix_t *new_matrix(const int rows, const int cols)
{
    matrix_t *matrix = malloc(sizeof(matrix_t));
    if (!matrix) {
        fprintf(stderr, OUT_OF_MEMORY);
    }
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->data = malloc(rows * cols * sizeof(double));
    if (!matrix->data) {
        fprintf(stderr, OUT_OF_MEMORY);
    }
    return matrix;
}

/*
 *  Function to calculate the identity matrix
 */
matrix_t *identity(const int size)
{
    matrix_t *matrix = new_matrix(size, size);
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            set(matrix, i, j, (i == j ? 1 : 0));
        }
    }
    return matrix;
}

/*
 *  Function to calculate a matrix of ones
 */
matrix_t *ones(const int rows, const int cols)
{
    matrix_t *matrix = new_matrix(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            set(matrix, i, j, 1);
        }
    }
    return matrix;
}

/*
 *  Evaluate the correct dimensions of the two matrix
 */
static void check_same_size(const matrix_t *matrixA, const matrix_t *matrixB)
{
    if (matrixA->rows == matrixB->rows && matrixA->cols == matrixB->cols)
    {
        return;
    }
    fprintf(stderr, "ERROR: Matrices are not compatible. They have different dimensions.\n");
    exit(EXIT_FAILURE);
}

/*
 *  Function to calculate the sum of matrices
 */
matrix_t *add(const matrix_t *matrixA, const matrix_t *matrixB)
{
    check_same_size(matrixA, matrixB);
    int rows = matrixA->rows;
    int cols = matrixA->cols;
    matrix_t *sum = new_matrix(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            double a = get(matrixA, i, j);
            double b = get(matrixB, i, j);
            set(sum, i, j, a + b);
        }
    }
    return sum;
}

/*
 *  Function to calculate matrix subtraction
 */
matrix_t *sub(const matrix_t *matrixA, const matrix_t *matrixB)
{
    check_same_size(matrixA, matrixB);
    int rows = matrixA->rows;
    int cols = matrixA->cols;
    matrix_t *diff = new_matrix(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            double a = get(matrixA, i, j);
            double b = get(matrixB, i, j);
            set(diff, i, j, a - b);
        }
    }
    return diff;
}

/*
 *  Function to calculate matrix multiplication
 */
matrix_t *mul(const matrix_t *matrixA, const matrix_t *matrixB)
{
    /*
     *  Check the size
     */
    if (matrixA->cols != matrixB->rows)
    {
        fprintf(stderr, "ERROR: Matrices are not compatible for multiplication.\n");
        exit(EXIT_FAILURE);
    }
    int m = matrixA->rows;
    int n = matrixA->cols;
    int p = matrixB->cols;
    matrix_t *product = new_matrix(m, p);
    
    /*
     *  Standard general multiplication
     */
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            double sum = 0;
            for (int k = 0; k < n; k++)
            {
                sum += get(matrixA, i, k) * get(matrixB, k, j);
            }
            set(product, i, j, sum);
        }
    }
    return product;
}

/*
 *  Function to calculate the multiplication of a matrix by a scalar
 */
matrix_t *scalar_mul(const matrix_t *matrix, const double x)
{
    int rows = matrix->rows;
    int cols = matrix->cols;
    matrix_t *result = new_matrix(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            set(result, i, j, get(matrix, i, j) * x);
        }
    }
    return result;
}

/*
 *	Transpose of a matrix
 */
matrix_t *transpose(const matrix_t *matrix)
{
    int rows = matrix->cols;
    int cols = matrix->rows;

    matrix_t *trans = new_matrix(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            set(trans, i, j, get(matrix, j, i));
        }
    }
    return trans;
}

/*
 *  Set individual items as well as rows and columns
 */
void set(const matrix_t *matrix, const int i, const int j, const double x)
{
    *(matrix->data + i * matrix->rows + j) = x;
}

/*
 *  Get individual items as well as rows and columns
 */
double get(const matrix_t *matrix, const int i, const int j)
{
    return *(matrix->data + i * matrix->rows + j);
}

/*
 *  Free memory
 */
void matrix_free(matrix_t *matrix)
{
    free(matrix->data);
    free(matrix);
}

/*
 *  Transports data from memory to screen
 */
void matrix_print(const matrix_t *matrix)
{
	printf("\n");
    for (int i = 0; i < matrix->rows; i++)
        {
            for (int j = 0; j < matrix->cols; j++)
            {
                printf("%5.2f ", get(matrix, i, j));
            }
            printf("\n");
        }
}

void set_row(const matrix_t *matrix, const int i, const double *elem)
{
    for (int j = 0; j < matrix->cols; j++)
    {
        set(matrix, i, j, elem[j]);
    }
}

void fill_matrix(const matrix_t *matrix) {

	double input_row;

	for (int j = 0; j < matrix->rows; ++j) 
		{
			for (int i = 0; i < matrix->cols; ++i)
			{
				printf( "\n\tInsert the value to (%i , %i): ", j, i);
				clean_stdin();
				scanf( "%lf", &input_row );
				set(matrix, j, i, input_row);
			}
		}
}

/* 
 *  Function to save a file
 */
int save_matrix(const matrix_t *matrix, const char * label, const char * file_name) {
    if (matrix == NULL || matrix->data == NULL) {
        return NO_ERROR;
    }

    /* Overwrite it all */
    FILE * matrix_fd = fopen(file_name, "a");
    if (matrix_fd == NULL) {
        return NO_ERROR;
    }

	fprintf(matrix_fd, "%s\n", label);
    for (int i = 0; i < matrix->rows; i++)
        {
            for (int j = 0; j < matrix->cols; j++)
            {
                fprintf(matrix_fd, "%5.2f ", get(matrix, i, j));
            }
            fprintf(matrix_fd, "\n");
        }

    fclose(matrix_fd);

    return ERROR;
}

/* 
 *  Function to remove a file when starting the program
 */
void remove_file(const char * file_name) {
   int del = remove(file_name);
   if (!del)
      printf("\n\nINFO: The file < %s > is deleted successfully!", file_name);
   else
      printf("\n\nERROR: The file < %s > is not deleted!", file_name);
}

void clean_stdin()
	{
	    while (getchar()!='\n');
	}
/*	
 *  Bibliography
 *
 *  https://www.youtube.com/watch?v=9Dpjhv0dN7I
 *  https://programacion1z.wordpress.com/2009/03/19/suma-de-dos-matrices-funciones/
 *  https://www.lawebdelprogramador.com/foros/Dev-C/1717568-sumar-restar-y-escalar-una-matriz.html
 *  https://programmerclick.com/article/5613640072/
 *  https://www.aprendoencasa.com/matrices-suma-resta-y-traspuesta/
 *  https://parzibyte.me/blog/2019/11/11/producto-matrices-c-multiplicacion/#:~:text=Para%20obtener%20el%20producto%20de,normalmente%2C%20en%20x%20e%20y%20.
 *  https://es.stackoverflow.com/questions/165509/multiplicacion-de-matrices-en-c
 *  determinante
 *  https://codereview.stackexchange.com/questions/179405/matrix-implementation-using-struct-in-c
 */

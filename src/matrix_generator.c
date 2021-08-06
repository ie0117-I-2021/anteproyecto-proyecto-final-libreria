/*
 *	matrix_generator.c
 *
 *	Created on: August 06, 2021
 *	Last modified on: August 06, 2021
 *		Author: Carlos Alberto Caravaca Mora. B61512
 *		Last modifier: Carlos Alberto Caravaca Mora
 *
 *	Description:
 *	This menu was made with the purpose of showing the functionality of the library.c
 *
 *	Compilation instruction:
 *		> make
 * 		Executable crated:
 *		> ./matrix_generator
 *		To redo the compilation, you can do first:
 *		> make clean
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libreria.h"
#define USER "USER"


/* 
 *	Control structure to be able to use the "case"
 */
 
enum control_e {
    Exit = 0,
    identit,
    one,
    ad,
    subb,
    mult,
    scalar_mult,
    trasp
};
 


int main(void) 
{
	int count = 1;
	int value = 1;
	int rows = 1;
	int cols = 1;
	
	double scal = 1;
	int size = 1;
		
	/*
	 *	Menu design, greeting the user
	 */

	printf("\nINFO: Welcome %s\n", getenv(USER));
		printf("\nINFO: This program allows you to choose between seven operations\nwith matrix, as you can see in the following menu: ");
	
	matrix_t *matrix = malloc(sizeof(matrix_t));

	remove_file("matrix.txt");

	do
	{
		/* 
		 *	Main menu
		 */
		
		printf( "\n\n\tINFO: Matrix operations menu:\n" );
		printf( "\n\t0. Exit" );
		printf( "\n\t1. Calculate the identity matrix" );
		printf( "\n\t2. Calculate the matrix of ones" );
		printf( "\n\t3. Calculate the sum of two matrix" );
		printf( "\n\t4. Calculate the subtraction of two matrix" );
		printf( "\n\t5. Calculate the multiplication of two matrix" );
		printf( "\n\t6. Calculate the multiplication of a matrix by a scalar" );
		printf( "\n\t7. Calculate the transpose of a matrix" );



		printf( "\n\n\tInsert an option (0-7): " );


		scanf( "\n\t%d", &value );
		printf("\n");

	 	switch (value)
	 	{	

	 		case identit: ;
		 		printf( "\n\tInsert the size of the matrix: ");
				scanf( "\t%d", &size );
				matrix = identity(size);
				printf("\n\tCalculating: wait...\n");
				sleep (count);	
				printf( "\n Solution, the Matrix is:" );	
				printf("\n");
				matrix_print(matrix);
				save_matrix(matrix, "\n Identity Matrix", "matrix.txt");
				break;

			case one: ;
				printf( "\n\tInsert number of rows: ");
				scanf( "%d", &rows );
				printf( "\n\tInsert number of columns: ");
				scanf( "%d", &cols );
				matrix = ones(rows, cols);
				printf("\n\tCalculating: wait...\n");
				sleep (count);
				printf( "\n Solution, the Matrix is:");
				matrix_print(matrix);
				save_matrix(matrix, "\n Ones Matrix", "matrix.txt");
				break;
			
			case ad: ;
				printf( "\n\tNumber of rows of the matrix A and the matrix B: ");
				scanf( "%i", &rows );
				printf( "\n\tNumber of columns of the matrix A and the matrix B: ");
				scanf( "%i", &cols );

				matrix_t *matrixA = new_matrix(rows, cols);
				printf( "\n\tFill matrix A: ");
				fill_matrix(matrixA);
			
				matrix_t *matrixB = new_matrix(rows, cols);
				printf( "\n\tFill matrix B: ");
				fill_matrix(matrixB);

				matrix_t *matrixC = new_matrix(rows, cols);
				matrixC = add(matrixA, matrixB);
				
				printf("\n\tCalculating: wait...\n");
				sleep (count);	

				printf( "\n Matrix A: ");
				matrix_print(matrixA);
				save_matrix(matrixA, "\n Matrix A", "matrix.txt");
				matrix_free(matrixA);
				
				printf( "\n Matrix B: ");
				matrix_print(matrixB);
				save_matrix(matrixB, "\n Matrix B", "matrix.txt");
				matrix_free(matrixB);			
				
				printf( "\n Solution, Matrix C: ");
				matrix_print(matrixC);
				save_matrix(matrixC, "\n Solution, Matrix C:", "matrix.txt");
				matrix_free(matrixC);
				break;

			case subb: 
				printf( "\n\tNumber of rows of the matrix A and the matrix B: ");
				scanf( "%i", &rows );
				printf( "\n\tNumber of columns of the matrix A and the matrix B: ");
				scanf( "%i", &cols );

				matrix_t *matrix1 = new_matrix(rows, cols);
				printf( "\n\tFill matrix A: ");
				fill_matrix(matrix1);
			
				matrix_t *matrix2 = new_matrix(rows, cols);
				printf( "\n\tFill matrix B: ");
				fill_matrix(matrix2);

				matrix_t *matrix3 = new_matrix(rows, cols);
				matrix3 = sub(matrix1, matrix2);
				
				printf("\n\tCalculating: wait...\n");
				sleep (count);

				printf( "\n Matrix A: ");
				matrix_print(matrix1);
				save_matrix(matrix1, "\n Matrix A", "matrix.txt");
				matrix_free(matrix1);
				
				printf( "\n Matrix B: ");
				matrix_print(matrix2);
				save_matrix(matrix2, "\n Matrix B", "matrix.txt");
				matrix_free(matrix2);

				printf( "\n Solution, Matrix C: ");
				matrix_print(matrix3);
				save_matrix(matrix3, "\n Solution, Matrix C:", "matrix.txt");
				matrix_free(matrix3);
				break;
				
			case mult: 
				printf( "\n\tNumber of rows of the matrix A and the matrix B: ");
				scanf( "%i", &rows );
				printf( "\n\tNumber of columns of the matrix A and the matrix B: ");
				scanf( "%i", &cols );

				matrix_t *matrix_am = new_matrix(rows, cols);
				printf( "\n\tFill matrix A: ");
				fill_matrix(matrix_am);
				
				matrix_t *matrix_bm = new_matrix(rows, cols);
				printf( "\n\tFill matrix B: ");
				fill_matrix(matrix_bm);

				matrix_t *matrix_rs = new_matrix(rows, cols);
				matrix_rs = mul(matrix_am, matrix_bm);

				printf("\n\tCalculating: wait...\n");
				sleep (count);
				
				printf( "\n Matrix A: ");
				matrix_print(matrix_am);
				save_matrix(matrix_am, "\n Matrix A", "matrix.txt");
				matrix_free(matrix_am);
				
				printf( "\n Matrix B: ");
				matrix_print(matrix_bm);
				save_matrix(matrix_bm, "\n Matrix B", "matrix.txt");
				matrix_free(matrix_bm);

				printf( "\n Solution, Matrix C: ");
				matrix_print(matrix_rs);
				save_matrix(matrix_rs, "\n Solution, Matrix C:", "matrix.txt");
				matrix_free(matrix_rs);
				break;
			
			case scalar_mult: 
				printf( "\n\tNumber of rows of the matrix: ");
				scanf( "%i", &rows );
				printf( "\n\tNumber of columns of the matrix: ");
				scanf( "%i", &cols );

				matrix_t *matrix_m = new_matrix(rows, cols);
				printf( "\n\tFill matrix A: ");
				fill_matrix(matrix_m);

				printf("\n\tInsert a scalar: ");
				scanf("%lf", &scal);
				
				matrix_t *matrix_s = new_matrix(rows, cols);
				matrix_s = scalar_mul(matrix_m, scal);

				printf("\n\tCalculating: wait...\n");
				sleep (count);

				printf( "\n Matrix A: ");
				matrix_print(matrix_m);
				save_matrix(matrix_m, "\n Matrix A", "matrix.txt");
				matrix_free(matrix_m);
				printf( "\n Solution, Matrix B: ");
				matrix_print(matrix_s);
				save_matrix(matrix_s, "\n Solution, Matrix B:", "matrix.txt");
				matrix_free(matrix_s);
				break;
			
			case trasp: 
				printf( "\n\tNumber of rows of the matrix: ");
				scanf( "%i", &rows );
				printf( "\n\tNumber of columns of the matrix: ");
				scanf( "%i", &cols );

				matrix_t *matrix_a = new_matrix(rows, cols);
				printf( "\n\tFill matrix A: ");
				fill_matrix(matrix_a);

				matrix_t *matrix_transp = new_matrix(rows, cols);
				matrix_transp = transpose(matrix_a);
				
				printf("\n\tCalculating: wait...\n");
				sleep (count);
				
				printf( "\n Matrix A: ");
				matrix_print(matrix_a);
				save_matrix(matrix_a, "\n Matrix A", "matrix.txt");
				matrix_free(matrix_a);

				printf( "\n Solution, Matrix A transposed: ");
				matrix_print(matrix_transp);
				save_matrix(matrix_transp, "\n Solution, Matrix A transposed:", "matrix.txt");
				matrix_free(matrix_transp);

			default:
				break;
		}
		
		clean_stdin();
	}
	
	while (value != 0);
		printf("\nINFO: has left the program, Until next time %s\n\n", getenv(USER));
	
	matrix_free(matrix);
	
	return NO_ERROR;
           
}
#define _CRT_SECURE_NO_WARNINGS

/*
 * algebra.c
 *
 *  Created on: Jan 4, 2021
 *      Author: Timor
 */


#include <stdio.h>
#include "algebra.h"
#include "mult.h"
#include "functions.h"

void PrintNxNMatrix(double A[MATRIX_nXn][MATRIX_nXn], size_t n)
{
	DEBUG_PRINT("matrix %dX%d:\n", (int)n, (int)n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			DEBUG_PRINT(" %f ", A[i][j]);
		}
		DEBUG_PRINT("\n");
	}
}






int main()
{

	DEBUG_PRINT("*Recrusive multiplications*\n");
	
	int x, y, res;
	x = 3;
	y = 5;
	res = multiply(3, 5);

	printf("result recrusive %d * %d = %d", x, y, res);
	getchar();
	int n = 2;
	double A[2][2];// = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

	//A = { 0 };

	
	DEBUG_PRINT("write matrix [%d]X[%d]\n", n, n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			printf("Enter value for disp[%d][%d]:", i, j);
			res = scanf("%lf", &A[i][j]);
			if (res != 1)
				j--;
			//A[i][j] = (double)i*j;
		}

	PrintNxNMatrix(A, n);
	DEBUG_PRINT("*DONE*\n");
	res = getchar();
	return 0;
}
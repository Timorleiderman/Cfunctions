#include "algebra.h"
#include "functions.h"

#include <math.h>

// matrix multiplication func A*B
void multMatrix(double A[MATRIX_nXn][MATRIX_nXn], double B[MATRIX_nXn][MATRIX_nXn], double res[MATRIX_nXn], size_t n)
{
	int i;
	int j;
	for (i = 0; i < n; i++)
		res[i] = 0;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			res[i] += A[i][j] * B[j][i];
}

// transpose matrix only NxN
void transpose(double A[MATRIX_nXn][MATRIX_nXn], double res[MATRIX_nXn][MATRIX_nXn], size_t n) {
	int i, j;
	for (i = 0;i < n; i++)
		for (j = 0; j < n; j++)
			res[i][j] = A[j][i];
}

// cofactor algorithem for solving inverse matrix
void cofactor(double src[MATRIX_nXn][MATRIX_nXn], double dst[MATRIX_nXn][MATRIX_nXn], size_t n, double det) {

	double minerMat[MATRIX_nXn][MATRIX_nXn];
	double cofactorMat[MATRIX_nXn][MATRIX_nXn];

	int i;
	int j;
	int row;
	int col;
	int minRow;
	int minCol;

	double sign;
	for (row = 0; row < n; row++)
		for (col = 0; col < n; col++)
		{
			minRow = 0;
			minCol = 0;
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++) 
				{
					if (i != row && j != col) 
					{
						minerMat[minCol][minRow] = src[i][j];
						if (minCol < (n - 2))
						{
							minCol++;
						}
						else 
						{
							minCol = 0;
							minRow++;
						}
					}
				}
			}
			sign = (double)row + (double)col;
			cofactorMat[row][col] = pow(-1, sign) * determinant(minerMat, (n - 1));
		}

	transpose(cofactorMat, dst, n);

	for (row = 0; row < n; row++)
		for (col = 0; col < n; col++)
			dst[row][col] = dst[row][col] / det;

}

// inverse of a matrix with cofactor algorithem
void inverse(double src[MATRIX_nXn][MATRIX_nXn], double dst[MATRIX_nXn][MATRIX_nXn], size_t n, double det) {
	if (det == 0)
		DEBUG_PRINT("\n Matrix cannot inverse det = 0\n");
	else if (n == 1)
		dst[0][0] = 1;
	else
		cofactor(src, dst, n, det);
}


// calculate minor matrix for determinant of NxN matrix
// idx is the location of the minor matrix to be calculated
// n size of matrix nXn
void minorMat(double A[MATRIX_nXn][MATRIX_nXn], double res[MATRIX_nXn][MATRIX_nXn], size_t idx, size_t n)
{
	int i = 0;
	int j = 0;

	for (int row = 1; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			if (idx == col)
				continue;

			res[i][j] = A[row][col];
			j++;
			if (j == n - 1)
			{
				i++;
				j = 0;
			}

		}
	}
}

// calculate the determinant of nXn matrix
double determinant(double A[MATRIX_nXn][MATRIX_nXn], size_t n) {
	int i;
	double tmp[MATRIX_nXn][MATRIX_nXn];
	double res = 0;

	if (n == 1) {
		return A[0][0];
	}
	else if (n == 2) {
		return (A[0][0] * A[1][1] - A[0][1] * A[1][0]);
	}
	else {
		for (i = 0;i < n; i++) {
			minorMat(tmp, A, i, n);
			res = (res + A[0][i] * pow(-1, i) * determinant(tmp, (n - 1)));
		}

		return res;
	}

}

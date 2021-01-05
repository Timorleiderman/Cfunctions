#pragma once
/*
 * algebra.h
 *
 *  Created on: Jan 4, 2021
 *      Author: Timor
 */

#ifndef ALGEBRA_H_
#define ALGEBRA_H_

#define MATRIX_nXn 3

void multMatrix(double A[MATRIX_nXn][MATRIX_nXn], double B[MATRIX_nXn][MATRIX_nXn], double res[MATRIX_nXn], size_t n);

void transpose(double A[MATRIX_nXn][MATRIX_nXn], double res[MATRIX_nXn][MATRIX_nXn], size_t n);

void cofactor(double src[MATRIX_nXn][MATRIX_nXn], double dst[MATRIX_nXn][MATRIX_nXn], size_t n, double det);

void inverse(double src[MATRIX_nXn][MATRIX_nXn], double dst[MATRIX_nXn][MATRIX_nXn], size_t n, double det);

void minorMat(double A[MATRIX_nXn][MATRIX_nXn], double res[MATRIX_nXn][MATRIX_nXn], size_t idx, size_t n);

double determinant(double A[MATRIX_nXn][MATRIX_nXn], size_t n);



#endif /* ALGEBRA_H_ */

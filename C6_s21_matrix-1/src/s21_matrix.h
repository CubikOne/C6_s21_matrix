#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum Error {
  OK = 0,
  INVALID_MATRIX = 1,
  COMPUTATION_ERROR = 2,
};

#define SUCCESS 1
#define FAILURE 0

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

int s21_eq_matrix(matrix_t *A, matrix_t *B);

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
int s21_same(matrix_t *A, matrix_t *B);
int s21_correct_matrix(matrix_t *A);
int s21_equal(matrix_t *A, matrix_t *B);
int s21_matrix_square(matrix_t *A);
void s21_matrix_minor(matrix_t *matrix, matrix_t *submatrix, int row_to_skip,
                      int column_to_skip);
double s21_find_determinant(matrix_t *A);

#endif
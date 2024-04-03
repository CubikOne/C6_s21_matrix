#include "s21_matrix.h"
/**
 * Транспонирует матрицу.
 * Транспонирование матрицы А заключается в замене строк этой матрицы ее
 * столбцами с сохранением их номеров.
 * @param A - Указатель на входную матрицу 'A'.
 * @param result - Указатель на выходную матрицу 'result'.
 * @return - 'OK', если матрица была успешно транспонирована, 'INVALID_MATRIX',
 * если 'A' не является допустимой матрицей.
 */
int s21_transpose(matrix_t *A, matrix_t *result) {
  if (!s21_correct_matrix(A)) return INVALID_MATRIX;

  s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++) result->matrix[j][i] = A->matrix[i][j];

  return OK;
}
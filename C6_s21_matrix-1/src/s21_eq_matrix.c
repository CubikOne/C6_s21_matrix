#include "s21_matrix.h"
/**
 * @brief Проверяет равенство двух матриц с учетом погрешности.
 * @param A: Указатель на первую матрицу.
 * @param B: Указатель на вторую матрицу.
 * @return SUCCESS, если матрицы равны. FAILURE, если матрицы не равны или
 * одна из матриц некорректна.
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!s21_correct_matrix(A) || !s21_correct_matrix(B)) return FAILURE;
  if (!s21_same(A, B)) return FAILURE;

  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) return FAILURE;

  return SUCCESS;
}
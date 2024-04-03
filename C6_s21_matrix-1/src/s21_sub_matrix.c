#include "s21_matrix.h"
/**
 * @brief Выполняет вычитание одной матрицы из другой.
 * @param A: Указатель на первую матрицу.
 * @param B: Указатель на вторую матрицу, из которой вычитается.
 * @param result: Указатель на структуру matrix_t, в которой будет храниться
 * результат вычитания.
 * @return OK, если вычитание успешно выполнено. INVALID_MATRIX, если одна из
 * матриц некорректна или если указатель на результат не задан.
 * COMPUTATION_ERROR, если матрицы не имеют одинаковых размеров.
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_correct_matrix(A) || !s21_correct_matrix(B) || result == NULL)
    return INVALID_MATRIX;
  if (!s21_same(A, B)) return COMPUTATION_ERROR;

  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];

  return OK;
}
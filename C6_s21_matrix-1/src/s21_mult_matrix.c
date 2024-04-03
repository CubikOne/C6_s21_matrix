#include "s21_matrix.h"
/**
 * @brief Выполняет умножение двух матриц.
 * @param A: Указатель на первую матрицу.
 * @param B: Указатель на вторую матрицу.
 * @param result: Указатель на структуру matrix_t, в которой будет храниться
 * результат умножения матриц.
 * @return OK, если умножение успешно выполнено. INVALID_MATRIX, если одна из
 * матриц некорректна. COMPUTATION_ERROR, если матрицы не могут быть умножены
 * (например, количество столбцов первой матрицы не равно количеству строк
 * второй матрицы).
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!s21_correct_matrix(A) || !s21_correct_matrix(B)) return INVALID_MATRIX;
  if (!s21_equal(A, B)) return COMPUTATION_ERROR;

  s21_create_matrix(A->rows, B->columns, result);
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < B->columns; j++)
      for (int k = 0; k < B->rows; k++)
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];

  return OK;
}
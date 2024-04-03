#include "s21_matrix.h"
/**
 * @brief Выполняет умножение каждого элемента матрицы на заданное число.
 * @param A: Указатель на исходную матрицу.
 * @param number: Число, на которое будут умножены все элементы матрицы.
 * @param result: Указатель на структуру matrix_t, в которой будет храниться
 * результат умножения.
 * @return OK, если умножение успешно выполнено. INVALID_MATRIX, если исходная
 * матрица некорректна. COMPUTATION_ERROR, если возникла ошибка при создании
 * матрицы для результата.
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (!s21_correct_matrix(A)) return INVALID_MATRIX;
  if (s21_create_matrix(A->rows, A->columns, result)) return COMPUTATION_ERROR;

  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++)
      result->matrix[i][j] = A->matrix[i][j] * number;

  return OK;
}
#include "s21_matrix.h"
/**
 * @brief Вычисляет обратную матрицу для квадратной матрицы.
 * @param A: Указатель на исходную квадратную матрицу.
 * @param result: Указатель на структуру matrix_t, в которой будет храниться
 * результат вычисления обратной матрицы.
 * @return OK, если обратная матрица успешно вычислена. INVALID_MATRIX, если
 * исходная матрица некорректна или не является квадратной. COMPUTATION_ERROR,
 * если возникла ошибка при вычислении обратной матрицы (например, если
 * определитель исходной матрицы равен нулю).
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!s21_correct_matrix(A)) return INVALID_MATRIX;
  if (!s21_matrix_square(A)) return COMPUTATION_ERROR;
  double determinant = 0;
  s21_determinant(A, &determinant);
  if (determinant != 0 && fabs(determinant) > 1e-07) {
    matrix_t temp1, temp2;
    s21_calc_complements(A, &temp1);
    s21_transpose(&temp1, &temp2);
    s21_mult_number(&temp2, 1. / determinant, result);
    s21_remove_matrix(&temp1);
    s21_remove_matrix(&temp2);
  } else
    return COMPUTATION_ERROR;

  return OK;
}
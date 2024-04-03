#include "s21_matrix.h"
/**
 * @brief Вычисляет комплекс матрицы.
 * @param A: Указатель на исходную матрицу.
 * @param result: Указатель на структуру matrix_t, в которой будет храниться
результат вычисления комплекса.
 * @return
OK, если комплекс успешно вычислен.
INVALID_MATRIX, если исходная матрица некорректна или не является квадратной.
COMPUTATION_ERROR, если возникла ошибка при вычислении комплекса.
 */
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!s21_correct_matrix(A)) return INVALID_MATRIX;
  if (!s21_matrix_square(A)) return COMPUTATION_ERROR;

  int test = s21_create_matrix(A->rows, A->columns, result);
  if (!test) {
    if (A->rows == 1)
      result->matrix[0][0] = A->matrix[0][0];
    else {
      matrix_t minor = {0};
      test = s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
      if (!test) {
        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            s21_matrix_minor(A, &minor, i, j);
            result->matrix[i][j] = s21_find_determinant(&minor);
          }
        }

        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            result->matrix[i][j] =
                ((i + j) % 2 ? -1 : 1) * result->matrix[i][j];
          }
        }
      } else
        return COMPUTATION_ERROR;
      s21_remove_matrix(&minor);
    }
  }

  return OK;
}
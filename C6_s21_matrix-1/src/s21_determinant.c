#include "s21_matrix.h"
/**
 @brief Вычисляет определитель квадратной матрицы.
 @param A: Указатель на исходную квадратную матрицу.
 @param result: Указатель на переменную типа double, в которую будет записан
 результат вычисления определителя.
 @return

OK, если определитель успешно вычислен.
INVALID_MATRIX, если исходная матрица некорректна или не является квадратной.
COMPUTATION_ERROR, если возникла ошибка при вычислении определителя.
 */
int s21_determinant(matrix_t *A, double *result) {
  if (!s21_correct_matrix(A)) return INVALID_MATRIX;
  if (!s21_matrix_square(A)) return COMPUTATION_ERROR;

  *result = s21_find_determinant(A);

  return OK;
}
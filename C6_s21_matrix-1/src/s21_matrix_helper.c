#include "s21_matrix.h"
/**
 * @brief Проверяет, имеют ли две матрицы одинаковые размеры.
 * @param A: Указатель на первую матрицу.
 * @param B: Указатель на вторую матрицу.
 * @return 1, если матрицы имеют одинаковые размеры. 0 в противном случае.
 */
int s21_same(matrix_t *A, matrix_t *B) {
  if (A->columns != B->columns || A->rows != B->rows) return 0;
  return 1;
}
/**
 * @brief Проверяет корректность матрицы.
 * @param A: Указатель на матрицу.
 * @return 1, если матрица корректна. 0 в противном случае.
 */
int s21_correct_matrix(matrix_t *A) {
  if (A == NULL) return 0;
  if (A->rows <= 0 || A->columns <= 0 || A->matrix == NULL) return 0;
  return 1;
}
/**
 * @brief Проверяет, можно ли умножить матрицу A на матрицу B.
 * @param A: Указатель на первую матрицу.
 * @param B: Указатель на вторую матрицу.
 * @return 1, если умножение возможно. 0 в противном случае.
 */
int s21_equal(matrix_t *A, matrix_t *B) {
  if (A->columns != B->rows) return 0;
  return 1;
}
/**
 * @brief Проверяет, является ли матрица квадратной.
 * @param A: Указатель на матрицу.
 * @return 1, если матрица квадратная. 0 в противном случае.
 */
int s21_matrix_square(matrix_t *A) {
  if (A->rows != A->columns) return 0;
  return 1;
}
/**
 * @brief Вычисляет минор элемента матрицы.
 * @param matrix: Указатель на исходную матрицу.
 * @param minor: Указатель на структуру matrix_t, в которой будет храниться
 * минор.
 * @param row_to_skip: Индекс строки, которую нужно пропустить.
 * @param column_to_skip: Индекс столбца, который нужно пропустить.
 */
void s21_matrix_minor(matrix_t *matrix, matrix_t *minor, int row_to_skip,
                      int column_to_skip) {
  if (!s21_correct_matrix(matrix) || !s21_correct_matrix(minor)) return;

  int r = 0;
  for (int i = 0; i < matrix->rows; i++) {
    if (i == row_to_skip) continue;
    int c = 0;
    for (int j = 0; j < matrix->columns; j++) {
      if (j == column_to_skip) continue;
      minor->matrix[r][c] = matrix->matrix[i][j];
      c++;
    }
    r++;
  }
}
/**
 * @brief Вычисляет определитель матрицы.
 * @param A: Указатель на матрицу.
 * @return Определитель матрицы. Возвращает 2, если матрица некорректна или
 * не является квадратной.
 */
double s21_find_determinant(matrix_t *A) {
  double determinant = 0.0;

  if (!s21_correct_matrix(A)) return 2;
  if (!s21_matrix_square(A)) return 2;

  if (A->rows == 1) return A->matrix[0][0];

  matrix_t minor;
  s21_create_matrix(A->rows - 1, A->columns - 1, &minor);

  for (int i = 0; i < A->rows; i++) {
    s21_matrix_minor(A, &minor, 0, i);
    if (i % 2)
      determinant -= A->matrix[0][i] * s21_find_determinant(&minor);
    else
      determinant += A->matrix[0][i] * s21_find_determinant(&minor);
  }

  s21_remove_matrix(&minor);
  return determinant;
}
#include "s21_matrix.h"
/**
 * @brief Создает матрицу с указанным количеством строк и столбцов.
 * @param rows: Количество строк в матрице.
 * @param columns: Количество столбцов в матрице.
 * @param result: Указатель на структуру matrix_t, в которой будет храниться
 * матрица.
 * @return OK, если матрица успешно создана. INVALID_MATRIX, если количество
 * строк или столбцов меньше или равно нулю.
 */
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  *result = (matrix_t){0};
  if (rows > 0 && columns > 0) {
    result->rows = rows;
    result->columns = columns;
    double **matrix = (double **)calloc(rows, sizeof(double *));
    double *value = (double *)calloc(rows * columns, sizeof(double));
    for (int i = 0; i < rows; i++) {
      matrix[i] = value + columns * i;
    }
    result->matrix = matrix;
  } else {
    result->matrix = NULL;
    return INVALID_MATRIX;
  }
  return OK;
}
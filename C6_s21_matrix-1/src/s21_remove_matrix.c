#include "s21_matrix.h"
/**
 * @brief Освобождает память, выделенную под матрицу.
 * @param A: Указатель на структуру matrix_t, память под которую нужно
 * освободить.
 */
void s21_remove_matrix(matrix_t *A) {
  if (A->matrix) {
    if (A->matrix[0]) free(A->matrix[0]);
    free(A->matrix);
    if (A->rows) A->rows = 0;
    if (A->columns) A->columns = 0;
    A->matrix = NULL;
  }
}
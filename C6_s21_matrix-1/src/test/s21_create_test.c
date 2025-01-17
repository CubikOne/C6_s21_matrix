#include "s21_test_matrix.h"

START_TEST(create_1) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m.matrix[i][j] = 0;
      ck_assert_ldouble_eq_tol(0, m.matrix[i][j], 1e-07);
    }
  }
  ck_assert_int_eq(m.rows, rows);
  ck_assert_int_eq(m.columns, cols);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(create_2) {
  const int rows = 0;
  const int cols = 10;
  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), INVALID_MATRIX);
}
END_TEST

START_TEST(create_3) {
  const int rows = 10;
  const int cols = 0;

  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), INVALID_MATRIX);
}
END_TEST

START_TEST(create_4) {
  const int rows = 1;
  const int cols = 1;

  matrix_t m;
  ck_assert_int_eq(s21_create_matrix(rows, cols, &m), OK);
  s21_remove_matrix(&m);
}

START_TEST(create_5) {
  matrix_t m = {0};
  ck_assert_int_eq(s21_create_matrix(0, 0, &m), INVALID_MATRIX);
  s21_remove_matrix(&m);
}
END_TEST

Suite *suite_create_matrix(void) {
  Suite *s = suite_create("suite_create_matrix");
  TCase *tc = tcase_create("case_create_matrix");

  tcase_add_test(tc, create_1);
  tcase_add_test(tc, create_2);
  tcase_add_test(tc, create_3);
  tcase_add_test(tc, create_4);
  tcase_add_test(tc, create_5);

  suite_add_tcase(s, tc);
  return s;
}
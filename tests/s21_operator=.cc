#include "s21_matrix_tests.h"

TEST(Test_OP_Assignment, TestCase_1) {
  S21Matrix matrix;
  S21Matrix m2;

  matrix(2, 2) = 5;

  m2 = matrix;

  ASSERT_TRUE(matrix == m2);
}
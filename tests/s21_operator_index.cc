#include "s21_matrix_tests.h"

TEST(Test_OP_INDEX, TestCase_1) {
  S21Matrix matrix;

  ASSERT_EQ(matrix(2, 2), 0);
}

TEST(Test_OP_INDEX, TestCase_2) {
  S21Matrix matrix;

  matrix(2, 2) = 5;

  ASSERT_EQ(matrix(2, 2), 5);
}
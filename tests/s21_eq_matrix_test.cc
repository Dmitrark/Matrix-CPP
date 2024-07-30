#include "s21_matrix_tests.h"

TEST(Test_EqMatrix, TestCase_1) {
  S21Matrix matrix;
  S21Matrix m2;

  ASSERT_TRUE(matrix.EqMatrix(m2));
}

TEST(Test_EqMatrix, TestCase_2) {
  S21Matrix matrix;
  S21Matrix m2(2, 2);

  ASSERT_FALSE(matrix.EqMatrix(m2));
}

TEST(Test_EqMatrix, TestCase_3) {
  S21Matrix matrix;
  S21Matrix m2;

  m2(1, 2) = 9;

  ASSERT_FALSE(matrix.EqMatrix(m2));
}
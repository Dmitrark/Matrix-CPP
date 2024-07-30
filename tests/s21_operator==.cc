#include "s21_matrix_tests.h"

TEST(Test_OP_EQ, TestCase_1) {
  S21Matrix matrix;
  S21Matrix m2;

  ASSERT_TRUE(matrix == m2);
}

TEST(Test_OP_EQ, TestCase_2) {
  S21Matrix matrix;
  S21Matrix m2(2, 2);

  ASSERT_FALSE(matrix == m2);
}

TEST(Test_OP_EQ, TestCase_3) {
  S21Matrix matrix;
  S21Matrix m2;

  m2(1, 2) = 9;

  ASSERT_FALSE(matrix == m2);
}
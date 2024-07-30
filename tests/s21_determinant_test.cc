#include "s21_matrix_tests.h"

TEST(Test_Determinant, TestCase_1) {
  S21Matrix tmp(1, 1);

  tmp(0, 0) = 5;

  ASSERT_DOUBLE_EQ(tmp.Determinant(), 5);
}

TEST(Test_Determinant, TestCase_2) {
  double array[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  double res = 0;

  S21Matrix tmp;

  for (int i = 0; i < 3; i++) {
    for (int i2 = 0; i2 < 3; i2++) {
      tmp(i, i2) = array[i][i2];
    }
  }

  ASSERT_DOUBLE_EQ(tmp.Determinant(), 0);
}

TEST(Test_Determinant, TestCase_3) {
  double array[2][2] = {{2, 1}, {3, 4}};

  S21Matrix tmp(2, 2);

  for (int i = 0; i < 2; i++) {
    for (int i2 = 0; i2 < 2; i2++) {
      tmp(i, i2) = array[i][i2];
    }
  }

  ASSERT_DOUBLE_EQ(tmp.Determinant(), 5);
}

TEST(Test_Determinant, TestCase_4) {
  double array[4][4] = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

  S21Matrix tmp(4, 4);

  for (int i = 0; i < 4; i++) {
    for (int i2 = 0; i2 < 4; i2++) {
      tmp(i, i2) = array[i][i2];
    }
  }

  ASSERT_DOUBLE_EQ(tmp.Determinant(), 0);
}

TEST(Test_Determinant, TestCase_5) {
  S21Matrix tmp(3, 4);

  ASSERT_THROW(tmp.Determinant(), std::out_of_range);
}
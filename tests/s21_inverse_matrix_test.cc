#include "s21_matrix_tests.h"

TEST(Test_InverseMatrix, TestCase_1) {
  double array[3][3] = {{2, 5, 7}, {6, 3, 4}, {5, -2, -3}};
  double res[3][3] = {{1, -1, 1}, {-38, 41, -34}, {27, -29, 24}};
  int error = 0, my_break = 0;

  S21Matrix tmp;

  for (int i = 0; i < 3; i++) {
    for (int i2 = 0; i2 < 3; i2++) {
      tmp(i, i2) = array[i][i2];
    }
  }

  S21Matrix tmp2(tmp.InverseMatrix());

  for (int i = 0; i < 3 && !my_break; i++) {
    for (int i2 = 0; i2 < 3 && !my_break; i2++) {
      if (tmp2(i, i2) != res[i][i2]) {
        error++;
        my_break++;
      }
    }
  }

  ASSERT_EQ(error, OK);
}

TEST(Test_InverseMatrix, TestCase_2) {
  double array[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  S21Matrix tmp;
  S21Matrix tmp2;

  for (int i = 0; i < 3; i++) {
    for (int i2 = 0; i2 < 3; i2++) {
      tmp(i, i2) = array[i][i2];
    }
  }

  ASSERT_THROW(S21Matrix tmp2(tmp.InverseMatrix()), std::logic_error);
}
#include "s21_matrix_tests.h"

TEST(Test_MulNumber, TestCase_1) {
  double array[3][3] = {{1, 2, 3}, {3, 2, 1}, {4, 5, 6}};
  double res[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
  int error = 0, my_break = 0, n = 0;

  S21Matrix tmp;

  for (int i = 0; i < 3; i++) {
    for (int i2 = 0; i2 < 3; i2++) {
      tmp(i, i2) = array[i][i2];
    }
  }

  tmp.MulNumber(n);

  for (int i = 0; i < 3 && !my_break; i++) {
    for (int i2 = 0; i2 < 3 && !my_break; i2++) {
      if (tmp(i, i2) != res[i][i2]) {
        error++;
        my_break++;
      }
    }
  }

  ASSERT_EQ(error, OK);
}

TEST(Test_MulNumber, TestCase_2) {
  double array[3][3] = {{1, 2, 3}, {3, 2, 1}, {4, 5, 6}};
  double res[3][3] = {{0.5, 1, 1.5}, {1.5, 1, 0.5}, {2, 2.5, 3}};

  int error = 0, my_break = 0;
  double n = 0.5;

  S21Matrix tmp;

  for (int i = 0; i < 3; i++) {
    for (int i2 = 0; i2 < 3; i2++) {
      tmp(i, i2) = array[i][i2];
    }
  }

  tmp.MulNumber(n);

  for (int i = 0; i < 3 && !my_break; i++) {
    for (int i2 = 0; i2 < 3 && !my_break; i2++) {
      if (tmp(i, i2) != res[i][i2]) {
        error++;
        my_break++;
      }
    }
  }

  ASSERT_EQ(error, OK);
}
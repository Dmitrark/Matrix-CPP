#include "s21_matrix_tests.h"

TEST(Test_SumMatrix, TestCase_1) {
  double array[3][3] = {{1, 2, 3}, {3, 2, 1}, {4, 5, 6}};
  double array2[3][3] = {{3, 2, 1}, {1, 2, 3}, {6, 5, 4}};
  double res[3][3] = {{4, 4, 4}, {4, 4, 4}, {10, 10, 10}};
  int error = 0, my_break = 0;

  S21Matrix tmp;
  S21Matrix tmp2;

  for (int i = 0; i < 3; i++) {
    for (int i2 = 0; i2 < 3; i2++) {
      tmp(i, i2) = array[i][i2];
      tmp2(i, i2) = array2[i][i2];
    }
  }

  tmp.SumMatrix(tmp2);

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

TEST(Test_SumMatrix, TestCase_2) {
  S21Matrix tmp;
  S21Matrix tmp2(4, 4);

  ASSERT_THROW(tmp.SumMatrix(tmp2), std::out_of_range);
}
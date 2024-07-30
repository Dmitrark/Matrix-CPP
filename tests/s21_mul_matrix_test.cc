#include "s21_matrix_tests.h"

TEST(Test_MulMatrix, TastCase_1) {
  double array[3][2] = {{1, 4}, {2, 5}, {3, 6}};
  double array2[2][3] = {{1, -1, 1}, {2, 3, 4}};
  double res[3][3] = {{9, 11, 17}, {12, 13, 22}, {15, 15, 27}};
  int error = 0, my_break = 0;

  S21Matrix tmp(3, 2);
  S21Matrix tmp2(2, 3);

  for (int i = 0; i < 3; i++) {
    for (int i2 = 0; i2 < 2; i2++) {
      tmp(i, i2) = array[i][i2];
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int i2 = 0; i2 < 3; i2++) {
      tmp2(i, i2) = array2[i][i2];
    }
  }

  tmp.MulMatrix(tmp2);

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

TEST(Test_MulMatrix, TastCase_2) {
  double array[3][2] = {{DBL_MAX, 4}, {2, 5}, {3, 6}};
  double array2[2][3] = {{10, -10, 10}, {20, 30, 40}};
  int error = 0, my_break = 0;

  S21Matrix tmp(3, 2);
  S21Matrix tmp2(2, 3);

  for (int i = 0; i < 3; i++) {
    for (int i2 = 0; i2 < 2; i2++) {
      tmp(i, i2) = array[i][i2];
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int i2 = 0; i2 < 3; i2++) {
      tmp2(i, i2) = array2[i][i2];
    }
  }

  ASSERT_THROW(tmp.MulMatrix(tmp2), std::overflow_error);
}

TEST(Test_MulMatrix, TastCase_3) {
  S21Matrix tmp(3, 3);
  S21Matrix tmp2(2, 3);

  ASSERT_THROW(tmp.MulMatrix(tmp2), std::out_of_range);
}
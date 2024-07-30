#include "s21_matrix_tests.h"

TEST(Test_Acessors_getRows, Test_Case_1) {
  S21Matrix matrix;

  ASSERT_EQ(matrix.getRows(), 3);
}

TEST(Test_Acessors_getRows, Test_Case_2) {
  S21Matrix matrix(4, 2);

  ASSERT_EQ(matrix.getRows(), 4);
}

TEST(Test_Acessors_getCols, Test_Case_1) {
  S21Matrix matrix;

  ASSERT_EQ(matrix.getCols(), 3);
}

TEST(Test_Acessors_getCols, Test_Case_2) {
  S21Matrix matrix(4, 2);

  ASSERT_EQ(matrix.getCols(), 2);
}

TEST(Test_Acessors_setRows, Test_Case_1) {
  double array[3][3] = {{1, 2, 3}, {3, 2, 1}, {4, 5, 6}};
  double res[4][3] = {{1, 2, 3}, {3, 2, 1}, {4, 5, 6}, {0, 0, 0}};
  int error = 0, my_break = 0;

  S21Matrix tmp;

  for (int i = 0; i < 3; i++) {
    for (int i2 = 0; i2 < 3; i2++) {
      tmp(i, i2) = array[i][i2];
    }
  }

  int rows = 4;

  tmp.setRows(rows);

  for (int i = 0; i < rows && !my_break; i++) {
    for (int i2 = 0; i2 < 3 && !my_break; i2++) {
      if (tmp(i, i2) != res[i][i2]) {
        error++;
        my_break++;
      }
    }
  }

  ASSERT_EQ(error, OK);
}

TEST(Test_Acessors_setRows, Test_Case_2) {
  S21Matrix tmp;

  int rows = 0;

  ASSERT_THROW(tmp.setRows(rows), std::out_of_range);
}

TEST(Test_Acessors_setCols, Test_Case_1) {
  double array[3][3] = {{1, 2, 3}, {3, 2, 1}, {4, 5, 6}};
  double res[3][4] = {{1, 2, 3, 0}, {3, 2, 1, 0}, {4, 5, 6, 0}};
  int error = 0, my_break = 0;

  S21Matrix tmp;

  for (int i = 0; i < 3; i++) {
    for (int i2 = 0; i2 < 3; i2++) {
      tmp(i, i2) = array[i][i2];
    }
  }

  int cols = 4;

  tmp.setCols(cols);

  for (int i = 0; i < 3 && !my_break; i++) {
    for (int i2 = 0; i2 < cols && !my_break; i2++) {
      if (tmp(i, i2) != res[i][i2]) {
        error++;
        my_break++;
      }
    }
  }

  ASSERT_EQ(error, OK);
}

TEST(Test_Acessors_setCols, Test_Case_2) {
  S21Matrix tmp;

  int rows = 0;

  ASSERT_THROW(tmp.setCols(rows), std::out_of_range);
}
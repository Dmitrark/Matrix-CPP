#include "s21_matrix_tests.h"

TEST(Test_S21Matrix, TestCase_1) {
  S21Matrix matrix;

  ASSERT_EQ(matrix.getRows(), 3);
}

TEST(Test_S21Matrix, TestCase_2) {
  S21Matrix matrix;

  ASSERT_EQ(matrix.getCols(), 3);
}

TEST(Test_S21Matrix, TestCase_3) {
  S21Matrix matrix;

  double **test_matrix = new double *[3];

  for (int i = 0; i < 3; ++i) {
    test_matrix[i] = new double[3];
    for (int i2 = 0; i2 < 3; ++i2) {
      test_matrix[i][i2] = 0;
    }
  }

  ASSERT_TRUE(matrix.MatricesAreEqual(test_matrix, 3, 3));

  for (int i = 0; i < 3; ++i) {
    delete[] test_matrix[i];
  }
  delete[] test_matrix;
}

TEST(Test_S21Matrix, TestCase_4) {
  S21Matrix matrix;
  for (int i = 0; i < matrix.getRows(); ++i) {
    for (int i2 = 0; i2 < matrix.getCols(); ++i2) {
      ASSERT_EQ(0, matrix(i, i2));
    }
  }
}

TEST(Test_S21Matrix2, TestCase_1) {
  S21Matrix matrix(1, 1);

  ASSERT_EQ(matrix.getRows(), 1);
}

TEST(Test_S21Matrix2, TestCase_2) {
  S21Matrix matrix(1, 1);

  ASSERT_EQ(matrix.getCols(), 1);
}

TEST(Test_S21Matrix2, TestCase_3) {
  S21Matrix matrix(1, 1);

  double **test_matrix = new double *[1];

  for (int i = 0; i < 1; ++i) {
    test_matrix[i] = new double[1];
    for (int i2 = 0; i2 < 1; ++i2) {
      test_matrix[i][i2] = 0;
    }
  }

  ASSERT_TRUE(matrix.MatricesAreEqual(test_matrix, 1, 1));

  for (int i = 0; i < 1; ++i) {
    delete[] test_matrix[i];
  }
  delete[] test_matrix;
}

TEST(Test_S21Matrix2, TestCase_4) {
  S21Matrix matrix(1, 1);
  for (int i = 0; i < matrix.getRows(); ++i) {
    for (int i2 = 0; i2 < matrix.getCols(); ++i2) {
      ASSERT_EQ(0, matrix(i, i2));
    }
  }
}

TEST(Test_S21MatrixCopy, TestCase_1) {
  S21Matrix matrix;

  S21Matrix m2(matrix);

  ASSERT_EQ(m2.getRows(), 3);
}

TEST(Test_S21MatrixCopy, TestCase_2) {
  S21Matrix matrix;

  S21Matrix m2(matrix);

  ASSERT_EQ(m2.getCols(), 3);
}

TEST(Test_S21MatrixCopy, TestCase_3) {
  S21Matrix matrix;

  S21Matrix m2(matrix);

  double **test_matrix = new double *[3];

  for (int i = 0; i < 3; ++i) {
    test_matrix[i] = new double[3];
    for (int i2 = 0; i2 < 3; ++i2) {
      test_matrix[i][i2] = 0;
    }
  }

  ASSERT_TRUE(m2.MatricesAreEqual(test_matrix, 3, 3));

  for (int i = 0; i < 3; ++i) {
    delete[] test_matrix[i];
  }
  delete[] test_matrix;
}

TEST(Test_S21MatrixCopy, TestCase_4) {
  S21Matrix matrix;

  S21Matrix m2(matrix);

  for (int i = 0; i < m2.getRows(); ++i) {
    for (int i2 = 0; i2 < m2.getCols(); ++i2) {
      ASSERT_EQ(0, m2(i, i2));
    }
  }
}

TEST(Test_S21MatrixRelocation, TestCase_1) {
  S21Matrix matrix(5, 5);

  S21Matrix m2(std::move(matrix));

  ASSERT_EQ(matrix.getRows(), 0);
}

TEST(Test_S21MatrixRelocation, TestCase_2) {
  S21Matrix matrix(5, 5);

  S21Matrix m2(std::move(matrix));

  ASSERT_EQ(matrix.getCols(), 0);
}

TEST(Test_S21MatrixRelocation, TestCase_3) {
  S21Matrix matrix(5, 5);

  S21Matrix m2(std::move(matrix));

  ASSERT_EQ(matrix.getMatrix(), nullptr);
}

TEST(Test_S21MatrixRelocation, TestCase_4) {
  S21Matrix matrix;

  S21Matrix m2(matrix);

  for (int i = 0; i < m2.getRows(); ++i) {
    for (int i2 = 0; i2 < m2.getCols(); ++i2) {
      ASSERT_EQ(0, m2(i, i2));
    }
  }
}
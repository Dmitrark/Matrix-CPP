#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <cmath>
#include <cstring>
#include <iostream>
#include <stdexcept>

#define FAILURE 0

#define EPS 1e-7

class S21Matrix {
 private:
  int _rows, _cols;
  double** _matrix;

 public:
  // Constructors
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  // Destructor
  ~S21Matrix();

  // Operations
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Minor(int row, int column);
  double Determinant();
  S21Matrix InverseMatrix();

  // Operators
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  bool operator==(const S21Matrix& other);
  void operator=(const S21Matrix& other);
  void operator+=(const S21Matrix& other);
  void operator-=(const S21Matrix& other);
  void operator*=(const S21Matrix& other);
  void operator*=(const double num);
  double& operator()(int i, int j);

  // Acessors
  int getRows() const;
  int getCols() const;
  double** getMatrix() const;

  // Mutators
  void setRows(int rows);
  void setCols(int cols);

  // For_test
  bool MatricesAreEqual(double** other, int rows, int cols) {
    if (getRows() != rows || getCols() != cols) {
      return false;
    }

    for (int i = 0; i < getRows(); ++i) {
      for (int i2 = 0; i2 < getCols(); ++i2) {
        if (_matrix[i][i2] != other[i][i2]) {
          return false;
        }
      }
    }

    return true;
  }
};

#endif
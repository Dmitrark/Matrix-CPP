#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result(*this);

  result.SumMatrix(other);

  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix result(*this);

  result.SubMatrix(other);

  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result(*this);

  result.MulMatrix(other);

  return result;
}

bool S21Matrix::operator==(const S21Matrix& other) {
  S21Matrix result(*this);

  return result.EqMatrix(other);
}

void S21Matrix::operator=(const S21Matrix& other) {
  for (int i = 0; i < _rows; ++i) {
    delete[] _matrix[i];
  }
  delete[] _matrix;

  _matrix = new double*[other._rows];

  for (int i = 0; i < other._rows; ++i) {
    _matrix[i] = new double[other._cols];
    for (int i2 = 0; i2 < _cols; ++i2) {
      _matrix[i][i2] = other._matrix[i][i2];
    }
  }

  _rows = other._rows;
  _cols = other._cols;
}

void S21Matrix::operator+=(const S21Matrix& other) { SumMatrix(other); }

void S21Matrix::operator-=(const S21Matrix& other) { SubMatrix(other); }

void S21Matrix::operator*=(const S21Matrix& other) { MulMatrix(other); }

void S21Matrix::operator*=(const double num) { MulNumber(num); }

double& S21Matrix::operator()(int i, int j) {
  if (i < 0 && j < 0 && i > _rows && j > _cols) {
    throw std::out_of_range("Error: out of range");
  } else
    return _matrix[i][j];
}
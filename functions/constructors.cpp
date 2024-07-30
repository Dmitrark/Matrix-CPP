#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : _rows(3), _cols(3) {
  _matrix = new double*[_rows];

  for (int i = 0; i < _rows; ++i) {
    _matrix[i] = new double[_cols];
    for (int i2 = 0; i2 < _cols; ++i2) {
      _matrix[i][i2] = 0;
    }
  }
}

S21Matrix::S21Matrix(int rows, int cols) : _rows(rows), _cols(cols) {
  _matrix = new double*[_rows];

  for (int i = 0; i < _rows; ++i) {
    _matrix[i] = new double[_cols];
    for (int i2 = 0; i2 < _cols; ++i2) {
      _matrix[i][i2] = 0;
    }
  }
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : _rows(other._rows), _cols(other._cols) {
  _matrix = new double*[_rows];

  for (int i = 0; i < _rows; ++i) {
    _matrix[i] = new double[_cols];
    for (int i2 = 0; i2 < _cols; ++i2) {
      _matrix[i][i2] = other._matrix[i][i2];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : _rows(other._rows), _cols(other._cols), _matrix(other._matrix) {
  other._rows = 0;
  other._cols = 0;
  other._matrix = nullptr;
}

S21Matrix::~S21Matrix() {
  if (_matrix) {
    for (int i = 0; i < _rows; ++i) {
      delete[] _matrix[i];
    }
    delete[] _matrix;
  }
}
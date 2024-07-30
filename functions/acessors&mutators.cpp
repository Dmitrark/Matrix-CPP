#include "s21_matrix_oop.h"

int S21Matrix::getRows() const { return _rows; }
int S21Matrix::getCols() const { return _cols; }
double** S21Matrix::getMatrix() const { return _matrix; }

// Mutators
void S21Matrix::setRows(int rows) {
  if (rows <= 0) {
    throw std::out_of_range("Error: out of range.");
  }

  S21Matrix result(rows, _cols);

  for (int i = 0; i < rows && i < _rows; ++i) {
    for (int i2 = 0; i2 < _cols; ++i2) {
      result._matrix[i][i2] = _matrix[i][i2];
    }
  }

  std::swap(_rows, result._rows);
  std::swap(_cols, result._cols);
  std::swap(_matrix, result._matrix);
}

void S21Matrix::setCols(int cols) {
  if (cols <= 0) {
    throw std::out_of_range("Error: out of range.");
  }
  S21Matrix result(_rows, cols);

  for (int i = 0; i < _rows; ++i) {
    for (int i2 = 0; i2 < cols && i2 < _cols; ++i2) {
      result._matrix[i][i2] = _matrix[i][i2];
    }
  }

  std::swap(_rows, result._rows);
  std::swap(_cols, result._cols);
  std::swap(_matrix, result._matrix);
}
#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (_rows != other._rows && _cols != other._cols) return false;

  int errcode = true, my_break = 0;

  for (int row = 0; row < _rows && !my_break; row++) {
    for (int column = 0; column < _cols && !my_break; column++) {
      if (fabs(_matrix[row][column] - other._matrix[row][column]) >= EPS) {
        errcode = false;
        my_break = true;
      }
    }
  }
  return errcode;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (_rows != other._rows && _cols != other._cols) {
    throw std::out_of_range(
        "Error: Incorrect matrices should have the same size");
  }

  for (int row = 0; row < _rows; row++) {
    for (int column = 0; column < _cols; column++) {
      _matrix[row][column] = _matrix[row][column] + other._matrix[row][column];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (_rows != other._rows && _cols != other._cols) {
    throw std::out_of_range(
        "Error: Incorrect matrices. Should have the same size");
  }

  for (int row = 0; row < _rows; row++) {
    for (int column = 0; column < _cols; column++) {
      _matrix[row][column] = _matrix[row][column] - other._matrix[row][column];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int row = 0; row < _rows; row++) {
    for (int column = 0; column < _cols; column++) {
      _matrix[row][column] = _matrix[row][column] * num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (_cols != other._rows) {
    throw std::out_of_range(
        "Error: Incorrect matrices. Should have the same size of rows and "
        "collumns");
  }

  S21Matrix matrix(_rows, other._cols);

  int errcode = false;

  for (int i = 0; i < _rows && !errcode; i++) {
    for (int j = 0; j < other._cols; j++) {
      for (int k = 0; k < _cols && !errcode; k++) {
        matrix._matrix[i][j] += _matrix[i][k] * other._matrix[k][j];
        if (std::isinf(matrix._matrix[i][j])) {
          throw std::overflow_error("Error: value is infinite");
        }
      }
    }
  }

  std::swap(_cols, matrix._cols);
  std::swap(_rows, matrix._rows);
  std::swap(_matrix, matrix._matrix);
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix matrix(_cols, _rows);

  for (int row = 0; row < _rows; row++) {
    for (int columns = 0; columns < _cols; columns++) {
      matrix._matrix[columns][row] = _matrix[row][columns];
    }
  }

  return matrix;
}

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix matrix(_cols, _rows);

  for (int row = 0; row < _rows; row++) {
    for (int column = 0; column < _cols; column++) {
      matrix(row, column) = Minor(row, column) * pow(-1, row + column);
    }
  }

  return matrix;
}

double S21Matrix::Minor(int row, int column) {
  S21Matrix result(_rows - 1, _cols - 1);

  for (int rowA = 0, rowR = 0; rowR < result._rows; rowA++, rowR++) {
    if (row == rowA) rowA++;

    for (int columnA = 0, columnR = 0; columnR < result._cols;
         columnA++, columnR++) {
      if (column == columnA) columnA++;
      result._matrix[rowR][columnR] = _matrix[rowA][columnA];
    }
  }

  return result.Determinant();
}

double S21Matrix::Determinant() {
  double result = 1;

  if (_cols != _rows) {
    throw std::out_of_range(
        "Error: Incorrect matrix. Should have the same size of rows and "
        "collumns");
  }

  if (_rows == 1) {
    result = _matrix[0][0];
  } else if (_rows == 2) {
    result = _matrix[0][0] * _matrix[1][1] - _matrix[0][1] * _matrix[1][0];
  } else {
    double coefficient;
    int add = 0;

    for (; _rows - add > 3; add++) {
      result *= _matrix[add][add];

      for (int row = add; row < _rows - 1; row++) {
        coefficient = _matrix[row + 1][add] / _matrix[add][add];

        for (int col = 0; col < _cols; col++) {
          _matrix[row + 1][col] =
              _matrix[row + 1][col] - (_matrix[add][col] * coefficient);
        }
      }
    }
    result = result * (_matrix[0 + add][0 + add] * _matrix[1 + add][1 + add] *
                           _matrix[2 + add][2 + add] +
                       _matrix[1 + add][0 + add] * _matrix[2 + add][1 + add] *
                           _matrix[0 + add][2 + add] +
                       _matrix[0 + add][1 + add] * _matrix[1 + add][2 + add] *
                           _matrix[2 + add][0 + add] -
                       _matrix[0 + add][2 + add] * _matrix[1 + add][1 + add] *
                           _matrix[2 + add][0 + add] -
                       _matrix[1 + add][2 + add] * _matrix[2 + add][1 + add] *
                           _matrix[0 + add][0 + add] -
                       _matrix[1 + add][0 + add] * _matrix[0 + add][1 + add] *
                           _matrix[2 + add][2 + add]);
  }

  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double d = Determinant();

  if (d == 0) {
    throw std::logic_error("Error: determinant equal zero.");
  }

  S21Matrix temp = CalcComplements();
  S21Matrix temp2 = temp.Transpose();
  temp2.MulNumber((double)1 / d);

  return temp2;
}
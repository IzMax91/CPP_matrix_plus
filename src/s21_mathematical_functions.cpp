#include <cmath>

#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool answer = true;

  if (rows_ != other.rows_ || cols_ != other.cols_) {
    answer = false;
  } else {
    for (int i = 0; i < rows_ && answer; i++) {
      for (int j = 0; j < cols_ && answer; j++) {
        if (matrix_[i][j] != other.matrix_[i][j]) {
          answer = false;
        }
      }
    }
  }

  return answer;
}

void S21Matrix::SumMatrix(const S21Matrix& other) { SumAndSub(other, 1); }
void S21Matrix::SubMatrix(const S21Matrix& other) { SumAndSub(other, -1); }

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::invalid_argument("Matrices of different sizes");
  } else {
    S21Matrix result(rows_, other.cols_);

    for (int i = 0; i < result.rows_; i++) {
      for (int j = 0; j < result.cols_; j++) {
        for (int k = 0; k < cols_; k++) {
          result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
        }
      }
    }

    MatrixCleaning();
    rows_ = result.rows_;
    cols_ = result.cols_;
    CreatingMatrix();
    CopyingMatrix(result);
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }

  return result;
}

double S21Matrix::Determinant() {
  double result = 0;

  if (rows_ != cols_) {
    throw std::invalid_argument("The matrix is ​​not square");
  } else if (rows_ == 1) {
    result = matrix_[0][0];
  } else if (rows_ == 2) {
    result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
  } else {
    for (int i = 0; i < cols_; i++) {
      S21Matrix minor = MinorMatrex(0, i);

      double num = minor.Determinant();
      result += pow(-1, i) * matrix_[0][i] * num;
    }
  }

  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix result(rows_, cols_);

  if (rows_ != cols_) {
    throw std::invalid_argument("The matrix is ​​not square");
  }

  else if (rows_ == 1) {
    result.matrix_[0][0] = matrix_[0][0];

  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        S21Matrix minor = MinorMatrex(i, j);

        result.matrix_[i][j] = minor.Determinant() * (double)(pow(-1, i + j));
      }
    }
  }

  return result;
}

S21Matrix S21Matrix ::InverseMatrix() {
  double determinant = 0.0;

  if (rows_ != cols_) {
    throw std::invalid_argument("The matrix is ​​not square");
  } else if ((determinant = Determinant()) == 0) {
    throw std::invalid_argument("Determinant is 0");
  } else {
    determinant = 1.0 / determinant;
  }

  return (this->CalcComplements().Transpose() * determinant);
}
#include "s21_matrix_oop.h"

void S21Matrix::CreatingMatrix() {
  matrix_ = new double* [rows_] {};
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]{};
  }
}

void S21Matrix::MatrixCleaning() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}

// void S21Matrix::PrintMatrix() {
//   std::cout << "Rows = " << rows_ << "\n";
//   std::cout << "Cols = " << cols_ << "\n\n";
//   for (int i = 0; i < rows_; i++) {
//     for (int j = 0; j < cols_; j++) {
//       std::cout << "|" << matrix_[i][j];
//     }
//     std::cout << "|\n";
//   }
//   std::cout << "\n";
// }

void S21Matrix::FillingMatrix(double num, double factor) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = num;
      num += factor;
    }
  }
}

void S21Matrix::SumAndSub(const S21Matrix& other, int sign) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Matrices of different sizes");
  } else {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        matrix_[i][j] += other.matrix_[i][j] * (double)sign;
      }
    }
  }
}

void S21Matrix::CopyingMatrix(const S21Matrix& other) {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      if (i < other.cols_ && j < other.cols_) {
        matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }
}

S21Matrix S21Matrix::MinorMatrex(int row, int col) {
  S21Matrix result(rows_ - 1, cols_ - 1);
  for (int i = 0, new_row = 0; i < rows_; i++) {
    if (i != row) {
      for (int j = 0, new_col = 0; j < cols_; j++) {
        if (j != col) {
          result.matrix_[new_row][new_col++] = matrix_[i][j];
        }
      }
      new_row++;
    }
  }

  return result;
}

void S21Matrix::WorkpieceDeterminant() {
  matrix_[0][0] = -0.25;
  matrix_[0][1] = -0.125;
  matrix_[0][2] = 0.75;
  matrix_[1][0] = -0.25;
  matrix_[1][1] = 0.375;
  matrix_[1][2] = -0.25;
  matrix_[2][0] = 0.75;
  matrix_[2][1] = -0.125;
  matrix_[2][2] = -0.25;
}
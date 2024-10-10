#include "s21_matrix_oop.h"

int S21Matrix::GetRows() { return rows_; }

int S21Matrix::GetCols() { return cols_; }

void S21Matrix::SetRows(int num) {
  if (num <= 0) {
    throw std::invalid_argument("Incorrect rows");
  } else if (num != rows_) {
    S21Matrix intermediate(*this);

    MatrixCleaning();
    rows_ = num;
    CreatingMatrix();
    CopyingMatrix(intermediate);
  }
}
void S21Matrix::SetCols(int num) {
  if (num <= 0) {
    throw std::invalid_argument("Incorrect cols");
  } else if (num != cols_) {
    S21Matrix intermediate(*this);

    MatrixCleaning();
    cols_ = num;
    CreatingMatrix();
    CopyingMatrix(intermediate);
  }
}
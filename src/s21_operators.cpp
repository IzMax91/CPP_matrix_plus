#include "s21_matrix_oop.h"

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix answer(*this);
  answer.SumMatrix(other);
  return answer;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix answer(*this);
  answer.SubMatrix(other);
  return answer;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix answer(*this);
  answer.MulMatrix(other);
  return answer;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix answer(*this);
  answer.MulNumber(num);
  return answer;
}

bool S21Matrix::operator==(const S21Matrix& other) {
  return this->EqMatrix(other);
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  MatrixCleaning();
  rows_ = other.rows_;
  cols_ = other.cols_;
  CreatingMatrix();
  CopyingMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);
  return *this;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  this->MulNumber(num);
  return *this;
}

double S21Matrix::operator()(int i, int j) {
  if (i < 0 || i >= rows_) {
    throw std::invalid_argument(
        "The specified rows is outside the array boundaries");
  }
  if (j < 0 || j >= cols_) {
    throw std::invalid_argument(
        "The specified columns is outside the array boundaries");
  }

  return matrix_[i][j];
}

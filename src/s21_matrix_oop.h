#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

  void CreatingMatrix();
  void MatrixCleaning();

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  int GetRows();
  int GetCols();
  void SetRows(int num);
  void SetCols(int num);

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  double Determinant();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  bool operator==(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  double operator()(int i, int j);

  void PrintMatrix();
  void FillingMatrix(double num, double factor);
  void SumAndSub(const S21Matrix& other, int sign);
  void CopyingMatrix(const S21Matrix& other);
  S21Matrix MinorMatrex(int row, int col);
  void WorkpieceDeterminant();
};

#endif  // S21_MATRIX_OOP_H
#include "s21_matrix_oop.h"

int main() {
  S21Matrix A(6, 6);
  A.FillingMatrix(1, 1);
  S21Matrix B(1, 1);
  B.FillingMatrix(1, 1);

  (A * B).PrintMatrix();

  return 0;
}
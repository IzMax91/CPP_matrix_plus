#include "main_test.h"

TEST(MathematicalFunc, TrueEqMatrix) {
  S21Matrix A;
  A.FillingMatrix(1, 2);
  S21Matrix B(A);

  EXPECT_TRUE(A.EqMatrix(B));
}

TEST(MathematicalFunc, FalseEqMatrix) {
  S21Matrix A;
  A.FillingMatrix(1, 2);
  S21Matrix B;
  B.FillingMatrix(1, -2);

  EXPECT_FALSE(A.EqMatrix(B));

  A.SetRows(5);

  EXPECT_FALSE(A.EqMatrix(B));
}

TEST(MathematicalFunc, SumMatrix) {
  S21Matrix A;
  A.FillingMatrix(1, 0);
  S21Matrix B;
  B.FillingMatrix(2, 0);

  A.SumMatrix(B);

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), 3);
    }
  }
}

TEST(MathematicalFunc, SubMatrix) {
  S21Matrix A;
  A.FillingMatrix(1, 0);
  S21Matrix B;
  B.FillingMatrix(2, 0);

  A.SubMatrix(B);
  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), -1);
    }
  }
}

TEST(MathematicalFunc, MatricesDifferentSizes) {
  S21Matrix A(2, 3);
  A.FillingMatrix(1, 0);
  S21Matrix B(3, 2);
  A.FillingMatrix(2, 0);

  bool error = false;

  try {
    A.SubMatrix(B);

  } catch (const std::exception& e) {
    error = true;
  }

  EXPECT_TRUE(error);
}

TEST(MathematicalFunc, MulNumber) {
  S21Matrix A;
  A.FillingMatrix(1, 1);

  A.MulNumber(2);

  int num = 2;
  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), num);
      num += 2;
    }
  }
}

TEST(MathematicalFunc, MulMatrix) {
  S21Matrix A(2, 3);
  A.FillingMatrix(1, 1);
  S21Matrix B(3, 2);
  B.FillingMatrix(1, 1);

  A.MulMatrix(B);

  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A(0, 0), 22);
  EXPECT_EQ(A(0, 1), 28);
  EXPECT_EQ(A(1, 0), 49);
  EXPECT_EQ(A(1, 1), 64);
}

TEST(MathematicalFunc, FalseMulMatrix) {
  S21Matrix A(2, 3);
  A.FillingMatrix(1, 1);
  S21Matrix B(2, 2);
  B.FillingMatrix(1, 1);

  bool error = false;

  try {
    A.MulMatrix(B);
  } catch (const std::exception& e) {
    error = true;
  }
  EXPECT_TRUE(error);
}

TEST(MathematicalFunc, Transpose) {
  S21Matrix A;
  A.FillingMatrix(1, 1);
  S21Matrix B = A.Transpose();

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), B(j, i));
    }
  }
}

TEST(MathematicalFunc, Determinant) {
  S21Matrix A;
  A.FillingMatrix(1, 1);

  double num = A.Determinant();
  EXPECT_EQ(num, 0.0);
}

TEST(MathematicalFunc, Determinant_1_on_1) {
  S21Matrix A(1, 1);
  A.FillingMatrix(1, 0);

  double num = A.Determinant();
  EXPECT_EQ(num, 1);
}

TEST(MathematicalFunc, FalseDeterminant) {
  S21Matrix A(2, 3);
  A.FillingMatrix(1, 1);

  bool error = false;

  try {
    A.Determinant();
  } catch (const std::exception& e) {
    error = true;
  }
  EXPECT_TRUE(error);
}

TEST(MathematicalFunc, CalcComplements) {
  S21Matrix A;
  A.FillingMatrix(1, 1);
  S21Matrix B = A.CalcComplements();

  EXPECT_EQ(B(0, 0), -3);
  EXPECT_EQ(B(0, 1), 6);
  EXPECT_EQ(B(0, 2), -3);
  EXPECT_EQ(B(1, 0), 6);
  EXPECT_EQ(B(1, 1), -12);
  EXPECT_EQ(B(1, 2), 6);
  EXPECT_EQ(B(2, 0), -3);
  EXPECT_EQ(B(2, 1), 6);
  EXPECT_EQ(B(2, 2), -3);
}

TEST(MathematicalFunc, CalcComplements_1_on_1) {
  S21Matrix A(1, 1);
  A.FillingMatrix(5, 0);
  S21Matrix B = A.CalcComplements();

  EXPECT_EQ(B(0, 0), 5);
}

TEST(MathematicalFunc, FalseCalcComplements) {
  S21Matrix A(2, 3);
  A.FillingMatrix(1, 1);

  bool error = false;

  try {
    A.CalcComplements();

  } catch (const std::exception& e) {
    error = true;
  }
  EXPECT_TRUE(error);
}

TEST(MathematicalFunc, InverseMatrix) {
  S21Matrix A;
  A.WorkpieceDeterminant();

  S21Matrix B = A.InverseMatrix();

  EXPECT_EQ(B(0, 0), 1);
  EXPECT_EQ(B(0, 1), 1);
  EXPECT_EQ(B(0, 2), 2);
  EXPECT_EQ(B(1, 0), 2);
  EXPECT_EQ(B(1, 1), 4);
  EXPECT_EQ(B(1, 2), 2);
  EXPECT_EQ(B(2, 0), 2);
  EXPECT_EQ(B(2, 1), 1);
  EXPECT_EQ(B(2, 2), 1);
}

TEST(MathematicalFunc, InverseDeterminantIsZero) {
  S21Matrix A;
  A.FillingMatrix(1, 1);

  bool error = false;

  try {
    A.InverseMatrix();
  } catch (const std::exception& e) {
    error = true;
  }
  EXPECT_TRUE(error);
}

TEST(MathematicalFunc, FalseInverseMatrix) {
  S21Matrix A(3, 4);
  A.FillingMatrix(1, 1);

  bool error = false;

  try {
    A.InverseMatrix();
  } catch (const std::exception& e) {
    error = true;
  }
  EXPECT_TRUE(error);
}
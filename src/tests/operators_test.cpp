#include "main_test.h"

TEST(Operator, OperatorPlus) {
  S21Matrix A;
  A.FillingMatrix(-1, 0);
  S21Matrix B;
  B.FillingMatrix(15, 0);

  S21Matrix answer = A + B;

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(answer(i, j), 14);
    }
  }
}

TEST(Operator, OperatorMinus) {
  S21Matrix A;
  A.FillingMatrix(15, 0);
  S21Matrix B;
  B.FillingMatrix(10, 0);

  S21Matrix answer = A - B;

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(answer(i, j), 5);
    }
  }
}

TEST(Operator, OperatorMulMatrix) {
  S21Matrix A(2, 3);
  A.FillingMatrix(1, 1);
  S21Matrix B(3, 2);
  B.FillingMatrix(1, 1);

  S21Matrix answer = A * B;

  EXPECT_EQ(answer.GetRows(), 2);
  EXPECT_EQ(answer.GetCols(), 2);
  EXPECT_EQ(answer(0, 0), 22);
  EXPECT_EQ(answer(0, 1), 28);
  EXPECT_EQ(answer(1, 0), 49);
  EXPECT_EQ(answer(1, 1), 64);
}

TEST(Operator, OperatorMulNumber) {
  S21Matrix A;
  A.FillingMatrix(1, 1);

  S21Matrix answer = A * 2;

  int num = 2;
  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(answer(i, j), num);
      num += 2;
    }
  }
}

TEST(Operator, OperatorTrueEq) {
  S21Matrix A;
  A.FillingMatrix(1, 2);
  S21Matrix B(A);

  bool error = false;

  if (!(A == B)) {
    error = true;
  }

  EXPECT_FALSE(error);
}

TEST(Operator, OperatorAssign) {
  S21Matrix A;
  A.FillingMatrix(1, 2);
  S21Matrix B(1, 1);

  B = A;

  EXPECT_TRUE(A == B);
}

TEST(Operator, OperatorPlusAssign) {
  S21Matrix A;
  A.FillingMatrix(-1, 0);
  S21Matrix B;
  B.FillingMatrix(15, 0);

  A += B;

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), 14);
    }
  }
}

TEST(Operator, OperatorOperatorAssign) {
  S21Matrix A;
  A.FillingMatrix(15, 0);
  S21Matrix B;
  B.FillingMatrix(10, 0);

  A -= B;

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), 5);
    }
  }
}

TEST(Operator, OperatorMulMatrixAssign) {
  S21Matrix A(2, 3);
  A.FillingMatrix(1, 1);
  S21Matrix B(3, 2);
  B.FillingMatrix(1, 1);

  A *= B;

  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_EQ(A.GetCols(), 2);
  EXPECT_EQ(A(0, 0), 22);
  EXPECT_EQ(A(0, 1), 28);
  EXPECT_EQ(A(1, 0), 49);
  EXPECT_EQ(A(1, 1), 64);
}

TEST(Operator, OperatorMulNumberAssign) {
  S21Matrix A;
  A.FillingMatrix(1, 1);

  A *= 2;

  int num = 2;
  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), num);
      num += 2;
    }
  }
}

TEST(Operator, OperatorIAndJ) {
  S21Matrix A;
  A.FillingMatrix(1, 1);

  for (int i = 0, num = 1; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), num++);
    }
  }
}

TEST(Operator, Operator_i_And_j_FalseRows) {
  S21Matrix A;
  A.FillingMatrix(1, 1);

  bool error = false;

  try {
    A(4, 0);
  } catch (const std::exception& e) {
    error = true;
  }
  EXPECT_TRUE(error);
}

TEST(Operator, Operator_i_And_j_FalseColumns) {
  S21Matrix A;
  A.FillingMatrix(1, 1);

  bool error = false;

  try {
    A(0, 4);
  } catch (const std::exception& e) {
    error = true;
  }
  EXPECT_TRUE(error);
}
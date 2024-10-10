#include "main_test.h"

TEST(Constructors, DefaultConstructor) {
  S21Matrix A;

  EXPECT_EQ(A.GetRows(), 3);
  EXPECT_EQ(A.GetCols(), 3);

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), 0);
    }
  }
}

TEST(Constructors, ConstructorWithParameters) {
  S21Matrix A(2, 5);

  EXPECT_EQ(A.GetRows(), 2);
  EXPECT_EQ(A.GetCols(), 5);

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      EXPECT_EQ(A(i, j), 0);
    }
  }
}

TEST(Constructors, NegativeMatrixHeightWidth) {
  bool error = false;

  try {
    S21Matrix A(-2, -5);

  } catch (const std::exception& e) {
    error = true;
  }

  EXPECT_TRUE(error);
}

TEST(Constructors, CopyConstructor) {
  S21Matrix A(3, 3);
  A.FillingMatrix(1, 1);

  S21Matrix B(A);

  EXPECT_TRUE(A.EqMatrix(B));
}

TEST(Constructors, MoveConstructor) {
  S21Matrix A(3, 3);
  A.FillingMatrix(1, 1);

  S21Matrix copy_A(A);

  S21Matrix B(std::move(A));

  EXPECT_TRUE(B.EqMatrix(copy_A));
  EXPECT_EQ(A.GetRows(), 0);
  EXPECT_EQ(A.GetCols(), 0);
}
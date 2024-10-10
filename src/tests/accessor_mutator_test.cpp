#include "main_test.h"

TEST(AccessorMutator, SetRows) {
  S21Matrix A;
  A.FillingMatrix(1, 1);
  A.SetRows(5);

  EXPECT_EQ(A.GetRows(), 5);
  EXPECT_EQ(A.GetCols(), 3);

  int num = 1;

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      if (i < 3 && j < 3) {
        EXPECT_EQ(A(i, j), num++);

      } else {
        EXPECT_EQ(A(i, j), 0);
      }
    }
  }
}

TEST(AccessorMutator, IncorrectRows) {
  S21Matrix A;
  bool error = false;

  try {
    A.SetRows(-5);
  } catch (const std::exception& e) {
    error = true;
  }

  EXPECT_TRUE(error);
}

TEST(AccessorMutator, SetCols) {
  S21Matrix A;
  A.FillingMatrix(1, 1);
  A.SetCols(5);

  EXPECT_EQ(A.GetRows(), 3);
  EXPECT_EQ(A.GetCols(), 5);

  int num = 1;

  for (int i = 0; i < A.GetRows(); i++) {
    for (int j = 0; j < A.GetCols(); j++) {
      if (i < 3 && j < 3) {
        EXPECT_EQ(A(i, j), num++);

      } else {
        EXPECT_EQ(A(i, j), 0);
      }
    }
  }
}

TEST(AccessorMutator, IncorrectCols) {
  S21Matrix A;
  bool error = false;

  try {
    A.SetCols(0);
  } catch (const std::exception& e) {
    error = true;
  }

  EXPECT_TRUE(error);
}
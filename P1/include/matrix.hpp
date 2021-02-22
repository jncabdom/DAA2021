#pragma once

#include <vector>
#include <iostream>

class Matrix {
 protected:
   std::vector<std::vector<int>> data;
 public:
  Matrix() {}
  Matrix(std::vector<std::vector<int>>);
  ~Matrix() {}
  void randomFill(int, int);
  void copy(const Matrix&);

  virtual Matrix* product (Matrix* another) = 0;
  inline std::vector<std::vector<int>> getMatrix() { return data; }

  std::ostream& print(std::ostream&) const;
  friend std::ostream& operator <<(std::ostream& os, const Matrix& mat) { mat.print(os); return os; };
};
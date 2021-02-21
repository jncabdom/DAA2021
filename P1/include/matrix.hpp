#pragma once

#include <vector>
#include <iostream>

class Matrix {
 protected:
   std::vector<std::vector<int>> data;
 public:
  Matrix() {}
  ~Matrix() {}
  void randomFill(int, int);
  void copy(const Matrix&);

  virtual Matrix* product (Matrix* matrix2) = 0;

  std::ostream& print(std::ostream&) const;
  friend std::ostream& operator <<(std::ostream& os, const Matrix& mat) { mat.print(os); return os; };
};
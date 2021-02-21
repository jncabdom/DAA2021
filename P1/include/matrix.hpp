#pragma once

#include <vector>

class Matrix {
 protected:
   std::vector<std::vector<int>> data;
 public:
  Matrix() {}
  ~Matrix() {}
  void randomFill(int, int);
};
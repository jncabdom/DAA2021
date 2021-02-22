#pragma once

#include "matrix.hpp"

class RowMatrix : public Matrix {
 private:
 public:
  RowMatrix() {}
  RowMatrix(std::vector<std::vector<int>> newData) : Matrix(newData) {}
  ~RowMatrix() {}
  Matrix* product (Matrix* another);
};
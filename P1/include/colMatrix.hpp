#pragma once

#include "matrix.hpp"

class ColMatrix : public Matrix {
 private:
 public:
  ColMatrix() {}
  ColMatrix(std::vector<std::vector<int>> newData) : Matrix(newData) {}
  ~ColMatrix() {}
  Matrix* product (Matrix* another);
};
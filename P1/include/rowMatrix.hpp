#pragma once

#include "matrix.hpp"

class RowMatrix : public Matrix {
 private:
 public:
  RowMatrix() {}
  ~RowMatrix() {}
  Matrix* product (Matrix* matrix2){};
};
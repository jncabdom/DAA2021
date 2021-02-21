#pragma once

#include "matrix.hpp"

class ColMatrix : public Matrix {
 private:
 public:
  ColMatrix() {}
  ~ColMatrix() {}
  Matrix* product (Matrix* matrix2){};
};
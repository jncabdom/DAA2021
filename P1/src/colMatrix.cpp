#include "../include/colMatrix.hpp"

Matrix* ColMatrix::product(Matrix* matrix2) {
  std::vector<std::vector<int>> matrix;
  std::vector<int> row;
  int total = 0;
  for (int j = 0; j < matrix2->getMatrix()[0].size(); j++) {
    for (int i = 0; i < getMatrix().size(); i++) {
      for (int k = 0; k < matrix2->getMatrix().size(); k++) {
        total += getMatrix()[j][k] * matrix2->getMatrix()[k][i];
      }
      row.push_back(total);
      total = 0;
    }
    matrix.push_back(row);
    row.clear();
  }
  return new ColMatrix(matrix);
}
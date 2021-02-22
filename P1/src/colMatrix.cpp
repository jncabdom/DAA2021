#include "../include/colMatrix.hpp"

Matrix* ColMatrix::product (Matrix* matrix2) {
  std::vector<std::vector<int>> matrix;
  matrix.resize(getMatrix().size());
  std::vector<int> col;
  int total = 0;
  for (int j = 0; j < getMatrix().size(); j++) {
    for (int i = 0; i < matrix2->getMatrix()[j].size(); i++) {
      for (int k = 0; k < matrix2->getMatrix().size(); k++) {
        total += getMatrix()[i][j] * matrix2->getMatrix()[j][i];
      }
      col.push_back(total);
      total = 0;
    }
    for (int it = 0; it < col.size(); it++)
      matrix[it].push_back(col[it]);
    col.clear();
  }
  return new ColMatrix(matrix);
}
#include "../include/rowMatrix.hpp"

Matrix* RowMatrix::product(Matrix* matrix2) {
  std::vector<std::vector<int>> matrix;
  std::vector<int> row;
  int total = 0;
  for (int i = 0; i < getMatrix().size(); i++) {
    for (int j = 0; j < matrix2->getMatrix()[i].size(); j++) {
      for (int k = 0; k < matrix2->getMatrix().size(); k++) {
        total += getMatrix()[i][j] * matrix2->getMatrix()[j][i];
      }
      row.push_back(total);
      total = 0;
    }
    matrix.push_back(row);
    row.clear();
  }
  return new RowMatrix(matrix);
}
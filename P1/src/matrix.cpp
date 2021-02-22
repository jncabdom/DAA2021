#include "../include/matrix.hpp"

Matrix::Matrix(std::vector<std::vector<int>> newData) : data(newData) {}

void Matrix::randomFill(int sizeN, int sizeM) {
  data.clear();
  std::vector<int> auxData;
  for(int i = 0; i < sizeN; i++) {
    for(int j = 0; j < sizeM; j++) {
      auxData.push_back(rand() % 99);
    }
    data.push_back(auxData);
    auxData.clear();
  }
}

void Matrix::copy(const Matrix& other) {
  data.clear();
  std::vector<int> auxData;
  for(auto i: other.data) {
    for(auto j: i) {
      auxData.push_back(j);
    }
    data.push_back(auxData);
    auxData.clear();
  }
}

std::ostream& Matrix::print(std::ostream& output) const {
  for(auto i: data) {
    for(auto j: i) {
      output << j << " ";
    }
    output << "\n";
  }
  return output;
}
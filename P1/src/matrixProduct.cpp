#include <chrono>
#include <iostream>

#include "../include/colMatrix.hpp"
#include "../include/matrix.hpp"
#include "../include/rowMatrix.hpp"

typedef std::chrono::milliseconds s;

RowMatrix* baseMat1 = new RowMatrix();
RowMatrix* baseMat2 = new RowMatrix();

RowMatrix* aRow = new RowMatrix();
RowMatrix* bRow = new RowMatrix();
ColMatrix* aCol = new ColMatrix();
ColMatrix* bCol = new ColMatrix();

int main(int argc, char* argv[]) {
  int minSize = atoi(argv[1]);
  int maxSize = atoi(argv[2]);
  int increment = atoi(argv[3]);

  for (int i = minSize; i <= maxSize; i += increment) {
    std::cout << "Tamaño de las matrices: " << i << ".\n\n";
    // Create both base matrixes, fill them and create row and col ones as
    // copies.
    baseMat1 = new RowMatrix();
    baseMat2 = new RowMatrix();

    baseMat1->randomFill(i, i);
    baseMat2->randomFill(i, i);

    aRow->copy(*baseMat1);
    bRow->copy(*baseMat2);
    aCol->copy(*baseMat1);
    bCol->copy(*baseMat1);

    // Row Product
    auto before = std::chrono::high_resolution_clock::now();
    Matrix* rowResult = aRow->product(bRow);
    auto after = std::chrono::high_resolution_clock::now();
    auto durationRow = std::chrono::duration_cast<s>(after - before).count();

    // Column Product
    before = std::chrono::high_resolution_clock::now();
    Matrix* ColResult = aCol->product(bCol);
    after = std::chrono::high_resolution_clock::now();
    auto durationCol = std::chrono::duration_cast<s>(after - before).count();

    std::cout << "Duración del producto por columnas: " << durationRow
              << " milisegundos" << std::endl;
    std::cout << "Duración del producto por filas: " << durationRow
              << " milisegundos" << std::endl;

    std::cout << "\n\n";
  }
}
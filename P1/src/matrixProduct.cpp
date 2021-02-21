#include <chrono>
#include <iostream>

#include "../include/colMatrix.hpp"
#include "../include/rowMatrix.hpp"

int main(int argc, char* argv[]) {
  int minSize   = atoi(argv[1]);
  int maxSize   = atoi(argv[2]);
  int increment = atoi(argv[3]);

  for (int i = minSize; i <= maxSize; i += increment) {
    std::cout << "Matrix Size: " << i << ".\n";
    // Create both matrix, then fill them
    auto before = std::chrono::high_resolution_clock::now();
    // Execute row product
    auto after = std::chrono::high_resolution_clock::now();
    auto durationRow = after - before;

    before = std::chrono::high_resolution_clock::now();
    // Execute column product
    after = std::chrono::high_resolution_clock::now();
    auto durationCol = after - before;

    std::cout << "Duración del producto por columnas: " << durationRow.count()
              << std::endl;
    std::cout << "Duración del producto por filas: " << durationRow.count()
              << std::endl;
  }
}
/* Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado
 * en Ingeniería Informática. Asignatura: Diseño y Análisis de Algoritmos (DAA)
 *  Curso: 4º
 *  Práctica 1 DAA:
 *  Autor: José Nicolás Cabrera Domínguez
 *  Correo: nicolas.cabrera.14@ull.edu.es
 *  Fecha: 21/02/2021
 *  Archivo: matrixProduct.cpp
 *
 *  Referencias:
 *   Enunciado de la práctica:
 * https://campusingenieriaytecnologia.ull.es/mod/assign/view.php?id=285311
 */

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
  if (argc != 4) {
    std::cout << "Error de ejecución. Por favor utilice la siguiente forma:"
              << std::endl
              << "./matrixProduct X Y Z " << std::endl
              << "X es el tamaño mínimo,"
              << "Y el máximo y Z el incremento en el tamaño." << std::endl;
    return 0;
  }

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
    bCol->copy(*baseMat2);

    // Uncomment for printing both base matrixes
    // std::cout << "Matriz base 1: " << std::endl;
    // baseMat1 -> print(std::cout);
    // std::cout << "Matriz base 2: " << std::endl;
    // baseMat2 -> print(std::cout);

    // Row Product
    auto before = std::chrono::high_resolution_clock::now();
    Matrix* rowResult = aRow->product(bRow);
    auto after = std::chrono::high_resolution_clock::now();
    auto durationRow = std::chrono::duration_cast<s>(after - before).count();

    // Uncomment for printing the resulting matrix from Row Multiplication
    // std::cout << "Resultado row: " << std::endl;
    // rowResult -> print(std::cout);

    // Column Product
    before = std::chrono::high_resolution_clock::now();
    Matrix* colResult = aCol->product(bCol);
    after = std::chrono::high_resolution_clock::now();
    auto durationCol = std::chrono::duration_cast<s>(after - before).count();

    // Uncomment for printing the resulting matrix from Col Multiplication
    // std::cout << "Resultado col: " << std::endl;
    // colResult -> print(std::cout);

    std::cout << "Duración del producto por columnas: " << durationCol
              << " milisegundos" << std::endl;
    std::cout << "Duración del producto por filas: " << durationRow
              << " milisegundos" << std::endl;

    std::cout << "\n\n";
  }
}
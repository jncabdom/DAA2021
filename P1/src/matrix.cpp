/* Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado
 * en Ingeniería Informática. Asignatura: Diseño y Análisis de Algoritmos (DAA)
 *  Curso: 4º
 *  Práctica 1 DAA:
 *  Autor: José Nicolás Cabrera Domínguez
 *  Correo: nicolas.cabrera.14@ull.edu.es
 *  Fecha: 21/02/2021
 *  Archivo: matrix.cpp
 *
 *  Referencias:
 *   Enunciado de la práctica:
 * https://campusingenieriaytecnologia.ull.es/mod/assign/view.php?id=285311
 */

#include "../include/matrix.hpp"

Matrix::Matrix(std::vector<std::vector<int>> newData) : data(newData) {}

// Fills the matrix with sizeN rows and sizeM columns filled with random values
void Matrix::randomFill(int sizeN, int sizeM) {
  data.clear();
  std::vector<int> auxData;
  for (int i = 0; i < sizeN; i++) {
    for (int j = 0; j < sizeM; j++) {
      auxData.push_back(rand() % 99);
    }
    data.push_back(auxData);
    auxData.clear();
  }
}

// Fills the matrix with the content of *other*
void Matrix::copy(const Matrix& other) {
  data.clear();
  std::vector<int> auxData;
  for (auto i : other.data) {
    for (auto j : i) {
      auxData.push_back(j);
    }
    data.push_back(auxData);
    auxData.clear();
  }
}

// Prints the matrix's content into the *output* stream
std::ostream& Matrix::print(std::ostream& output) const {
  for (auto i : data) {
    for (auto j : i) {
      output << j << " ";
    }
    output << "\n";
  }
  return output;
}
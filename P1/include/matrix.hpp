/* Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado
 * en Ingeniería Informática. Asignatura: Diseño y Análisis de Algoritmos (DAA)
 *  Curso: 4º
 *  Práctica 1 DAA:
 *  Autor: José Nicolás Cabrera Domínguez
 *  Correo: nicolas.cabrera.14@ull.edu.es
 *  Fecha: 21/02/2021
 *  Archivo: matrix.hpp
 *
 *  Referencias:
 *   Enunciado de la práctica:
 * https://campusingenieriaytecnologia.ull.es/mod/assign/view.php?id=285311
 */

#pragma once

#include <iostream>
#include <vector>

class Matrix {
 protected:
  std::vector<std::vector<int>> data;

 public:
  Matrix() {}
  Matrix(std::vector<std::vector<int>>);
  ~Matrix() {}

  void copy(const Matrix&);
  void randomFill(int, int);
  virtual Matrix* product(Matrix* another) = 0;
  inline std::vector<std::vector<int>> getMatrix() { return data; }

  std::ostream& print(std::ostream&) const;
  friend std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
    mat.print(os);
    return os;
  }
};
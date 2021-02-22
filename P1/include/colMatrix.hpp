/* Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado en Ingeniería Informática.
*  Asignatura: Diseño y Análisis de Algoritmos (DAA)
*  Curso: 4º
*  Práctica 1 DAA: 
*  Autor: José Nicolás Cabrera Domínguez
*  Correo: nicolas.cabrera.14@ull.edu.es
*  Fecha: 21/02/2021
*  Archivo: colMatrix.hpp
*  
*  Referencias: 
*   Enunciado de la práctica: https://campusingenieriaytecnologia.ull.es/mod/assign/view.php?id=285311
*/

#pragma once

#include "matrix.hpp"

class ColMatrix : public Matrix {
 private:
 public:
  ColMatrix() {}
  ColMatrix(std::vector<std::vector<int>> newData) : Matrix(newData) {}
  ~ColMatrix() {}
  Matrix* product (Matrix* another);
};
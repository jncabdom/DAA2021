/* Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado
 * en Ingeniería Informática. Asignatura: Diseño y Análisis de Algoritmos (DAA)
 *  Curso: 4º
 *  Práctica 1 DAA:
 *  Autor: José Nicolás Cabrera Domínguez
 *  Correo: nicolas.cabrera.14@ull.edu.es
 *  Fecha: 21/02/2021
 *  Archivo: colMatrix.cpp
 *
 *  Referencias:
 *   Enunciado de la práctica:
 *   https://campusingenieriaytecnologia.ull.es/mod/assign/view.php?id=285311
 */

#include "../include/colMatrix.hpp"

// Returns the resulting matrix from the product
// of two others. The final matrix is travelled through by columns.
Matrix* ColMatrix::product(Matrix* matrix2) {
  std::vector<std::vector<int>> matrix;
  std::vector<int> row;
  std::vector<std::vector<int>> auxMat1 = getMatrix();
  std::vector<std::vector<int>> auxMat2 = matrix2->getMatrix();
  int total = 0;
  for (int j = 0; j < auxMat2[0].size(); j++) {
    for (int i = 0; i < auxMat1.size(); i++) {
      for (int k = 0; k < auxMat2.size(); k++) {
        total += auxMat1[j][k] * auxMat2[k][i];
      }
      row.push_back(total);
      total = 0;
    }
    matrix.push_back(row);
    row.clear();
  }
  return new ColMatrix(matrix);
}
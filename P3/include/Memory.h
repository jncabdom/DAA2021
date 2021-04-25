/*
 * Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado
 * en Ingeniería Informática. Asignatura: Diseño y Análisis de Algoritmos (DAA)
 * Curso: 4º
 * Práctica 2 DAA: Simulador de la Máquina RAM
 * Autor: José Nicolás Cabrera Domínguez
 * Correo: nicolas.cabrera.14@ull.edu.es
 * Fecha: 27/02/2021
 * Archivo: Memory.h
 * Referencias:
 *   Enunciado de la práctica:
 * https://campusingenieriaytecnologia.ull.es/pluginfile.php/356512/mod_assign/introattachment/0/enunciadopracticaRAM.pdf?forcedownload=1
 */

#pragma once

#include <vector>
#include <iostream>

class Memory {
 private:
  std::vector<int> registerArray = {0};

 public:
  Memory() {}
  ~Memory() {}

  inline int getVal(int n) { return registerArray[n]; }
  inline void setVal(int n) { registerArray[0] = n; }
  void storeVal(int n, int pos);
  friend std::ostream& operator<<(std::ostream& os, Memory& mem) {
    for (int i = 0; i < mem.registerArray.size(); i++) {
      os << "r[" << i << "]: " << mem.registerArray[i] << std::endl;
    }
    return os;
  }
};
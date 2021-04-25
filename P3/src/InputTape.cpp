/*
 * Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado
 * en Ingeniería Informática. Asignatura: Diseño y Análisis de Algoritmos (DAA)
 * Curso: 4º
 * Práctica 2 DAA: Simulador de la Máquina RAM
 * Autor: José Nicolás Cabrera Domínguez
 * Correo: nicolas.cabrera.14@ull.edu.es
 * Fecha: 27/02/2021
 * Archivo: InputTape.cpp
 * Referencias:
 *   Enunciado de la práctica:
 * https://campusingenieriaytecnologia.ull.es/pluginfile.php/356512/mod_assign/introattachment/0/enunciadopracticaRAM.pdf?forcedownload=1
 */

#include "../include/InputTape.h"

InputTape::InputTape(std::ifstream& input) {
  int aux;
  while (input >> aux) {
    tapeData.push_back(aux);
  }
}

int InputTape::read() {
  currentPos++;
  return tapeData[currentPos - 1];
}
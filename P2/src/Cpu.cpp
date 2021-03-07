/* 
* Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado en Ingeniería Informática.
* Asignatura: Diseño y Análisis de Algoritmos (DAA)
* Curso: 4º
* Práctica 2 DAA: Simulador de la Máquina RAM
* Autor: José Nicolás Cabrera Domínguez
* Correo: nicolas.cabrera.14@ull.edu.es
* Fecha: 27/02/2021
* Archivo: Cpu.cpp
* Referencias: 
*   Enunciado de la práctica: https://campusingenieriaytecnologia.ull.es/pluginfile.php/356512/mod_assign/introattachment/0/enunciadopracticaRAM.pdf?forcedownload=1
*/

#include "../include/Cpu.h"

Cpu::Cpu(Program newProgram, std::ifstream& input, std::string output) {
  inputTape = InputTape(input);
  outputTape = OutputTape();
  outputStream = output;
  program = newProgram;
}

std::ostream& Cpu::printInputTape(std::ostream& os) {
  inputTape.print(os);
  return os;
}

std::ostream& Cpu::printOutputTape(std::ostream& os) {
  outputTape.print(os);
  return os;
}

std::ostream& Cpu::printRegisters(std::ostream& os) {
  os << memory;
  return os;
}
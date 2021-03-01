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

Cpu::Cpu(Program newProgram, std::ifstream& input, std::string output,
         bool debug) {
  inputTape = InputTape(input);
  outputTape = OutputTape();
  outputStream = output;
  program = newProgram;

  // Provisional: solo para el funcionamiento de la primera entrega:
  std::cout << "Programa leído:" << std::endl << std::endl;
  program.print(std::cout);
  std::cout << std::endl << "Cinta de entrada:" << std::endl << std::endl;
  inputTape.print(std::cout);
  std::cout << std::endl;
}
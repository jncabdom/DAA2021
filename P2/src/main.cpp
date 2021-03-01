/* 
* Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado en Ingeniería Informática.
* Asignatura: Diseño y Análisis de Algoritmos (DAA)
* Curso: 4º
* Práctica 2 DAA: Simulador de la Máquina RAM
* Autor: José Nicolás Cabrera Domínguez
* Correo: nicolas.cabrera.14@ull.edu.es
* Fecha: 27/02/2021
* Archivo: main.cpp
* Referencias: 
*   Enunciado de la práctica: https://campusingenieriaytecnologia.ull.es/pluginfile.php/356512/mod_assign/introattachment/0/enunciadopracticaRAM.pdf?forcedownload=1
*/

#include <iostream>

#include "../include/Cpu.h"
#include "../include/ProgramParser.h"

std::ifstream inputTape;
std::ifstream program;

const char COMMENT_SIGN = '#';

bool debugFlag;

int main(int argc, char* argv[]) {
  if (argc < 5) {
    std::cout << "Error en la ejecución." << std::endl;
    return 1;
  }

  program.open(argv[1]);
  inputTape.open(argv[2]);

  debugFlag = (argv[4] == "1") ? 1 : 0;

  if ((!program.is_open()) || (!inputTape.is_open())) {
    std::cout << "Error en la lectura de archivos de entrada." << std::endl;
    return 1;
  }

  ProgramParser parser(program, COMMENT_SIGN);

  Cpu cpu(parser.getParsedProgram(), inputTape, argv[3], debugFlag);
}
/*
 * Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado
 * en Ingeniería Informática. Asignatura: Diseño y Análisis de Algoritmos (DAA)
 * Curso: 4º
 * Práctica 2 DAA: Simulador de la Máquina RAM
 * Autor: José Nicolás Cabrera Domínguez
 * Correo: nicolas.cabrera.14@ull.edu.es
 * Fecha: 27/02/2021
 * Archivo: main.cpp
 * Referencias:
 *   Enunciado de la práctica:
 * https://campusingenieriaytecnologia.ull.es/pluginfile.php/356512/mod_assign/introattachment/0/enunciadopracticaRAM.pdf?forcedownload=1
 */

#include <iostream>

#include "../include/Cpu.h"
#include "../include/ProgramParser.h"

std::ifstream inputTape;
std::ifstream program;

const char COMMENT_SIGN = '#';

bool debugFlag;
char opt;

int main(int argc, char* argv[]) {
  if (argc < 5) {
    std::cout << "Error en la ejecución." << std::endl;
    return 1;
  }

  program.open(argv[1]);
  inputTape.open(argv[2]);

  debugFlag = (atoi(argv[4]) == 1) ? 1 : 0;

  if ((!program.is_open()) || (!inputTape.is_open())) {
    std::cout << "Error en la lectura de archivos de entrada." << std::endl;
    return 1;
  }

  ProgramParser parser(program, COMMENT_SIGN);
  Cpu cpu(parser.getParsedProgram(), inputTape, argv[3]);

  if (debugFlag == 1) {
    while ((opt != 'x') && (cpu.HALT == false)) {
      std::cout << "r: ver los registros" << std::endl
                << "t: traza" << std::endl
                << "e: ejecutar" << std::endl
                << "s: desensamblador" << std::endl
                << "i: ver cinta entrada" << std::endl
                << "o: ver cinta salida" << std::endl
                << "h: ayuda" << std::endl
                << "x: exit" << std::endl
                << ">";
      std::cin >> opt;
      switch (opt) {
        case 'r':
          std::cout << std::endl << "Contenido de los registros: " << std::endl;
          cpu.printRegisters(std::cout);
          std::cout << std::endl;
          break;
        case 't':
          std::cout << std::endl;
          cpu.showNextInstr(std::cout, 0);
          cpu.step();
          std::cout << std::endl << std::endl;
          break;
        case 'e':
          while (!cpu.HALT) {
            cpu.step();
          }
          break;
        case 's':
          std::cout << std::endl;
          cpu.showNextInstr(std::cout, 1);
          std::cout << std::endl << std::endl;
          break;
        case 'i':
          std::cout << std::endl << "Contenido de la cinta de entrada: ";
          cpu.printInputTape(std::cout);
          std::cout << std::endl << std::endl;
          break;
        case 'o':
          std::cout << std::endl << "Contenido de la cinta de salida: ";
          cpu.printOutputTape(std::cout);
          std::cout << std::endl << std::endl;
          break;
        case 'h':
          std::cout << std::endl <<
          "r: imprime el contenido de los registros de la memoria.\n" <<
          "t: imprime y ejecuta la siguiente instrucción.\n" <<
          "e: ejecuta el resto del programa.\n" <<
          "s: imprime de forma detallada la siguiente instrucción.\n" <<
          "i: imprime el contenido de la cinta de entrada.\n" <<
          "o: imprime el contenido de la cinta de salida.\n" <<
          "h: ayuda.\n" <<
          "x: salir del programa.\n\n" ;
          break;
        case 'x':
          cpu.printToOutputTape();
          cpu.HALT = true;
          return 0;
          break;
        default:
          break;
      }
    }
  } else {
    while (!cpu.HALT) {
      cpu.step();
    }
  }
}
/* 
* Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado en Ingeniería Informática.
* Asignatura: Diseño y Análisis de Algoritmos (DAA)
* Curso: 4º
* Práctica 2 DAA: Simulador de la Máquina RAM
* Autor: José Nicolás Cabrera Domínguez
* Correo: nicolas.cabrera.14@ull.edu.es
* Fecha: 27/02/2021
* Archivo: Program.cpp
* Referencias: 
*   Enunciado de la práctica: https://campusingenieriaytecnologia.ull.es/pluginfile.php/356512/mod_assign/introattachment/0/enunciadopracticaRAM.pdf?forcedownload=1
*/

#include "../include/Program.h"

Program::Program(std::vector<Instruction> instructions,
                 std::vector<std::pair<std::string, int>> newSubRoutines) {
  program = instructions;
  subRoutines = newSubRoutines;
}

std::ostream& Program::print(std::ostream& os) {
  for(int i = 0; i < program.size(); i++) {
    for(auto aux: subRoutines) {
      if(aux.second == i) {
        os << aux.first << ": ";
      }
    }
    os << program[i] << std::endl;
  }
  return os;
}

/* 
* Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado en Ingeniería Informática.
* Asignatura: Diseño y Análisis de Algoritmos (DAA)
* Curso: 4º
* Práctica 2 DAA: Simulador de la Máquina RAM
* Autor: José Nicolás Cabrera Domínguez
* Correo: nicolas.cabrera.14@ull.edu.es
* Fecha: 27/02/2021
* Archivo: ProgramParser.cpp
* Referencias: 
*   Enunciado de la práctica: https://campusingenieriaytecnologia.ull.es/pluginfile.php/356512/mod_assign/introattachment/0/enunciadopracticaRAM.pdf?forcedownload=1
*/

#include "../include/ProgramParser.h"


ProgramParser::ProgramParser(std::ifstream& input, char commentSign) {
  std::string line;
  Instruction newInstruction;
  std::pair<std::string,int> subRoutine;
  while(std::getline(input, line)) {
    if((line[0] != commentSign) && (line != "")) {
      line.erase(std::remove(line.begin(), line.end(), '\t'), line.end());
      std::size_t pos = line.find(':');
      if(pos != std::string::npos) {
        std::string name = line.substr(0, pos);
        subRoutine = std::make_pair(name,parsedProgram.size());
        subRoutines.push_back(subRoutine);
        line = line.substr(pos+1, line.size() - 1);
      }
      newInstruction = Instruction(line);
      parsedProgram.push_back(newInstruction);
    }
  }
}
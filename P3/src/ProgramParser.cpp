/*
 * Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado
 * en Ingeniería Informática. Asignatura: Diseño y Análisis de Algoritmos (DAA)
 * Curso: 4º
 * Práctica 2 DAA: Simulador de la Máquina RAM
 * Autor: José Nicolás Cabrera Domínguez
 * Correo: nicolas.cabrera.14@ull.edu.es
 * Fecha: 27/02/2021
 * Archivo: ProgramParser.cpp
 * Referencias:
 *   Enunciado de la práctica:
 * https://campusingenieriaytecnologia.ull.es/pluginfile.php/356512/mod_assign/introattachment/0/enunciadopracticaRAM.pdf?forcedownload=1
 */

#include "../include/ProgramParser.h"

#include <sstream>

ProgramParser::ProgramParser(std::ifstream& input, char commentSign) {
  std::string line, aux;
  std::pair<std::string, int> tag;
  while (std::getline(input, line)) {
    if ((line[0] != commentSign) && (line != "")) {
      line.erase(std::remove(line.begin(), line.end(), '\t'), line.end());
      std::transform(line.begin(), line.end(), line.begin(), ::toupper);
      std::size_t pos = line.find(':');
      if (pos != std::string::npos) {
        std::string name = line.substr(0, pos);
        tags.insert(std::pair<std::string, int>(name, parsedProgram.size()));
        line = line.substr(pos + 1, line.size() - 1);
      }
      std::istringstream ss(line);
      ss >> aux;
      switch (opc.find(aux)->second) {
        case LOAD:
          parsedProgram.push_back(new LoadInstruction(line));
          break;
        case STORE:
          parsedProgram.push_back(new StoreInstruction(line));
          break;
        case ADD:
          parsedProgram.push_back(new AddInstruction(line));
          break;
        case SUB:
          parsedProgram.push_back(new SubInstruction(line));
          break;
        case MULT:
          parsedProgram.push_back(new MultInstruction(line));
          break;
        case DIV:
          parsedProgram.push_back(new DivInstruction(line));
          break;
        case READ:
          parsedProgram.push_back(new ReadInstruction(line));
          break;
        case WRITE:
          parsedProgram.push_back(new WriteInstruction(line));
          break;
        case JUMP:
          parsedProgram.push_back(new JumpInstruction(line));
          break;
        case JGTZ:
          parsedProgram.push_back(new JGTZInstruction(line));
          break;
        case JZERO:
          parsedProgram.push_back(new JZEROInstruction(line));
          break;
        case HALT:
          parsedProgram.push_back(new HaltInstruction(line));
          break;
      }
      aux = "";
    }
  }
}
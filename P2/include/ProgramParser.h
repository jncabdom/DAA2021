/* 
* Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado en Ingeniería Informática.
* Asignatura: Diseño y Análisis de Algoritmos (DAA)
* Curso: 4º
* Práctica 2 DAA: Simulador de la Máquina RAM
* Autor: José Nicolás Cabrera Domínguez
* Correo: nicolas.cabrera.14@ull.edu.es
* Fecha: 27/02/2021
* Archivo: ProgramParser.h
* Referencias: 
*   Enunciado de la práctica: https://campusingenieriaytecnologia.ull.es/pluginfile.php/356512/mod_assign/introattachment/0/enunciadopracticaRAM.pdf?forcedownload=1
*/

#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#include "../include/Instruction.h"
#include "../include/Program.h"

class ProgramParser
{
private:
  std::vector<Instruction> parsedProgram;
  std::vector<std::pair<std::string,int>> subRoutines;
public:
  ProgramParser() {}
  ProgramParser(std::ifstream&, char);
  ~ProgramParser() {}

  Program getParsedProgram() { return Program(parsedProgram, subRoutines); }
};
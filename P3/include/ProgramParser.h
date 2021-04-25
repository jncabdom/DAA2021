/*
 * Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado
 * en Ingeniería Informática. Asignatura: Diseño y Análisis de Algoritmos (DAA)
 * Curso: 4º
 * Práctica 2 DAA: Simulador de la Máquina RAM
 * Autor: José Nicolás Cabrera Domínguez
 * Correo: nicolas.cabrera.14@ull.edu.es
 * Fecha: 27/02/2021
 * Archivo: ProgramParser.h
 * Referencias:
 *   Enunciado de la práctica:
 * https://campusingenieriaytecnologia.ull.es/pluginfile.php/356512/mod_assign/introattachment/0/enunciadopracticaRAM.pdf?forcedownload=1
 */

#pragma once

#include <algorithm>
#include <fstream>
#include <map>
#include <string>
#include <vector>

#include "../include/AddInstruction.h"
#include "../include/DivInstruction.h"
#include "../include/HaltInstruction.h"
#include "../include/JGTZInstruction.h"
#include "../include/JZEROInstruction.h"
#include "../include/JumpInstruction.h"
#include "../include/LoadInstruction.h"
#include "../include/MultInstruction.h"
#include "../include/Program.h"
#include "../include/ReadInstruction.h"
#include "../include/StoreInstruction.h"
#include "../include/SubInstruction.h"
#include "../include/WriteInstruction.h"

enum opcodes {
  LOAD,
  STORE,
  ADD,
  SUB,
  MULT,
  DIV,
  READ,
  WRITE,
  JUMP,
  JGTZ,
  JZERO,
  HALT
};

class ProgramParser {
 private:
  std::vector<Instruction*> parsedProgram;
  std::map<std::string, int> tags;
  std::map<std::string, opcodes> opc = {
      {"LOAD", LOAD}, {"STORE", STORE}, {"ADD", ADD},     {"SUB", SUB},
      {"MULT", MULT}, {"DIV", DIV},     {"READ", READ},   {"WRITE", WRITE},
      {"JUMP", JUMP}, {"JGTZ", JGTZ},   {"JZERO", JZERO}, {"HALT", HALT}};

 public:
  ProgramParser() {}
  ProgramParser(std::ifstream&, char);
  ~ProgramParser() {}

  Program getParsedProgram() { return Program(parsedProgram, tags); }
};
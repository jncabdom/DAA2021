/*
 * Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado
 * en Ingeniería Informática. Asignatura: Diseño y Análisis de Algoritmos (DAA)
 * Curso: 4º
 * Práctica 2 DAA: Simulador de la Máquina RAM
 * Autor: José Nicolás Cabrera Domínguez
 * Correo: nicolas.cabrera.14@ull.edu.es
 * Fecha: 27/02/2021
 * Archivo: Cpu.h
 * Referencias:
 *   Enunciado de la práctica:
 * https://campusingenieriaytecnologia.ull.es/pluginfile.php/356512/mod_assign/introattachment/0/enunciadopracticaRAM.pdf?forcedownload=1
 */

#pragma once

#include <fstream>
#include <vector>

#include "InputTape.h"
#include "Memory.h"
#include "OutputTape.h"
#include "Program.h"

class Cpu {
 private:
  int programCounter = 0;
  Program program;
  InputTape inputTape;
  OutputTape outputTape;
  std::string outputStream;
  Memory memory;
  ctx context;

 public:
  bool HALT = false;
  Cpu(Program, std::ifstream&, std::string);
  ~Cpu() {}
  std::ostream& printOutputTape(std::ostream&);
  void printToOutputTape();
  std::ostream& printInputTape(std::ostream&);
  std::ostream& printRegisters(std::ostream&);
  std::ostream& showNextInstr(std::ostream&, int);
  void step();
};
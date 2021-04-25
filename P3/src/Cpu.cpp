/*
 * Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado
 * en Ingeniería Informática. Asignatura: Diseño y Análisis de Algoritmos (DAA)
 * Curso: 4º
 * Práctica 2 DAA: Simulador de la Máquina RAM
 * Autor: José Nicolás Cabrera Domínguez
 * Correo: nicolas.cabrera.14@ull.edu.es
 * Fecha: 27/02/2021
 * Archivo: Cpu.cpp
 * Referencias:
 *   Enunciado de la práctica:
 * https://campusingenieriaytecnologia.ull.es/pluginfile.php/356512/mod_assign/introattachment/0/enunciadopracticaRAM.pdf?forcedownload=1
 */

#include "../include/Cpu.h"

Cpu::Cpu(Program newProgram, std::ifstream& input, std::string output) {
  inputTape = InputTape(input);
  outputTape = OutputTape();
  outputStream = output;
  program = newProgram;

  context.pc = &programCounter;
  context.it = &inputTape;
  context.ot = &outputTape;
  context.mem = &memory;
  context.tags = program.getTags();
}

std::ostream& Cpu::printInputTape(std::ostream& os) {
  inputTape.print(os);
  return os;
}

std::ostream& Cpu::printOutputTape(std::ostream& os) {
  outputTape.print(os);
  return os;
}

void Cpu::printToOutputTape() {
  std::ofstream of;
  of.open(outputStream);
  outputTape.print(of);
}

std::ostream& Cpu::printRegisters(std::ostream& os) {
  os << memory;
  return os;
}

void Cpu::step() {
  try {
    program.getInstr(programCounter)->execute(context);
  } catch (char x) {
    if (x == 'x') {
      printToOutputTape();
      HALT = true;
    }
  }
}

std::ostream& Cpu::showNextInstr(std::ostream& os, int opt) {
  program.getInstr(programCounter)->print(os, opt);
  return os;
}
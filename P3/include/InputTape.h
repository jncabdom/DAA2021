/* 
* Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado en Ingeniería Informática.
* Asignatura: Diseño y Análisis de Algoritmos (DAA)
* Curso: 4º
* Práctica 2 DAA: Simulador de la Máquina RAM
* Autor: José Nicolás Cabrera Domínguez
* Correo: nicolas.cabrera.14@ull.edu.es
* Fecha: 27/02/2021
* Archivo: InputTape.h
* Referencias: 
*   Enunciado de la práctica: https://campusingenieriaytecnologia.ull.es/pluginfile.php/356512/mod_assign/introattachment/0/enunciadopracticaRAM.pdf?forcedownload=1
*/

#pragma once

#include <fstream>
#include <vector>
#include <string>

#include "../include/Tape.h"

class InputTape : public Tape
{
public:
  InputTape() { Tape(); }
  InputTape(std::ifstream& input);
  ~InputTape() {}
  int read();
};
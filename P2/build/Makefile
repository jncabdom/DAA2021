# Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado en Ingeniería Informática.
# Asignatura: Diseño y Análisis de Algoritmos (DAA)
# Curso: 4º
# Práctica 2 DAA: Simulador de la Máquina RAM
# Autor: José Nicolás Cabrera Domínguez
# Correo: nicolas.cabrera.14@ull.edu.es
# Fecha: 27/02/2021
# Archivo: Makefile
#  
# Referencias: 
#   Enunciado de la práctica: https://campusingenieriaytecnologia.ull.es/pluginfile.php/356512/mod_assign/introattachment/0/enunciadopracticaRAM.pdf?forcedownload=1

CXX=g++
CXXFLAGS=-std=c++11 -g

SRC=../src
MAIN=../src/main.cpp
EXEC=RAM
INCLUDES= $(SRC)/Tape.cpp $(SRC)/InputTape.cpp $(SRC)/OutputTape.cpp $(SRC)/ProgramParser.cpp $(SRC)/Instruction.cpp $(SRC)/Program.cpp $(SRC)/Cpu.cpp

all:
	$(CXX)  $(CXXFLAGS) $(MAIN) $(INCLUDES) -o $(EXEC)

.PHONY: clean

clean:
	rm -f *.o ${EXEC}
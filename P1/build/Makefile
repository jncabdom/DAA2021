# Universidad de La Laguna. Escuela Superior de Ingeniería y Tecnología. Grado en Ingeniería Informática.
# Asignatura: Diseño y Análisis de Algoritmos (DAA)
# Curso: 4º
# Práctica 1 DAA: 
# Autor: José Nicolás Cabrera Domínguez
# Correo: nicolas.cabrera.14@ull.edu.es
# Fecha: 21/02/2021
# Archivo: Makefile
#  
# Referencias: 
#   Enunciado de la práctica: https://campusingenieriaytecnologia.ull.es/mod/assign/view.php?id=285311

CXX=g++
CXXFLAGS=-std=c++11 -g

SRC=../src
MAIN=../src/matrixProduct.cpp
EXEC=matrixProduct
INCLUDES= $(SRC)/matrix.cpp $(SRC)/colMatrix.cpp $(SRC)/rowMatrix.cpp

all:
	$(CXX)  $(CXXFLAGS) $(MAIN) $(INCLUDES) -o $(EXEC)

.PHONY: clean

clean:
	rm -f *.o ${EXEC}
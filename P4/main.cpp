
#ifndef MAIN_
#define MAIN_

#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include"framework/Framework.h"
#include"examples/FibonacciP.h"
#include"examples/FibonacciS.h" 
#include"examples/mergeSortP.h"
#include"examples/mergeSortS.h"
#include"examples/quickSortP.h"
#include"examples/quickSortS.h"
using namespace std;

vector<int> toOrder;

Problema* problema;
Solucion* solucion;

int main(int argc, char* argv[]){
	if (argc < 4) {
		cout << "\nNúmero de parametros incorrecto. Encontrado " << argc-1 << " requeridos 4 o más."<< endl;
		cout << "\nUso: ./sort [merge | quick] Y Z..." << endl;
		exit(-1);
	}

	int opt = atoi(argv[1]);
	for (int i = 2; i < argc; i++) {
		toOrder.push_back(atoi(argv[i]));
	}

	if(string(argv[1]) == "quick") {
		problema = new quickSortP(toOrder);
		solucion = new quickSortS();
	}
	else if(string(argv[1]) == "merge") {
		problema = new mergeSortP(toOrder);
		solucion = new mergeSortS();
	}
	else { 
		cout << "Opción inválida. Por favor, inténtelo de nuevo.";
		cout << "\nUso: ./sort [merge | quick] Y Z..." << endl;
		exit(-1);
	}
	Framework* framework = new Framework();

	framework->divideyVenceras(problema, solucion);
	cout << "Resultado:" << endl;
	solucion->resolver();

};

#endif /* MAIN_ */
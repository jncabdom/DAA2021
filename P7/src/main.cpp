#include <chrono>
#include <iostream>

#include "../include/machines.h"

int option = 1;
int lrcNumber = 3;
int operation = 1, search = 1, stop = 1, iterations = 100;
machines machinesTest;

auto start = std::chrono::steady_clock::now();
auto end = std::chrono::steady_clock::now();

void menu() {
  while (option != 0) {
    std::cout << "1. Algoritmo Voraz 1" << std::endl
              << "2. Algoritmo Voraz 2" << std::endl
              << "3. Resolución por GRASP" << std::endl
              << "0. Salir del programa" << std::endl
              << "Elija una opción: ";
    std::cin >> option;
    switch (option) {
      case 0:
        break;
      case 1:
        start = std::chrono::steady_clock::now();
        machinesTest.greedy1();
        end = std::chrono::steady_clock::now();
        machinesTest.showResults(std::cout);
        std::cout << "Elapsed time: "
                  << std::chrono::duration_cast<std::chrono::microseconds>(
                         end - start)
                         .count()
                  << "μs\n\n";
        break;
      case 2:
        start = std::chrono::steady_clock::now();
        machinesTest.greedy2();
        end = std::chrono::steady_clock::now();
        machinesTest.showResults(std::cout);
        std::cout << "Elapsed time: "
                  << std::chrono::duration_cast<std::chrono::microseconds>(
                         end - start)
                         .count()
                  << "μs\n\n";
        break;
      case 3:
        std::cout << "Introduzca una cantidad de opciones para la lista "
                     "restringida de candidatos: ";
        std::cin >> lrcNumber;
        std::cout
            << "Introduzca un método para generar las soluciones vecinas: "
            << std::endl
            << "1. Intercambio de tareas entre máquinas." << std::endl
            << "2. Intercambio de tareas en la misma máquina." << std::endl
            << "3. Reinserción de tareas en otra máquina." << std::endl
            << "4. Reinserción de tareas en la misma máquina." << std::endl
            << ">> ";
        std::cin >> operation;
        std::cout << "Introduzca un método para la búsqueda: " << std::endl
                  << "1. Greedy" << std::endl
                  << "2. Ansioso" << std::endl
                  << ">> ";
        std::cin >> search;
        std::cout << "Introduzca una condición de parada: " << std::endl
                  << "1. Número de iteraciones" << std::endl
                  << "2. Número de iteraciones sin ninguna mejora" << std::endl
                  << ">> ";
        std::cin >> stop;
        std::cout << "Introduzca un número de iteraciones para la parada: ";
        std::cin >> iterations;
        start = std::chrono::steady_clock::now();
        machinesTest.grasp(lrcNumber, operation, search, stop, iterations);
        end = std::chrono::steady_clock::now();
        machinesTest.showResults(std::cout);
        std::cout << "Elapsed time: "
                  << std::chrono::duration_cast<std::chrono::microseconds>(
                         end - start)
                         .count()
                  << "μs\n\n";
        break;
      default:
        std::cout << "Opción no permitida. Inténtelo de nuevo." << std::endl;
        break;
    }
  }
}

void fullTest() {
  std::cout << "----- ALGORITMO GREEDY 1 -----\n";
  start = std::chrono::steady_clock::now();
  machinesTest.greedy1();
  end = std::chrono::steady_clock::now();
  machinesTest.showResults(std::cout);
  std::cout << "Elapsed time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << "μs\n\n";
  std::cout << "----- ALGORITMO GREEDY 2 -----\n";
  start = std::chrono::steady_clock::now();
  machinesTest.greedy2();
  end = std::chrono::steady_clock::now();
  machinesTest.showResults(std::cout);
  std::cout << "Elapsed time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << "μs\n\n";
  std::cout << "------ ALGORITMO GRASP ------- (k = 3) \n\n";
  std::cout << "-- Intercambio Inter (GREEDY):\n";
  start = std::chrono::steady_clock::now();
  machinesTest.grasp(lrcNumber, 2, search, stop, iterations);
  end = std::chrono::steady_clock::now();
  machinesTest.showResults(std::cout);
  std::cout << "Elapsed time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << "μs\n\n";
  std::cout << "-- Intercambio Inter (ANSIOSA):\n";
  start = std::chrono::steady_clock::now();
  machinesTest.grasp(lrcNumber, 2, 2, stop, iterations);
  end = std::chrono::steady_clock::now();
  machinesTest.showResults(std::cout);
  std::cout << "Elapsed time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << "μs\n\n";
  std::cout << "-- Intercambio Intra (GREEDY):\n";
  start = std::chrono::steady_clock::now();
  machinesTest.grasp(lrcNumber, 1, search, stop, iterations);
  end = std::chrono::steady_clock::now();
  machinesTest.showResults(std::cout);
  std::cout << "Elapsed time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << "μs\n\n";
  std::cout << "-- Intercambio Intra (ANSIOSA):\n";
  start = std::chrono::steady_clock::now();
  machinesTest.grasp(lrcNumber, 1, 2, stop, iterations);
  end = std::chrono::steady_clock::now();
  machinesTest.showResults(std::cout);
  std::cout << "Elapsed time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << "μs\n\n";
  std::cout << "-- Reinserción Inter (GREEDY):\n";
  start = std::chrono::steady_clock::now();
  machinesTest.grasp(lrcNumber, 4, search, stop, iterations);
  end = std::chrono::steady_clock::now();
  machinesTest.showResults(std::cout);
  std::cout << "Elapsed time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << "μs\n\n";
  std::cout << "-- Reinserción Inter (ANSIOSA):\n";
  start = std::chrono::steady_clock::now();
  machinesTest.grasp(lrcNumber, 4, 2, stop, iterations);
  end = std::chrono::steady_clock::now();
  machinesTest.showResults(std::cout);
  std::cout << "Elapsed time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << "μs\n\n";
  std::cout << "-- Reinserción Intra (GREEDY):\n";
  start = std::chrono::steady_clock::now();
  machinesTest.grasp(lrcNumber, 3, search, stop, iterations);
  end = std::chrono::steady_clock::now();
  machinesTest.showResults(std::cout);
  std::cout << "Elapsed time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << "μs\n\n";
  std::cout << "-- Reinserción Intra (ANSIOSA):\n";
  start = std::chrono::steady_clock::now();
  machinesTest.grasp(lrcNumber, 3, 2, stop, iterations);
  end = std::chrono::steady_clock::now();
  machinesTest.showResults(std::cout);
  std::cout << "Elapsed time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << "μs\n\n";
  std::cout << "------- ALGORITMO VND (GREEDY) --------\n";
  start = std::chrono::steady_clock::now();
  machinesTest.grasp(3, 1, search, 1, 100);
  machinesTest.VND(1);
  end = std::chrono::steady_clock::now();
  machinesTest.showResults(std::cout);
  std::cout << "Elapsed time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << "μs\n\n";
  std::cout << "------- ALGORITMO VND (ANSIOSA) --------\n";
  start = std::chrono::steady_clock::now();
  machinesTest.grasp(3, 1, search, 1, 100);
  machinesTest.VND(2);
  end = std::chrono::steady_clock::now();
  machinesTest.showResults(std::cout);
  std::cout << "Elapsed time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << "μs\n\n";
  std::cout << "------- ALGORITMO GVNS (GREEDY) -------\n";
  start = std::chrono::steady_clock::now();
  machinesTest.GVNS(1);
  end = std::chrono::steady_clock::now();
  machinesTest.showResults(std::cout);
  std::cout << "Elapsed time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << "μs\n\n";
  std::cout << "------- ALGORITMO GVNS (ANSIOSA) -------\n";
  start = std::chrono::steady_clock::now();
  machinesTest.GVNS(2);
  end = std::chrono::steady_clock::now();
  machinesTest.showResults(std::cout);
  std::cout << "Elapsed time: "
            << std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                     start)
                   .count()
            << "μs\n\n";
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cout
        << "Error en la ejecución. Por favor, ejecute de la siguiente forma:"
        << std::endl;
    std::cout << "./machines inputFile.txt 0 (Para ejecutar en modo menú)\n";
    std::cout << "./machines inputFile.txt 1 (Para ejecutar en modo traza)\n";
    return 1;
  }
  try {
    machinesTest.read(argv[1]);
  } catch (int) {
    std::cout << "Error en la apertura de archivo.\n";
    return 0;
  }
  if (std::stoi(argv[2]) == 1) {
    fullTest();
  }
  if (std::stoi(argv[2]) == 0) {
    menu();
  }
}
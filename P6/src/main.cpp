#include <iostream>

#include "../include/LCS.h"

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cout << "Error de ejecución. Por favor utilice la siguiente forma:"
              << std::endl
              << "./LCS cadena1 cadena2 " << std::endl
              << "Donde cadena1 y cadena2 serán las dos cadenas a comparar "
              << " para encontrar la sucesión común más larga. " << std::endl;
    return 0;
  }

  LCS lcs(argv[1], argv[2]);
  lcs.solveAll();
  std::set<std::pair<int, std::string>> solutions = lcs.getSol();

  if (solutions.size() == 0) {
    std::cout << "No se encontró una sucesión común entre " << argv[1] << " y "
              << argv[2] << "." << std::endl;
  } else {
    if (solutions.size() == 1) {
      std::cout << "La sucesión común más larga encontrada entre " << argv[1]
                << " y " << argv[2] << " es ";
    } else {
      std::cout << "Las sucesiones comunes más largas encontradas entre "
                << argv[1] << " y " << argv[2] << " son: " << std::endl;
    }
    for (auto sol : solutions) {
      std::cout << sol.second << " con una longitud de " << sol.first
                << std::endl;
    }
  }
}
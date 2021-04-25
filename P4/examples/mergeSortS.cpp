#include "mergeSortS.h"

void mergeSortS::resolver() {
  std::cout << "[ ";
  for (auto element : sequence) {
    std::cout << element << " ";
  }
  std::cout << "]\n";
}

void mergeSortS::mezcla(pair<Solucion*, Solucion*> subSoluciones) {
  std::vector<int> first_sequence =
      ((mergeSortS*)subSoluciones.first)->getSequence();
  std::vector<int> second_sequence =
      ((mergeSortS*)subSoluciones.second)->getSequence();
  int i = 0, j = 0;
  // Hacemos la mezcla ordenando los elementos de ambos vectores hasta recorrer
  // del todo uno o ambos
  while (i < first_sequence.size() && j < second_sequence.size()) {
    if (first_sequence[i] <= second_sequence[j]) {
      sequence.push_back(first_sequence[i]);
      i++;
    } else {
      sequence.push_back(second_sequence[j]);
      j++;
    }
  }
  // Insertamos elementos restantes
  while (i < first_sequence.size()) {
    sequence.push_back(first_sequence[i]);
    i++;
  }
  // Insertamos elementos restantes
  while (j < second_sequence.size()) {
    sequence.push_back(second_sequence[j]);
    j++;
  }
}
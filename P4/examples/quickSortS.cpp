#include "quickSortS.h"

void quickSortS::mezcla(pair<Solucion*,Solucion*> subSoluciones) {
  std::vector<int> first = ((quickSortS*)subSoluciones.first)->getSequence();
  std::vector<int> second = ((quickSortS*)subSoluciones.second)->getSequence();
  first.insert(first.end(), second.begin(), second.end());
  sequence = first;
}

void quickSortS::resolver() {
  std::cout << "[ ";
	for (auto element : sequence) {
    std::cout << element << " ";
  }
  std::cout << "]\n";
}
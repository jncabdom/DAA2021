#include "mergeSortP.h"

pair<Problema*, Problema*> mergeSortP::descomponer() {
  pair<Problema*, Problema*> subProblemas;
  subProblemas.first = new mergeSortP(std::vector<int>(
      sequence.begin(), sequence.begin() + sequence.size() / 2));
  subProblemas.second = new mergeSortP(
      std::vector<int>(sequence.begin() + sequence.size() / 2, sequence.end()));
  return subProblemas;
}

void mergeSortP::solver(Solucion* s) {
  if (sequence.size() > 1 && sequence[1] < sequence[0]) {
    int aux = sequence[0];
    sequence[0] = sequence[1];
    sequence[1] = aux;
  }
  ((mergeSortS*)s)->setValor(sequence);
}
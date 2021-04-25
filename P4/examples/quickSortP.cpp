#include "quickSortP.h"

pair<Problema*, Problema*> quickSortP::descomponer() {
  pair<Problema*, Problema*> subProblemas;
  // Elegimos último elemento como pivote
  int pivote = sequence[sequence.size() - 1];
  int i = 0;
  // Vamos enviando atrás los elementos menores que el pivote
  for (int j = 0; j < sequence.size(); j++) {
    if (sequence[j] <= pivote) {
      int aux = sequence[j];
      sequence[j] = sequence[i];
      sequence[i] = aux;
      if(i < sequence.size() - 1) i++;
    }
  }
  // Al acabar, colocamos el pivote
  int aux = sequence[i];
  sequence[i] = sequence[sequence.size() - 1];
  sequence[sequence.size() - 1] = aux;

  subProblemas.first =
      new quickSortP(std::vector<int>(sequence.begin(), sequence.begin() + i));
  subProblemas.second =
      new quickSortP(std::vector<int>(sequence.begin() + i, sequence.end()));
  return subProblemas;
}

void quickSortP::solver(Solucion* s) {
  if (sequence.size() > 1)
    if (sequence[1] < sequence[0]) {
      int aux = sequence[0];
      sequence[0] = sequence[1];
      sequence[1] = aux;
    }
  ((quickSortS*)s)->setValor(sequence);
}
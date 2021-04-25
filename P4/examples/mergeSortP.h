
#ifndef MERGESORTP_H_
#define MERGESORTP_H_

#include "../framework/Problema.h"
#include "mergeSortS.h"

class mergeSortP : public Problema {
 private:
  std::vector<int> sequence;

 public:
  mergeSortP(std::vector<int> newSequence) { sequence = newSequence; }
  ~mergeSortP() {}

  bool isCasoMinimo() { return (sequence.size() <= 2); }
  pair<Problema*, Problema*> descomponer();
  void solver(Solucion* s);
};

#endif /* MERGESORTP_H_ */
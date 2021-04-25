
#ifndef QUICKSORTP_H_
#define QUICKSORTP_H_

#include "../framework/Problema.h"
#include "quickSortS.h"

class quickSortP : public Problema {
 private:
  std::vector<int> sequence;

 public:
  quickSortP(std::vector<int> newSequence) { sequence = newSequence; }
  virtual ~quickSortP() {}

  inline bool isCasoMinimo() { return(sequence.size() <= 2); }
  pair<Problema*, Problema*> descomponer();

  void solver(Solucion* s);

  inline std::vector<int> getSequence() { return sequence; }
};

#endif /* QUICKSORTP_H_ */
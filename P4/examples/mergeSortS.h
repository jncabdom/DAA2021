
#ifndef MERGESORTS_H_
#define MERGESORTS_H_

#include "../framework/Solucion.h"

class mergeSortS : public Solucion {
 private:
  std::vector<int> sequence;

 public:
  mergeSortS() {}
  ~mergeSortS() {}
  void resolver();
  void mezcla(pair<Solucion*, Solucion*>);
  Solucion* getInstance() { return new mergeSortS(); }
  inline std::vector<int> getSequence() { return sequence; }
  void setValor(std::vector<int> newSequence) { sequence = newSequence; }
};

#endif /* MERGESORTS_H_ */
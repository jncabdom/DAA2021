
#ifndef QUICKSORTS_H_
#define QUICKSORTS_H_

#include <vector>

#include "../framework/Solucion.h"

class quickSortS : public Solucion {
 private:
  std::vector<int> sequence;
 public:
  quickSortS() {}
  virtual ~quickSortS() {}
  void resolver();
  void mezcla(pair<Solucion*, Solucion*>);
  inline std::vector<int> getSequence() { return sequence; }
  inline Solucion* getInstance() { return new quickSortS; }
  inline void setValor(std::vector<int> newSequence) { sequence = newSequence; }
};

#endif /* QUICKSORTS_H_ */
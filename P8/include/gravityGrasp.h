#include "gravity.h"

class gravityGrasp : public gravity {
 private:
  int lrc;
  int iter;

 public:
  gravityGrasp(pointSpace nCoord, int nLrc ,int nIter) : gravity(nCoord), lrc(nLrc), iter(nIter) {}
  ~gravityGrasp() {}
  pointSpace run(int);
  pointSpace singleRun(int);
  pointSpace enhance(pointSpace);
  pointSpace construct(int);
};
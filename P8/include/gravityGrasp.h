#include "gravity.h"

class gravityGrasp : public gravity {
 private:
  int lrc;

 public:
  gravityGrasp(pointSpace nCoord, int nLrc) : gravity(nCoord), lrc(nLrc) {}
  ~gravityGrasp() {}
  pointSpace run(int);
  pointSpace enhance(pointSpace);
  pointSpace construct(int);
};
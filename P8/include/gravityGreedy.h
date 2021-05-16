#include "gravity.h"

class gravityGreedy : public gravity {
 private:
 public:
  gravityGreedy(pointSpace nCoord) : gravity(nCoord) {}
  ~gravityGreedy() {}
  pointSpace run(int k);
};
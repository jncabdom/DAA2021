#include "gravityBnB.h"

class gravityBnB1 : public gravityBnB {
 private:
 public:
  gravityBnB1(pointSpace nCoord, pointSpace initialSol)
      : gravityBnB(nCoord, initialSol) {}
  ~gravityBnB1() {}
  std::set<searchNode>::iterator selectNode();
};

std::set<searchNode>::iterator gravityBnB1::selectNode() {
  std::set<searchNode>::iterator best = tree.begin();
  std::set<searchNode>::iterator it = tree.begin();
  while (it != tree.end()) {
    if (getZ(it->getSol()) < getZ(best->getSol())) {
      best = it;
    }
    ++it;
  }
  return best;
}
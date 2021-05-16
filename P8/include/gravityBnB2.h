#include "gravityBnB.h"

class gravityBnB2 : public gravityBnB {
 private:
 public:
  gravityBnB2(pointSpace nCoord, pointSpace initialSol)
      : gravityBnB(nCoord, initialSol) {}
  ~gravityBnB2() {}
  std::set<searchNode>::iterator selectNode();
};

std::set<searchNode>::iterator gravityBnB2::selectNode() {
  std::set<searchNode>::iterator best = tree.begin();
  std::set<searchNode>::iterator it = tree.begin();
  while (it != tree.end()) {
    if (it->getLevel() > best->getLevel()) {
      best = it;
    }
    ++it;
  }
  return best;
}
#pragma once

#include <set>

#include "gravity.h"
#include "searchNode.h"



class gravityBnB : public gravity {
 protected:
  searchNode lowerBound;
  std::set<searchNode> tree;
  int nodeCount = 0;

  float getValue(pointSpace);
  point getBestZPoint(pointSpace auxSolution, pointSpace elements);
  void newNode(pointSpace, float, int);
 public:
  gravityBnB(pointSpace nCoord, pointSpace initialSol) : gravity(nCoord) {
    lowerBound = searchNode(initialSol, getZ(initialSol), 0);
  }
  ~gravityBnB() {}
  pointSpace run(int);
  void expand(searchNode);
  virtual std::set<searchNode>::iterator selectNode() = 0;
  int getNodeCount() { return nodeCount; }
};
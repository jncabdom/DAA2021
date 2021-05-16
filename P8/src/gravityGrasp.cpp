#include "../include/gravityGrasp.h"

pointSpace gravityGrasp::run(int k) {
  pointSpace firstSol, nextSol, bestSol;
  firstSol = construct(k);
  bestSol = firstSol;
  for (int i = 0; i < 100; i++) {
    nextSol = enhance(firstSol);
    if(getZ(firstSol) >= getZ(nextSol)) {
      if(getZ(firstSol) > getZ(bestSol)) {
        bestSol = firstSol;
      }
    }
    else if(getZ(nextSol) > getZ(bestSol)) {
      bestSol = nextSol;
    }
    firstSol = construct(k);
  }
  return bestSol;
}

pointSpace gravityGrasp::enhance(pointSpace firstSol) {
  pointSpace nextSol = neighborExplore(firstSol);
  return (getZ(nextSol) > getZ(firstSol)) ? nextSol : firstSol;
}

pointSpace gravityGrasp::construct(int k) {
  pointSpace elements = coordinates;
  pointSpace solution = {};
  point center = getCenter(elements);

  while ((elements.size() > 0) && (solution.size() != k)) {
    std::vector<int> furthestK = getBetterK(lrc, center, elements);
    int furthest = furthestK[rand() % furthestK.size()];
    solution.push_back(elements[furthest]);
    elements.erase(elements.begin() + furthest);
    center = getCenter(solution);
  }
  return solution;
}
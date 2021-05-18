#include "../include/gravityGrasp.h"

// Main run function, implements a GRASP algorithm
// to construct and then improve via local search
pointSpace gravityGrasp::run(int k) {
  pointSpace firstSol, nextSol, bestSol;
  firstSol = construct(k);
  bestSol = firstSol;
  for (int i = 0; i < iter; i++) {
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

// Single run of grasp. One construction, one improvement
pointSpace gravityGrasp::singleRun(int k) {
  pointSpace firstSol = construct(k);
  firstSol = enhance(firstSol);
  return firstSol;
}

// Does a neighbor exploration onto *firstSol*. Returns the best one
pointSpace gravityGrasp::enhance(pointSpace firstSol) {
  pointSpace nextSol = neighborExplore(firstSol);
  return (getZ(nextSol) > getZ(firstSol)) ? nextSol : firstSol;
}

// Construction phase of the GRASP algorithm. Builds a solution
// via pseudo-random insertions.
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
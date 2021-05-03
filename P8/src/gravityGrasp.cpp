#include "../include/gravityGrasp.h"

pointSpace gravityGrasp::run(int k) {
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
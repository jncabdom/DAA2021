#include "../include/gravityGreedy.h"

pointSpace gravityGreedy::run(int k) {
  pointSpace elements = coordinates;
  pointSpace solution = {};
  point center = getCenter(elements);

  while ((elements.size() > 0) && (solution.size() != k)) {
    int furthest = getBetterK(1, center, elements)[0];
    solution.push_back(elements[furthest]);
    elements.erase(elements.begin() + furthest);
    center = getCenter(solution);
  }
  return solution;
}
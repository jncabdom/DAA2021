#include "../include/gravity.h"

// Prints all the point space through os
std::ostream& gravity::print(std::ostream& os) {
  for (auto it : coordinates) {
    for (auto coord : it) {
      os << coord << " ";
    }
    os << std::endl;
  }
  return os;
}

// Calculates the center of mass of the space of points *coords*
point gravity::getCenter(pointSpace coords) {
  point center = coords[0];

  if (coords.size() > 1)
    for (int i = 1; i < coords.size(); i++) {
      for (int j = 0; j < coords[i].size(); j++) {
        center[j] += coords[i][j];
      }
    }

  float modifier = 1.0 / coords.size();

  for (int i = 0; i < center.size(); i++) {
    center[i] *= modifier;
  }

  return center;
}

// Calculates the euclidean distance between the two points
float gravity::getDist(point p1, point p2) {
  float accum = 0;
  float accum2;
  for (int i = 0; i < p1.size(); i++) {
    accum2 = p2[i] - p1[i];
    accum += accum2 * accum2;
  }
  return sqrt(accum);
}

// Returns a vector with the k first best insertions of points to make around
// *center*
std::vector<int> gravity::getBetterK(int k, point center, pointSpace points) {
  std::vector<int> candidates;
  pointSpace coords = points;
  float currentDist = 0;
  while ((candidates.size() != k) && (!coords.empty())) {
    int bestPoint = 0;
    float bestDistance = getDist(center, coords[bestPoint]);
    if (coords.size() > 1)
      for (int i = 1; i < coords.size(); i++) {
        currentDist = getDist(center, coords[i]);
        if (currentDist > bestDistance) {
          bestDistance = currentDist;
          bestPoint = i;
        }
      }
    candidates.push_back(bestPoint);
    coords.erase(coords.begin() + bestPoint);
  }
  return candidates;
}

// Calculates the objective function value for *points*
float gravity::getZ(pointSpace points) {
  float acc = 0;
  for (int i = 0; i < points.size(); i++) {
    for (int j = i + 1; j < points.size(); j++) {
      acc += getDist(points[i], points[j]);
    }
  }
  return acc;
}

// Explores the neighborhood of solutions to find the best one.
// Uses ls, an object of type localSearch
pointSpace gravity::neighborExplore(pointSpace mainSolution) {
  ls.setMainSolution(mainSolution);
  ls.setCoordinates(coordinates);
  ls.genSolutions();
  auto bestSol = ls.greedyExploration();
  if (getZ(bestSol) > getZ(mainSolution)) {
    return neighborExplore(bestSol);
  }
  return mainSolution;
}
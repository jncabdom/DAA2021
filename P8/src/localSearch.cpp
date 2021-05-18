#include "../include/localSearch.h"

// Calculates the objective function Z for the
// point space *points*
float localSearch::getZ(pointSpace points) {
  float acc = 0.0;
  for (int i = 0; i < points.size(); i++) {
    for (int j = i + 1; j < points.size(); j++) {
      acc += getDist(points[i], points[j]);
    }
  }
  return acc;
}

// Calculates the distance between the two points
float localSearch::getDist(point p1, point p2) {
  float accum = 0.0;
  float accum2 = 0.0;
  for (int i = 0; i < p1.size(); i++) {
    accum2 = p2[i] - p1[i];
    accum += (accum2 * accum2);
  }
  return sqrt(accum);
}

// Generates all neighbor solutions via interchanging
// every point in the solution with every other point
// that is outside.
void localSearch::genSolutions() {
  neighborSolutions.clear();
  pointSpace auxSolution = mainSolution;
  for (int i = 0; i < mainSolution.size(); i++) {
    for (int j = 0; j < ogCoordinates.size(); j++) {
      if (std::find(auxSolution.begin(), auxSolution.end(), ogCoordinates[j]) == auxSolution.end()) {
        auxSolution[i] = ogCoordinates[j];
        neighborSolutions.push_back(auxSolution);
        auxSolution = mainSolution;
      }
    }
  }
}

// Does a greedy exploration of the solution neighborhood.
// Returns the best one
pointSpace localSearch::greedyExploration() {
  pointSpace bestSol = neighborSolutions[0];
  float bestZ = getZ(bestSol);

  if (neighborSolutions.size() > 1)
    for (int i = 1; i < neighborSolutions.size(); i++) {
      if (getZ(neighborSolutions[i]) > bestZ) {
        bestSol = neighborSolutions[i];
        bestZ = getZ(bestSol);
      }
    }
  return bestSol;
}
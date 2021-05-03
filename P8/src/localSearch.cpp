#include "../include/localSearch.h"

int localSearch::getZ(pointSpace points) {
  float acc = 0;
  for (int i = 0; i < points.size(); i++) {
    for (int j = i + 1; j < points.size(); j++) {
      acc += getDist(points[i], points[j]);
    }
  }
  return acc;
}

float localSearch::getDist(point p1, point p2) {
  float accum = 0;
  float accum2;
  for (int i = 0; i < p1.size(); i++) {
    accum2 = p2[i] - p1[i];
    accum += accum2 * accum2;
  }
  return sqrt(accum);
}

void localSearch::genSolutions() {
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

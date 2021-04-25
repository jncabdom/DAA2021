#include "../include/localSearch.h"

#include <iostream>

void localSearch::exploreAndImprove(int operation, int search) {
  neighborSolutions.clear();
  switch (operation) {
    case 1:
      genSolutionsIntraInter();
      break;
    case 2:
      genSolutionsInterInter();
      break;
    case 3:
      genSolutionsIntraReinser();
      break;
    case 4:
      genSolutionsInterReinser();
      break;
    default:
      break;
  }
  switch (search) {
    case 1:
      searchGreedy(operation);
      break;
    case 2:
      searchAnxious(operation);
  }
}

void localSearch::genSolutionsIntraInter(void) {
  std::vector<machine> auxVect = mainSolution;
  for (int i = 0; i < auxVect.size(); i++) {
    for (int j = 0; j < auxVect[i].getTasks().size(); j++) {
      for (int z = i; z < auxVect.size(); z++) {
        if (z != i) {
          for (int w = 0; w < auxVect[z].getTasks().size(); w++) {
            std::swap(auxVect[i].getTasks()[j], auxVect[z].getTasks()[w]);
            recalculateTime(auxVect, i, j);
            recalculateTime(auxVect, z, w);
            neighborSolutions.push_back(auxVect);
            auxVect = mainSolution;
          }
        }
      }
    }
  }
}

void localSearch::genSolutionsInterInter(void) {
  std::vector<machine> auxVect = mainSolution;
  for (int i = 0; i < auxVect.size(); i++) {
    for (int j = 0; j < auxVect[i].getTasks().size(); j++) {
      for (int z = j; z < auxVect[i].getTasks().size(); z++) {
        if (j != z) {
          std::swap(auxVect[i].getTasks()[j], auxVect[i].getTasks()[z]);
          recalculateTime(auxVect, i, j);
          recalculateTime(auxVect, i, z);
          neighborSolutions.push_back(auxVect);
          auxVect = mainSolution;
        }
      }
    }
  }
}

void localSearch::genSolutionsIntraReinser(void) {
  std::vector<machine> auxVect = mainSolution;
  for (int i = 0; i < auxVect.size(); i++) {
    for (int j = 0; j < auxVect[i].getTasks().size(); j++) {
      for (int z = 0; z < auxVect.size(); z++) {
        if (z != i) {
          for (int w = 0; w <= auxVect[z].getTasks().size(); w++) {
            auxVect[z].getTasks().insert(auxVect[z].getTasks().begin() + w,
                                         auxVect[i].getTasks()[j]);
            auxVect[i].getTasks().erase(auxVect[i].getTasks().begin() + j);
            recalculateTime(auxVect, i, j);
            recalculateTime(auxVect, z, w);
            neighborSolutions.push_back(auxVect);
            auxVect = mainSolution;
          }
        }
      }
    }
  }
}

void localSearch::genSolutionsInterReinser(void) {
  std::vector<machine> auxVect = mainSolution;
  std::pair<int, int> auxPair;
  for (int i = 0; i < auxVect.size(); i++) {
    for (int j = 0; j < auxVect[i].getTasks().size(); j++) {
      for (int z = 0; z < auxVect[i].getTasks().size(); z++) {
        if (j != z) {
          auxPair = auxVect[i].getTasks()[j];
          auxVect[i].getTasks().erase(auxVect[i].getTasks().begin() + j);
          auxVect[i].getTasks().insert(auxVect[i].getTasks().begin() + z,
                                       auxPair);
            recalculateTime(auxVect, i, j);
            recalculateTime(auxVect, i, z);
          neighborSolutions.push_back(auxVect);
          auxVect = mainSolution;
        }
      }
    }
  }
}

void localSearch::searchGreedy(int op) {
  int minTCT = calculateTCT(mainSolution);
  int currentTCT;
  bool found = false;
  std::vector<machine> minSolution = mainSolution;
  for (auto neighbor : neighborSolutions) {
    currentTCT = calculateTCT(neighbor);
    if (currentTCT < minTCT) {
      minSolution = neighbor;
      found = true;
    }
  }
  if (found) {
    mainSolution = minSolution;
    exploreAndImprove(op, 1);
  }
}

void localSearch::searchAnxious(int op) {
  int minTCT = calculateTCT(mainSolution);
  int currentTCT;
  bool found = false;
  std::vector<machine> minSolution = mainSolution;
  for (auto neighbor : neighborSolutions) {
    currentTCT = calculateTCT(neighbor);
    if (currentTCT < minTCT) {
      minSolution = neighbor;
      found = true;
      break;
    }
  }
  if (found) {
    mainSolution = minSolution;
    exploreAndImprove(op, 2);
  }
}

int localSearch::calculateTCT(std::vector<machine> solution) {
  int counter = 0;
  for (auto machine : solution) {
    machine.calculateTCT();
    counter += machine.getTCT();
  }
  return counter;
}

void localSearch::recalculateTime(std::vector<machine>& machineArray,
                                  int machineIndex, int taskIndex) {
  std::vector<std::pair<int, int>>& machine =
      machineArray[machineIndex].getTasks();
  if (taskIndex == 0) {
    machine[taskIndex].second = prepCosts[0][machine[taskIndex].first] +
                                taskCosts[machine[taskIndex].first - 1];
  } else {
    machine[taskIndex].second = prepCosts[machine[taskIndex - 1].first]
                                         [machine[taskIndex].first] +
                                taskCosts[machine[taskIndex].first - 1];
  }
  if (taskIndex < machine.size() - 1) {
    machine[taskIndex + 1].second =
        prepCosts[machine[taskIndex].first]
                 [machine[taskIndex + 1].first] +
        taskCosts[machine[taskIndex + 1].first - 1];
  }
}
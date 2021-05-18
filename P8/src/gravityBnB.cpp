#include "../include/gravityBnB.h"

// Main run function. Branch and bound algorithm.
pointSpace gravityBnB::run(int k) {
  nodeCount = 0;
  pointSpace auxSolution;
  for (auto point : coordinates) {
    auxSolution.clear();
    auxSolution.push_back(point);
    newNode(auxSolution, getValue(auxSolution), 0);
  }
  while (!tree.empty()) {
    auto selectedNode = selectNode();
    if (selectedNode->getSol().size() == lowerBound.getSol().size()) {
      if (getZ(selectedNode->getSol()) > getZ(lowerBound.getSol()))
        lowerBound = *selectedNode;
    } else {
      expand(*selectedNode);
    }
    tree.erase(selectedNode);
    tree.erase(tree.begin(), tree.upper_bound(lowerBound));
  }
  return lowerBound.getSol();
}

// Expands the selected node. That is: inserts all children into the tree
void gravityBnB::expand(searchNode node) {
  pointSpace originalSol = node.getSol();
  pointSpace auxSol;
  searchNode auxNode;
  int level = node.getLevel() + 1;
  for (auto p : coordinates) {
    if (std::find(originalSol.begin(), originalSol.end(), p) ==
        originalSol.end()) {
      auxSol = originalSol;
      auxSol.push_back(p);
      newNode(auxSol, getValue(auxSol), level);
    }
  }
}

// Calculates the value (upper bound) for a partial solution
float gravityBnB::getValue(pointSpace partSolution) {
  if (partSolution.size() == lowerBound.getSol().size()) {
    return getZ(partSolution);
  }
  pointSpace auxSolution = partSolution;
  pointSpace elements = coordinates;
  elements.erase(std::remove_if(elements.begin(), elements.end(), [&auxSolution](const point& x) {
    return std::find(auxSolution.begin(), auxSolution.end(), x) != auxSolution.end();}), elements.end());
  while (auxSolution.size() != lowerBound.getSol().size()) {
    auxSolution.push_back(getBestZPoint(auxSolution, elements));
  }
  return getZ(auxSolution);
}

// Calculates the best insertion one could possibly make. This is used by
// getValue()
point gravityBnB::getBestZPoint(pointSpace auxSolution, pointSpace elements) {
  auxSolution.push_back(elements[0]);
  int index = 0;
  float bestZ = getZ(auxSolution);
  auxSolution.pop_back();
  for (int i = 1; i < elements.size(); i++) {
    auxSolution.push_back(elements[i]);
    if (getZ(auxSolution) > bestZ) {
      bestZ = getZ(auxSolution);
      index = i;
    }
    auxSolution.pop_back();
  }
  return elements[index];
}

// Inserts a new node into the tree
void gravityBnB::newNode(pointSpace newPoints, float newZ, int layer) {
  nodeCount++;
  searchNode newNode(newPoints, newZ, layer);
  tree.insert(newNode);
}
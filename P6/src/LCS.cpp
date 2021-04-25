#include "../include/LCS.h"

LCS::LCS(std::string newString1, std::string newString2) {
  substr1 = newString1;
  substr2 = newString2;
}

void LCS::solveAll() {
  for (int i = 0; i < substr1.size(); i++) {
    if ((substr1.size() - i + 1) < maxSize) {
      break;
    }
    solve(i);
  }

  /* std::string aux = substr1;
   substr1 = substr2;
   substr2 = aux;

   for (int i = 0; i < substr1.size(); i++) {
     if (substr1.size() - i + 1 < maxSize) {
       break;
     }
     solve(i);
   }
   aux = substr1;
   substr1 = substr2;
   substr2 = aux;*/
}

void LCS::resetMatrix() {
  std::pair<int, std::string> aux = {0, ""};
  matrix.resize(substr1.size() + 1);
  for (int i = 0; i < matrix.size(); i++) {
    matrix[i].resize(substr2.size() + 1);
    std::fill(matrix[i].begin(), matrix[i].end(), aux);
  }
}

void LCS::solve(int startPoint) {
  resetMatrix();
  for (int i = startPoint + 1; i < matrix.size(); i++) {
    for (int j = 1; j < matrix[i].size(); j++) {
      if (substr1[i - 1] == substr2[j - 1]) {
        matrix[i][j].second = matrix[i - 1][j - 1].second + substr1[i - 1];
        matrix[i][j].first = 1 + matrix[i - 1][j - 1].first;
      } else {
        if (matrix[i - 1][j].first >= matrix[i][j - 1].first) {
          matrix[i][j] = matrix[i - 1][j];
        } else
          matrix[i][j] = matrix[i][j - 1];
      }
    }
  }
  generateSolutionsFromMatrix();
}

void LCS::generateSolutionsFromMatrix() {
  if (matrix[substr1.size()][substr2.size()].first >= maxSize) {
    maxSize = matrix[substr1.size()][substr2.size()].first;
    solutions.insert(matrix[substr1.size()][substr2.size()]);
  }
}
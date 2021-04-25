#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <set>

class LCS {
 private:
  int maxSize = 0;
  std::string substr1;
  std::string substr2;
  std::vector<std::vector<std::pair<int, std::string>>> matrix;
  std::set<std::pair<int, std::string>> solutions = {};

  void generateSolutionsFromMatrix();
  void resetMatrix();
 public:
  LCS() {}
  LCS(std::string, std::string);
  ~LCS() {}

  void solve(int);
  void solveAll();
  inline std::set<std::pair<int, std::string>> getSol() { return solutions; }
};
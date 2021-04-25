#include <vector>

#include "machine.h"

class localSearch {
 private:
  std::vector<machine> mainSolution;
  std::vector<std::vector<machine>> neighborSolutions = {};

  std::vector<int> taskCosts;
  std::vector<std::vector<int>> prepCosts;

  void genSolutionsInterInter();
  void genSolutionsInterReinser();
  void genSolutionsIntraInter();
  void genSolutionsIntraReinser();

  void searchGreedy(int);
  void searchAnxious(int);

  int calculateTCT(std::vector<machine>);


 public:
  localSearch() {}
  ~localSearch() {}
  inline void setPrepCosts(std::vector<std::vector<int>> newCosts) { prepCosts = newCosts; }
  inline void setTaskCosts(std::vector<int> newCosts) { taskCosts = newCosts; }
  inline void setMainSolution(std::vector<machine> mainSol) {
    mainSolution = mainSol;
  }
  inline std::vector<machine> getmainSolution() { return mainSolution; }
  void exploreAndImprove(int, int);
  void recalculateTime(std::vector<machine>&, int, int);
};
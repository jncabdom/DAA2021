#include <iostream>
#include <string>
#include <vector>

#include "localSearch.h"

class machines {
 private:
  std::vector<machine> allMachines;
  std::vector<int>
      remainingTasks;  // Initialize at the start of every algorithm
  std::vector<int> taskCosts;
  std::vector<std::vector<int>> prepCosts;

  localSearch localSearchGrasp;

  void resetRemainingVector();
  void resetMachines();
  void assigned(int);
  std::vector<std::vector<int>> constructlrc(int, int);
  void graspConstruct(int);
  void graspImprove(int, int);
  int calculateTCT(std::vector<machine>);
  int calculateMaxK();
  void randomJumpInterchange(int);

 public:
  machines() {}
  ~machines() {}
  inline machines(std::string fileName) { read(fileName); }

  std::ostream& showResults(std::ostream&);
  void read(std::string);

  inline int getTCT() { return calculateTCT(allMachines); }

  void greedy1();
  void greedy2();
  void grasp(int, int, int, int, int);
  void VND(int);
  void GVNS(int);
};
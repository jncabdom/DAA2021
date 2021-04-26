#include "../include/machines.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <utility>

/*
 * Reads all content from a file with name *filename*
 */
void machines::read(std::string fileName) {
  std::string auxString;
  std::ifstream input;

  input.open(fileName);
  if (!input.is_open()) {
    throw 1;
  }

  // Reading (getting rid of) the first
  // line containing number of tasks.
  input >> auxString >> auxString;

  // Reading machine number
  input >> auxString >> auxString;
  allMachines.resize(stoi(auxString));
  input >> auxString;

  // Reading all task costs
  getline(input, auxString);
  std::istringstream iss(auxString);
  while (iss >> auxString) {
    taskCosts.push_back(stoi(auxString));
  }

  // Reading all task setup times
  getline(input, auxString);
  std::vector<int> auxVector;
  while (getline(input, auxString)) {
    std::istringstream iss(auxString);
    while (iss >> auxString) {
      auxVector.push_back(stoi(auxString));
    }
    prepCosts.push_back(auxVector);
    auxVector.clear();
  }

  localSearchGrasp.setPrepCosts(prepCosts);
  localSearchGrasp.setTaskCosts(taskCosts);

}

/*
 * Greedy algorithm for selecting each machine's assigned tasks.
 */
void machines::greedy1() {
  resetRemainingVector();
  resetMachines();
  while (remainingTasks.size() != 0) {
    // First, we set minimum TCT increment, task and machine to
    //*task 0 -> machine 0*
    int minTask = remainingTasks[0];
    int minTime =
        prepCosts[0][remainingTasks[0]] + taskCosts[remainingTasks[0] - 1];
    int minMachine = 0;
    int minIncrement = minTime + allMachines[0].calculateIncrement();
    int currentTime, currentIncrement;
    // Then, for each task
    for (int i = 0; i < remainingTasks.size(); i++) {
      // And each machine
      for (int j = 0; j < allMachines.size(); j++) {
        // We calculate the increment on TCT for *task i -> machine j*
        currentTime = (prepCosts[allMachines[j].getLast()][remainingTasks[i]] +
                       taskCosts[remainingTasks[i] - 1]);
        currentIncrement = currentTime + allMachines[j].calculateIncrement();
        // If it's better, we select that one
        if (currentIncrement < minIncrement) {
          minTask = remainingTasks[i];
          minTime = currentTime;
          minMachine = j;
          minIncrement = currentIncrement;
        }
      }
    }
    // Then, we insert the best task in the best machine
    allMachines[minMachine].insertTask(std::make_pair(minTask, minTime));
    assigned(minTask);
  }
}

/*
 * Greedy algorithm for selecting each machine's assigned tasks
 * (same as greedy1. But instead of using TCT increments for calculations,
 * it uses the task prep + execution time only).
 */
void machines::greedy2() {
  resetRemainingVector();
  resetMachines();
  while (remainingTasks.size() != 0) {
    // First, we set minimum time, task and machine to
    //*task 0 -> machine 0*
    int minTask = remainingTasks[0];
    int minTime =
        prepCosts[0][remainingTasks[0]] + taskCosts[remainingTasks[0] - 1];
    int minMachine = 0;
    int currentTime;
    // Then, for each task
    for (int i = 0; i < remainingTasks.size(); i++) {
      // And each machine
      for (int j = 0; j < allMachines.size(); j++) {
        // We calculate the increment on TCT for *task i -> machine j*
        currentTime = (prepCosts[allMachines[j].getLast()][remainingTasks[i]] +
                       taskCosts[remainingTasks[i] - 1]);
        // If it's better, we select that one
        if (currentTime < minTime) {
          minTask = remainingTasks[i];
          minTime = currentTime;
          minMachine = j;
        }
      }
    }
    // Then, we insert the best task in the best machine
    allMachines[minMachine].insertTask(std::make_pair(minTask, minTime));
    assigned(minTask);
  }
}

/*
 * Main GRASP approach. First, it constructs a base solution from which
 * we will explore neighbors to find better ones.
 */
void machines::grasp(int lrcK, int operation, int search, int stopCondition,
                     int iterations) {
  switch (stopCondition) {
    case 1:
      for (int i = 0; i < iterations; i++) {
        graspConstruct(lrcK);
        graspImprove(operation, search);
      }
      break;
    case 2:
      int numWithoutBetter = 0;
      int bestTCT = 0;
      while (numWithoutBetter != iterations) {
        graspConstruct(lrcK);
        graspImprove(operation, search);
        if (bestTCT == 0)
          bestTCT = calculateTCT(allMachines);
        else if (calculateTCT(allMachines) > bestTCT)
          numWithoutBetter = 0;
        else
          numWithoutBetter++;
      }
      break;
  }
}

int machines::calculateTCT(std::vector<machine> solution) {
  int counter = 0;
  for (auto machine : solution) {
    machine.calculateTCT();
    counter += machine.getTCT();
  }
  return counter;
}

/*
 * For each machine, get *lrcNumber* best candidates and insert a random one
 * from the list
 */
void machines::graspConstruct(int lrcNumber) {
  std::vector<std::vector<int>> lrc;
  resetRemainingVector();
  resetMachines();
  while (remainingTasks.size() != 0) {
    for (int j = 0; j < allMachines.size(); j++) {
      if (remainingTasks.size() == 0) break;
      lrc = constructlrc(lrcNumber, j);
      int index = rand() % lrc.size();
      assigned(lrc[index][1]);
      allMachines[lrc[index][0]].insertTask(
          std::make_pair(lrc[index][1], lrc[index][2]));
    }
  }
}

/*
 * Constructs a set of *lrcNumber* tasks with best times to select from for
 * machine *machineIndex*
 */
std::vector<std::vector<int>> machines::constructlrc(int lrcNumber,
                                                     int machineIndex) {
  std::vector<std::vector<int>> lrc;
  std::vector<int> remainingAux = remainingTasks;
  int index = machineIndex;
  int currentcost;
  while (lrc.size() != lrcNumber) {
    // First, we set minimum TCT increment, task and machine to
    //*task 0 -> machine 0*
    int minTask = remainingAux[0];
    int minTime =
        prepCosts[allMachines[0].getLast()][remainingAux[0]] + taskCosts[remainingAux[0] - 1];
    int minMachine = 0;
    int minIncrement = minTime + allMachines[0].calculateIncrement();
    int currentTime, currentIncrement;
    // Then, for each task
    for (int i = 0; i < remainingAux.size(); i++) {
      // And each machine
      for (int j = 0; j < allMachines.size(); j++) {
        // We calculate the increment on TCT for *task i -> machine j*
        currentTime = (prepCosts[allMachines[j].getLast()][remainingAux[i]] +
                       taskCosts[remainingAux[i] - 1]);
        currentIncrement = currentTime + allMachines[j].calculateIncrement();
        // If it's better, we select that one
        if (currentIncrement < minIncrement) {
          minTask = remainingAux[i];
          minTime = currentTime;
          minMachine = j;
          minIncrement = currentIncrement;
        }
      }
    }
    lrc.push_back(std::vector<int>{minMachine, minTask, minTime});
    remainingAux.erase(
        std::remove(remainingAux.begin(), remainingAux.end(), minTask),
        remainingAux.end());
  }
  return lrc;
}

/*
 * Improves the results from Grasps, making a local exploration.
 * Using localSearchGrasp for it.
 */
void machines::graspImprove(int operation, int search) {
  localSearchGrasp.setMainSolution(allMachines);
  localSearchGrasp.exploreAndImprove(operation, search);
  allMachines = localSearchGrasp.getmainSolution();
}

/*
 * Resets all machines's to a base state: empty task vector and TCT = 0.
 */
void machines::resetMachines() {
  for (int i = 0; i < allMachines.size(); i++) {
    allMachines[i].clear();
  }
}

/*
 * Puts all tasks back into the remaining vector in
 * preparation for running another algorithm.
 */
void machines::resetRemainingVector() {
  remainingTasks.resize(taskCosts.size());
  std::iota(std::begin(remainingTasks), std::end(remainingTasks), 1);
}

/*
 * Erases the task from the remaining task.
 */
void machines::assigned(int task) {
  remainingTasks.erase(
      std::remove(remainingTasks.begin(), remainingTasks.end(), task),
      remainingTasks.end());
}

/*
 * Prints all machines' tasks and TCTs onto os.
 */
std::ostream& machines::showResults(std::ostream& os) {
  std::string tasks = "";
  int totalTCT = 0;
  for (int i = 0; i < allMachines.size(); i++) {
    if (allMachines[i].getTasks().size() != 0) {
      for (auto task : allMachines[i].getTasks()) {
        tasks += "(" + std::to_string(task.first) + ", " +
                 std::to_string(task.second) + "), ";
      }
      tasks.pop_back();
      tasks.pop_back();
      allMachines[i].calculateTCT();
      totalTCT += allMachines[i].getTCT();
      os << "Machine " << i + 1 << " (TCT: " << allMachines[i].getTCT() << ")"
         << std::endl;
      os << "Tasks: { " << tasks << " }" << std::endl << std::endl;
      tasks = "";
    }
  }
  std::cout << "Total TCT (Z): " << totalTCT << std::endl << std::endl;
  return os;
}

/*
 * VND algorithm. Explores in the following order of neighborhoods:
 * 1 (Intra Interchange)
 * 2 (Inter Interchange)
 * 3 (Intra Reinsertion)
 * 4 (Inter Reinsertion)
 * Needs an existing solution to start exploring.
 * In our case, we will use GRASP.
 */
void machines::VND(int search) {
  int operation = 1;
  bool brk = false;

  while (!brk) {
    auto beforeSolution = allMachines;
    int beforeTCT = calculateTCT(allMachines);
    graspImprove(operation, search);
    if (beforeTCT <= calculateTCT(allMachines)) {
      allMachines = beforeSolution;
      (operation < 4) ? operation++ : brk = true;
    } else {
      operation = 1;
    }
  }
}

/*
 * GVNS Algorithm. If we find a better solution, we start from k = 1 and explore
 * its neighbors. If not, we set k to k + 1 and explore again.
 */
void machines::GVNS(int search) {
  for (int i = 0; i < 20; i++) {
    grasp(3, 1, search, 1, 100);
    int k = 1;
    int maxK = calculateMaxK();

      auto lastSolution = allMachines;
      int lastTCT = calculateTCT(allMachines);

    while (k <= maxK) {
      //std::cout << "I: " << i << " K: " << k << std::endl;
      auto beforeSolution = allMachines;
      int beforeTCT = calculateTCT(allMachines);
      randomJumpInterchange(k);
      VND(search);
      if (beforeTCT > calculateTCT(allMachines)) {
        k = 1;
      } else {
        allMachines = beforeSolution;
        k++;
      }
    }
    if(calculateTCT(allMachines) > lastTCT) {
      allMachines = lastSolution;
    }
  }
}

void machines::randomJumpInterchange(int changes) {
  std::vector<std::set<int>> changesMade;
  changesMade.resize(allMachines.size());

  int machineIndex1 = rand() % allMachines.size();
  int machineIndex2 = rand() % allMachines.size();
  int taskIndex1, taskIndex2;

  for (int i = 0; i < changes; i++) {
    while (changesMade[machineIndex1].size() ==
           allMachines[machineIndex1].size()) {
      machineIndex1 = rand() % allMachines.size();
    }
    while ((changesMade[machineIndex2].size() ==
            allMachines[machineIndex2].size()) ||
           (machineIndex2 == machineIndex1)) {
      machineIndex2 = rand() % allMachines.size();
    }
    taskIndex1 = rand() % allMachines[machineIndex1].size();
    while (changesMade[machineIndex1].find(taskIndex1) !=
           changesMade[machineIndex1].end())
      taskIndex1 = rand() % allMachines[machineIndex1].size();

    taskIndex2 = rand() % allMachines[machineIndex2].size();
    while (changesMade[machineIndex2].find(taskIndex2) !=
           changesMade[machineIndex2].end())
      taskIndex2 = rand() % allMachines[machineIndex2].size();

    changesMade[machineIndex1].insert(taskIndex1);
    changesMade[machineIndex2].insert(taskIndex2);

    std::swap(allMachines[machineIndex1].getTasks()[taskIndex1],
              allMachines[machineIndex2].getTasks()[taskIndex2]);
              
    localSearchGrasp.recalculateTime(allMachines, machineIndex1, taskIndex1);
    localSearchGrasp.recalculateTime(allMachines, machineIndex2, taskIndex2);
  }
}

int machines::calculateMaxK() {
  int minMachine = allMachines[0].size();
  for (int i = 1; i < allMachines.size(); i++) {
    if (allMachines[i].size() < minMachine) minMachine = allMachines[i].size();
  }
  return (std::min(minMachine, 5));
}
#include <vector>
#include <math.h>
#include <algorithm>

typedef std::vector<float> point;
typedef std::vector<point> pointSpace;

class localSearch {
 private:
  pointSpace mainSolution;
  std::vector<pointSpace> neighborSolutions = {};
  pointSpace ogCoordinates;

  float getZ(pointSpace points);
  float getDist(point p1, point p2);

 public:
  localSearch() {}
  ~localSearch() {}
  inline void setCoordinates(pointSpace coords) {ogCoordinates = coords; }
  inline void setMainSolution(pointSpace mainSol) { mainSolution = mainSol; }
  inline pointSpace getmainSolution() { return mainSolution; }
  void genSolutions();
  pointSpace greedyExploration();
};


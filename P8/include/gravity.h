#pragma once

#include <math.h>
#include <iostream>
#include <vector>

#include "./localSearch.h"

typedef std::vector<float> point;
typedef std::vector<point> pointSpace;

class gravity {
 protected:
  pointSpace coordinates;
  localSearch ls;
  float getDist(point, point);
  point getCenter(pointSpace);
  std::vector<int> getBetterK(int, point, pointSpace);

 public:
  gravity() {}
  inline gravity(pointSpace nCoord) { coordinates = nCoord; }
  ~gravity() {}
  float getZ(pointSpace);

  virtual pointSpace run(int k) = 0;
  pointSpace neighborExplore(pointSpace);

  std::ostream& print(std::ostream&);
};
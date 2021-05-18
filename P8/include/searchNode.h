#pragma once

#include <vector>

typedef std::vector<float> point;
typedef std::vector<point> pointSpace;

class searchNode {
 private:
  pointSpace solution;
  float value;
  int level;

 public:
  searchNode(pointSpace newSol, float newValue, int newLevel)
      : solution(newSol), value(newValue), level(newLevel) {}
  searchNode() {}
  ~searchNode() {}

  int getLevel() const { return level; }
  pointSpace getSol() const { return solution; }

  void set(pointSpace newS, float newV, int newL) {
    solution = newS;
    value = newV;
    level = newL;
  }

  friend bool operator<(const searchNode& l, const searchNode& r) {
    if (l.value != r.value) return (l.value < r.value);
    if (l.level != r.level) return (l.level < r.level);
    float sum1 = 0, sum2 = 0;
    for (auto it : l.solution) {
      for (auto p : it) {
        sum1 += p;
      }
    }
    for (auto it : r.solution) {
      for (auto p : it) {
        sum2 += p;
      }
    }
    return sum1 < sum2;
  }
};
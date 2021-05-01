#include <iostream>
#include <vector>

class gravity {
 protected:
  std::vector<std::vector<float>> coordinates;
  // objeto de tipo local search?
  float getDist(int, int);
  int getCenter();
  std::vector<int> getBetterK(int);

 public:
  gravity() {}
  inline gravity(std::vector<std::vector<float>> nCoord) { coordinates = nCoord; }
  ~gravity() {}

  virtual void run();
  std::ostream& print(std::ostream&);
};
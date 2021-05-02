#include "gravity.h"

class gravityGreedy: public gravity
{
private:
  
public:
  gravityGreedy(std::vector<std::vector<float>> nCoord):gravity(nCoord) {}
  ~gravityGreedy() {}
  void run();
};
#include "../include/gravity.h"

std::ostream& gravity::print(std::ostream& os) {
  for(auto it: coordinates) {
    for(auto coord: it) {
      os << coord << " ";
    }
    os << std::endl;
  }
  return os;
}
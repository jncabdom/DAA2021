#include "../include/Memory.h"

void Memory::storeVal(int n, int pos) { 
  if(pos >= registerArray.size()) {
    registerArray.resize(pos + 1);
  }
  registerArray[pos] = n; 
}
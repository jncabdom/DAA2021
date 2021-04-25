#include "../include/machine.h"

void machine::calculateTCT() {
  TCT = 0;
  for(int i = 0; i < tasks.size(); i++) {
    TCT += tasks[i].second * (tasks.size() - i);
  }
}

int machine::calculateIncrement() {
  int increment = 0;
  for(int i = 0; i < tasks.size(); i++) {
    increment += tasks[i].second;
  }
  return increment;
}

void machine::clear() {
  TCT = 0;
  tasks.clear();
}
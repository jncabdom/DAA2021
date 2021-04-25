#pragma once

#include "../include/Instruction.h"

class LoadInstruction : public Instruction {
 private:
  int data;

 public:
  LoadInstruction() {}
  LoadInstruction(std::string text) { parse(text); }
  ~LoadInstruction() {}
  void parse(std::string);
  std::ostream& print(std::ostream&, bool) const;
  void execute(ctx&);
};
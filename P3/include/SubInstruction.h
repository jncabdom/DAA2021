#pragma once

#include "../include/Instruction.h"

class SubInstruction : public Instruction {
 private:
  int data;

 public:
  SubInstruction() {}
  SubInstruction(std::string text) { parse(text); }
  virtual ~SubInstruction() {}
  void parse(std::string);
  std::ostream& print(std::ostream&, bool) const;
  void execute(ctx&);
};
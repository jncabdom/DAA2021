#pragma once

#include "../include/Instruction.h"

class DivInstruction : public Instruction {
 private:
  int data;

 public:
  DivInstruction() {}
  DivInstruction(std::string text) { parse(text); }
  virtual ~DivInstruction() {}
  void parse(std::string);
  std::ostream& print(std::ostream&, bool) const;
  void execute(ctx&);
};
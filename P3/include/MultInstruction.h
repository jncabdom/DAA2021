#pragma once

#include "../include/Instruction.h"

class MultInstruction : public Instruction {
 private:
  int data;

 public:
  MultInstruction() {}
  MultInstruction(std::string text) { parse(text); }
  virtual ~MultInstruction() {}
  void parse(std::string);
  std::ostream& print(std::ostream&, bool) const;
  void execute(ctx&);
};
#pragma once

#include "../include/Instruction.h"

class AddInstruction : public Instruction {
 private:
  int data;

 public:
  AddInstruction() {}
  AddInstruction(std::string text) { parse(text); }
  virtual ~AddInstruction() {}
  void parse(std::string);
  std::ostream& print(std::ostream&, bool) const;
  void execute(ctx&);
};
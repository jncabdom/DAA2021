#pragma once

#include "../include/Instruction.h"

class WriteInstruction : public Instruction {
 private:
  int data;

 public:
  WriteInstruction() {}
  WriteInstruction(std::string text) { parse(text); }
  virtual ~WriteInstruction() {}
  void parse(std::string);
  std::ostream& print(std::ostream&, bool) const;
  void execute(ctx&);
};
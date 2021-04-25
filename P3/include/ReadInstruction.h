#pragma once

#include "../include/Instruction.h"

class ReadInstruction : public Instruction {
 private:
  int data;

 public:
  ReadInstruction() {}
  ReadInstruction(std::string text) { parse(text); }
  virtual ~ReadInstruction() {}
  void parse(std::string);
  std::ostream& print(std::ostream&, bool) const;
  void execute(ctx&);
};
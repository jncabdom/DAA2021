#pragma once

#include "../include/Instruction.h"

class JZEROInstruction : public Instruction {
 private:
  std::string data;

 public:
  JZEROInstruction() {}
  JZEROInstruction(std::string text) { parse(text); }
  virtual ~JZEROInstruction() {}
  void parse(std::string);
  std::ostream& print(std::ostream&, bool) const;
  void execute(ctx&);
};
#pragma once

#include "../include/Instruction.h"

class HaltInstruction : public Instruction {
 public:
  HaltInstruction() {}
  HaltInstruction(std::string text) { parse(text); }
  virtual ~HaltInstruction() {}
  void parse(std::string);
  std::ostream& print(std::ostream&, bool) const;
  void execute(ctx&);
};
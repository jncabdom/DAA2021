#pragma once

#include "../include/Instruction.h"

class JumpInstruction : public Instruction {
 private:
  std::string data;

 public:
  JumpInstruction() {}
  JumpInstruction(std::string text) { parse(text); }
  virtual ~JumpInstruction() {}
  void parse(std::string);
  std::ostream& print(std::ostream&, bool) const;
  void execute(ctx&);
};
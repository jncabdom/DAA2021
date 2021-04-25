#pragma once

#include "../include/Instruction.h"

class JGTZInstruction : public Instruction {
 private:
  std::string data;

 public:
  JGTZInstruction() {}
  JGTZInstruction(std::string text) { parse(text); }
  virtual ~JGTZInstruction() {}
  void parse(std::string);
  std::ostream& print(std::ostream&, bool) const;
  void execute(ctx&);
};
#pragma once

#include "../include/Instruction.h"

class StoreInstruction : public Instruction {
 private:
  int data;

 public:
  StoreInstruction() {}
  StoreInstruction(std::string text) { parse(text); }
  virtual ~StoreInstruction() {}
  void parse(std::string);
  std::ostream& print(std::ostream&, bool) const;
  void execute(ctx&);
};
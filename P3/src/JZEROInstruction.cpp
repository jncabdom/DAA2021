#include "../include/JZEROInstruction.h"

void JZEROInstruction::parse(std::string text) {
  std::istringstream ss(text);
  ss >> opcode >> data;
}

std::ostream& JZEROInstruction::print(std::ostream& os, bool disassembly) const {
  if (disassembly) {
    os << "OPCODE = " << opcode;
    os << " OPERANDO = " << data;
  } else {
    os << opcode << " " << data;
  }
  return os;
}

void JZEROInstruction::execute(ctx& context) {
  if(context.mem->getVal(0) == 0)
    *context.pc = context.tags.find(data)->second;
  else *context.pc+= 1;
}
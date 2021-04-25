#include "../include/JGTZInstruction.h"

void JGTZInstruction::parse(std::string text) {
  std::istringstream ss(text);
  ss >> opcode >> data;
}

std::ostream& JGTZInstruction::print(std::ostream& os, bool disassembly) const {
  if (disassembly) {
    os << "OPCODE = " << opcode;
    os << " OPERANDO = " << data;
  } else {
    os << opcode << " " << data;
  }
  return os;
}

void JGTZInstruction::execute(ctx& context) {
  if(context.mem->getVal(0) > 0)
    *context.pc = context.tags.find(data)->second;
  else *context.pc+= 1;
}
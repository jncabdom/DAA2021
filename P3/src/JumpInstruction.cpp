#include "../include/JumpInstruction.h"

void JumpInstruction::parse(std::string text) {
  std::istringstream ss(text);
  ss >> opcode >> data;
}

std::ostream& JumpInstruction::print(std::ostream& os, bool disassembly) const {
  if (disassembly) {
    os << "OPCODE = " << opcode;
    os << " OPERANDO = " << data;
  } else {
    os << opcode << " " << data;
  }
  return os;
}

void JumpInstruction::execute(ctx& context) {
  *context.pc = context.tags.find(data)->second;
}
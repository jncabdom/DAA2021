#include "../include/HaltInstruction.h"

void HaltInstruction::parse(std::string text) {
  std::istringstream ss(text);
  std::string aux;
  ss >> opcode;
}

std::ostream& HaltInstruction::print(std::ostream& os, bool disassembly) const {
  if (disassembly) {
    os << "OPCODE = " << opcode;
  }
  return os;
}

void HaltInstruction::execute(ctx& context) {
throw('x');
}
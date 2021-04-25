#include "../include/ReadInstruction.h"

void ReadInstruction::parse(std::string text) {
  std::istringstream ss(text);
  std::string aux;
  ss >> opcode >> aux;
  if (aux[0] == '=') {  // error
  }
  if (aux[0] == '*') {
    direct = indir;
    data = stoi(aux.substr(1));
  } else {
    data = stoi(aux);
    direct = dir;
  }
}

std::ostream& ReadInstruction::print(std::ostream& os, bool disassembly) const {
  if (disassembly) {
    os << "OPCODE = " << opcode << ", DIRECCIONAMIENTO = ";
    if (direct == imm) {
      os << " INMEDIATO,";
    } else if (direct == indir) {
      os << "INDIRECTO,";
    } else
      os << "DIRECTO,";
    os << " OPERANDO = " << data;
  } else {
    os << opcode << " " << data;
  }
  return os;
}

void ReadInstruction::execute(ctx& context) {
  switch (direct) {
    case dir:
      context.mem->storeVal(context.it->read(), data);
      break;
    case indir:
      context.mem->storeVal(context.it->read(), context.mem->getVal(data));
      break;
  }
  *context.pc+= 1;
}
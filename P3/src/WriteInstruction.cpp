#include "../include/WriteInstruction.h"

void WriteInstruction::parse(std::string text) {
  std::istringstream ss(text);
  std::string aux;
  ss >> opcode >> aux;
  if ((aux[0] == '=') || (aux[0] == '*')) {
    direct = (aux[0] == '=') ? imm : indir;
    data = stoi(aux.substr(1));
  } else {
    data = stoi(aux);
    direct = dir;
  }
}

std::ostream& WriteInstruction::print(std::ostream& os,
                                      bool disassembly) const {
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

void WriteInstruction::execute(ctx& context) {
  switch (direct) {
    case imm:
      context.ot->write(data);
      break;
    case dir:
      context.ot->write(context.mem->getVal(data));
      break;
    case indir:
      context.ot->write(context.mem->getVal(context.mem->getVal(data)));
      break;
  }
  *context.pc+= 1;
}
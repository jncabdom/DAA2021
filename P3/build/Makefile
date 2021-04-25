IDIR =../include
CXX=g++ -g -std=c++11 -o RAM
CFLAGS=-I$(IDIR) 

ODIR=../src

LIBS=-lm

_OBJ = AddInstruction.o Cpu.o DivInstruction.o HaltInstruction.o InputTape.o JGTZInstruction.o JumpInstruction.o JZEROInstruction.o LoadInstruction.o main.o Memory.o MultInstruction.o OutputTape.o Program.o ProgramParser.o ReadInstruction.o StoreInstruction.o SubInstruction.o Tape.o WriteInstruction.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: RAM
RAM: ${OBJ} 
		$(CXX) $(CXXFLAGS) ${OBJ} 

.PHONY: clean

clean:
		rm -f $(ODIR)/*.o *~ $(INCDIR)/*~
IDIR =../include
CXX=g++ -g -std=c++11 -o LCS
CFLAGS=-I$(IDIR) 

ODIR=../src

LIBS=-lm

_OBJ = main.o LCS.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: main
main: ${OBJ} 
		$(CXX) $(CXXFLAGS) ${OBJ} 

.PHONY: clean

clean:
		rm -f $(ODIR)/*.o *~ $(INCDIR)/*~

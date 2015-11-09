CXX=g++
CXXFLAGS= -Wall 
LD=g++
LDFLAGS= 
LIB=

all: prog.x

prog.x: prog.o MonteCarlo.o LCGenerator.o DumbGenerator.o
	$(LD) $(LDFLAGS) $^ $(LIB)  -o $@

prog.o : prog.cpp MonteCarlo.h  Generator.h LCGenerator.h DumbGenerator.h
	$(CXX) $(CXXFLAGS) -c $<

%.o : %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.x *.o

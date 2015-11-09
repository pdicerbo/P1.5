CXX=g++
CXXFLAGS= -Wall -DUSEBLAS 
LD=g++
LDFLAGS= 
LIB= -lblas

all: prog.x

prog.x: prog.o 
	$(LD) $(LDFLAGS) $^ $(LIB)  -o $@

prog.o : prog.cpp matrix.h MyBoostMatrix.h 
	$(CXX) $(CXXFLAGS) -c $<

%.o : %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.x *.o

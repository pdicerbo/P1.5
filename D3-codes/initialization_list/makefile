CXX=g++
CXXFLAGS=
LD=g++
LDFLAGS=

all: prog.x

prog.x: prog.o rectangle.o square.o  
	$(LD) $(LDFLAGS) $^ -o $@

prog.o: prog.cpp rectangle.h square.h
	$(CXX) $(CXXFLAGS) -c $<

%.o : %.cpp %.h 
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.x *.o

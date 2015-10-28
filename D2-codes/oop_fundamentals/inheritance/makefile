CXX=g++
CXXFLAGS=
LD=g++
LDFLAGS=

all: prog2.x

prog2.x: prog2.o rectangle.o square.o
	$(LD) $(LDFLAGS) $^ -o $@

prog2.o: prog2.cpp rectangle.h square.h
	$(CXX) $(CXXFLAGS) -c $<

%.o : %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.x *.o

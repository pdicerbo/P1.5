CXX=g++
CXXFLAGS=
LD=g++
LDFLAGS=

all: prog1.x

prog1.x: prog1.o myvector.o
	$(LD) $(LDFLAGS) $^ -o $@

prog1.o: prog1.cpp myvector.h
	$(CXX) $(CXXFLAGS) -c $<

%.o : %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.x *.o

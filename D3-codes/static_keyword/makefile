CXX=g++
CXXFLAGS=
LD=g++
LDFLAGS=

all: prog.x

prog.x: prog.o myclass.o
	$(LD) $(LDFLAGS) $^ -o $@

prog.o: prog.cpp myclass.h
	$(CXX) $(CXXFLAGS) -c $<

%.o : %.cpp %.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.x *.o

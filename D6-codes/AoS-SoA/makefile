CXX=g++ #icpc
CXXFLAGS= -O3  
LIBS= 

all: testAoS.x testSoA.x

%.x : %.o
	$(CXX) $^ $(LIBS) -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o *.x

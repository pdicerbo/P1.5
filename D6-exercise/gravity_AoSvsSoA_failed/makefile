CXX=g++
CXXFLAGS= -O3  #-DDEBUG 
LIBS= 

all: gravity_AoS.x gravity_SoA.x

gravity_AoS.x : gravity_AoS.o
	$(CXX) $^ $(LIBS) -o $@

gravity_SoA.x : gravity_SoA.o
	$(CXX) $^ $(LIBS) -o $@


%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm *.o *.x

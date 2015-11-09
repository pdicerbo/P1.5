CC=g++
CFLAGS=-Wall
LIBS=-lcblas

all=prog.x

prog.x: prog.o MyMatrix.o MySquareMatrix.o FactoryMatrix.o
	$(CC) $^ $(LIBS) -o $@

prog.o: prog.cpp
	$(CC) -c $<

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.x *.o

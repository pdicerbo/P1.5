CC=g++
CFLAGS=-Wall -DUSEBLAS #-DDEBUG
LIBS=-lblas -llapacke
DOT_O = prog.o MyMatrix.o MySquareMatrix.o rvector.o lvector.o

all=prog.x

prog.x: ${DOT_O}
	$(CC) $^ $(LIBS) -o $@

prog.o: prog.cpp
	$(CC) -c $<

%.o: %.cpp %.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.x *.o

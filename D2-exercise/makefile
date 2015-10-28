CC=g++

all=prog.x

prog.x: prog.o MyMatrix.o
	$(CC) $^ -o $@

prog.o: prog.cpp MyMatrix.h
	$(CC) -c $<

%.o: %.cpp %.h
	$(CC) -c $<

clean:
	rm -f *.x *.o

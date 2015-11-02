CC=g++
CFLAGS=-c

all: LibCell.o ConcCell.o test.o
	$(CC) LibCell.o ConcCell.o test.o -o test
LibCell.o: LibCell.cpp
	$(CC) $(CFLAGS) LibCell.cpp
ConcCell.o: ConcCell.cpp
	$(CC) $(CFLAGS) ConcCell.cpp
test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp
clean:
	rm *.o
	rm *.gch
	rm test
	rm *~

CC=g++

main: MyAllocator MyAllocator.o
	$(CC) -o MyAllocator.o

test: MyAllocator.o test.o
	$(CC) -o Test test.o MyAllocator.o

MyAllocator.o: MyAllocator.cpp MyAllocator.hpp
	$(CC) -std=c++14 -c MyAllocator.cpp

test.o: test.cpp test.hpp
	$(CC) -std=c++14 -c test.cpp

clean:
	rm -rf *.o MyAllocator Test


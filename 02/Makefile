CC=g++

run:  test

test: MyAllocator.o test.o
	$(CC) -o Test test.o MyAllocator.o

MyAllocator.o: MyAllocator.cpp 
	$(CC) -std=c++14 -c MyAllocator.cpp 

test.o: test.cpp MyAllocator.hpp
	$(CC) -std=c++14 -c test.cpp

clean:
	rm -rf *.o MyAllocator Test


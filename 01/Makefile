CC=g++
all: my_prog

run: ./my_calc
	./my_calc "2+2"

test: calc.o tests.o
	$(CC) -o test_prog tests.o calc.o
	./test_prog

main.o: main.cpp calc.hpp
	$(CC) -std=c++11 -c main.cpp

calc.o: calc.cpp calc.hpp
	$(CC) -std=c++11 -c calc.cpp

tests.o: tests.cpp tests.hpp
	$(CC) -std=c++11 -c tests.cpp

my_prog: main.o calc.o
	$(CC) -o my_calc main.o calc.o

clean: 
	rm -rf *.o my_calc test_prog

CC=g++
CFLAGS=-fprofile-arcs -ftest-coverage
OS=$(shell uname -s)

all: clean matrix_oop.a test

matrix_oop.a: matrix_oop.o
	ar rcs matrix_oop.a matrix_oop.o
	cp matrix_oop.a libs_matrix_oop.a
	ranlib libs_matrix_oop.a

matrix_oop.o: matrix_oop.cpp
	$(CC) -c matrix_oop.cpp -o matrix_oop.o

test: matrix_oop.a
ifeq ($(OS), Darwin)
	$(CC) test.cpp matrix_oop.cpp -o test -lgtest --coverage -pthread
	./test
else
	$(CC) test.cpp matrix_oop.cpp -o test -lgtest -pthread
	./test
endif

clean:
	rm -rf *.gc* *.o *.a *.out *.info test matrix_oop

rebuild: clean all

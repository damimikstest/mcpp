program: header.hpp vector.o main.o
	g++ main.o vector.o -o main
vector: header.hpp vector.cpp
	g++ -c vector.cpp -o vector.o
main: header.hpp vector.cpp
	g++ -c main.cpp -o main.o
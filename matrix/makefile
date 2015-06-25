app: header.hpp vector.o matrix.o out.o
	g++ out.o matrix.o vector.o -o app
vector: header.hpp vector.cpp
	g++ -c vector.cpp -o vector.o
matrix: header.hpp matrix.cpp
	g++ -c matrix.cpp -o matrix.o
out: header.hpp out.cpp
	g++ -c out.cpp -o out.o
clean:
	rm *.o
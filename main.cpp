#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "colours.h"


#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

/* --------------- HEADER.HPP ------------ */

using namespace std;

class Vector{
	int dim;
	int *fields;
public:
	Vector(int d = 2);
	Vector(const Vector &ref);
	~Vector();
	
	/* Overloaded equality operator   
	   It simply rewrite values from right 
	   operand (ref) to left operand (this object) */
	void operator=(const Vector &ref);
	/* Stream operators overloading */
	friend ostream& operator<<(ostream& os, const Vector &ref);
	friend istream& operator>>(istream& is, Vector &ref);
	int &operator[](unsigned int index);
	/* Overloaded arithmetic operator */
	Vector operator+(const Vector &ref);
	Vector operator-(const Vector &ref);
	Vector operator*(int scalar);
	void operator+=(const Vector &ref);
	void operator-=(const Vector &ref);
	void operator*=(int scalar);
	bool operator==(const Vector &ref);
	bool operator!=(const Vector &ref);

};

/* --------------- END OF HEADER.HPP ------------ */

/* --------------- VECTOR.CPP ------------ */

/* Constructor definitions */
/* Default constructor */
Vector::Vector(int d){ 
	dim = d;
	fields = new int[d];
	for(int i = 0; i < dim; i++) fields[i] = 0;
}
/* Copy constructor */
Vector::Vector(const Vector &ref){
	dim = ref.dim;
	fields = new int[dim];
	for (int i = 0; i < dim; ++i){ fields[i] = ref.fields[i];}
}
/* Destructor */
Vector::~Vector(){
	delete fields;
	cout << FG_DARK_GRAY << "(object deleted)" << RST << endl;
}

/* Overloaded assignment operator */
void Vector::operator=(const Vector &ref){
	dim = ref.dim;
	fields = new int[dim];
	for (int i = 0; i < dim; ++i){ fields[i] = ref.fields[i];}
}

/* Overloaded out stream operator */ 
ostream& operator<<(ostream& os, const Vector &ref){
	cout << KGRN << "(";
	for(int i = 0; i < ref.dim; i++)
	{
		os << ref.fields[i];
		if(i == (ref.dim - 1)) break;
		os << ", ";
	}
	os << ")" << RST << endl;
	return os;
}

/* Overloaded in stream operator */
istream& operator>>(istream& is, Vector &ref){
	// cout << "Wpisz tekst" << endl;
	bool again = FALSE;
	do{
		//cout << "jestem w do:" << endl;
		again = FALSE;
		cout.flush(); // synchronize output with stream
		for(int i = 0; i < ref.dim; i++){
			is >> ws; // ignore whitespaces
			int x = is.peek(); // get an value without extracting it
			if(isdigit(x))
			{
				int n;
				is >> n;
				//cout << "Wpisałeś liczbę: " << n << endl;
				ref.fields[i] = n;
			}
			else
			{
				is.ignore(); // this line protect from errors
				again = TRUE;
				cout << "Wrong data input, try again!" << endl;
				break;
			}
			//cout << endl;
		}
	} while(again);
	char rest = '1';
	do{
		rest = is.get();
	}while(rest != '\n');
	cout << FG_DARK_GRAY << "buffer clean!" << RST << endl;
	return is;
}

/* Overloaded index operator */
int &Vector::operator[](unsigned int index){
	if(index >= 0 and index < dim) return fields[index];
	else fields[0];
}

/* Overloaded arithmetic operators */
/* Operator + */
Vector Vector::operator+(const Vector &ref){
	int dimen = dim;
	if(ref.dim > dimen) dimen = ref.dim;
	Vector *result = new Vector(dimen);
	for(int i = 0; i < dimen; i++){
		int nfv = 0;
		if(dim > i) {nfv += fields[i];}
		if(ref.dim > i) {nfv += ref.fields[i];}
		result->fields[i] = nfv;
	}
	return *result;
}


/* Operator - */
Vector Vector::operator-(const Vector &ref){
	int dimen = dim;
	if(ref.dim > dimen) dimen = ref.dim;
	Vector *result = new Vector(dimen);
	for(int i = 0; i < dimen; i++){
		int nfv = 0;
		if(dim > i) {nfv = fields[i];}
		if(ref.dim > i) {nfv -= ref.fields[i];}
		result->fields[i] = nfv;
	}
	return *result;
}
/* Operator * */
Vector Vector::operator*(int scalar){
	/* NOTICE that the left operant must be of type Vector and right operand of type int */
	Vector *allocation = new Vector((*this));
	for(int i = 0; i < dim; i++) allocation->fields[i] = fields[i] * scalar;
	return *allocation;
}

/* Add a vector */
void Vector::operator+=(const Vector &ref){
	(*this) = (*this) + ref;
}
/* Substract a vector */
void Vector::operator-=(const Vector &ref){
	(*this) = (*this) - ref;
}
void Vector::operator*=(int scalar){
	(*this) = (*this) * scalar;
}



/* Overloaded logic operators */
/* Comparison - Is equal */
bool Vector::operator==(const Vector &ref){
	if(dim == ref.dim){
		for(int i = 0; i < dim; i++){
			if(fields[i] != ref.fields[i]) return FALSE;
		}
		return TRUE;
	} else return FALSE;
}
/* Difference - Is not equal */
bool Vector::operator!=(const Vector &ref){
	return !((*this) == ref);
}


/* --------------- END OF VECTOR.CPP ------------ */

/* ----------------- HEADER.HPP ----------------- */

class Matrix
	: public Vector	
{
	int rows;
	Vector *vectors;
public:
	Matrix(int r = 2, int d = 2);
	Matrix(const Matrix &ref);
	~Matrix();
	
	/* Overloaded equality operator   
	   It simply rewrite values from right 
	   operand (ref) to left operand (this object) */
	void operator=(const Matrix &ref);
	/* Stream operators overloading */
	friend ostream& operator<<(ostream& os, const Matrix &ref);
	friend istream& operator>>(istream& is, Matrix &ref);
	int &operator[](unsigned int index);
	/* Overloaded arithmetic operator */
	Matrix operator+(const Matrix &ref);
	Matrix operator-(const Matrix &ref);
	Matrix operator*(int scalar);
	void operator+=(const Matrix &ref);
	void operator-=(const Matrix &ref);
	void operator*=(int scalar);
	bool operator==(const Matrix &ref);
	bool operator!=(const Matrix &ref);	
};

/* ------------- END OF HEADER.HPP -------------- */

/* ----------------- MATRIX.CPP ----------------- */

Matrix::Matrix(int r, int d){
	rows = r;
	vectors = new Vector[r];
}
Matrix::Matrix(const Matrix &ref){
	rows = ref.rows;
	vectors = new Vector[rows];
	for (int i = 0; i < rows; ++i) vectors[i] = ref.vectors[i];
}
Matrix::~Matrix(){
	delete vectors;
	cout << FG_DARK_GRAY << "(matrix deleted)" << RST << endl;
}
/* Overloaded assignment operator */
void Matrix::operator=(const Matrix &ref){
	rows = ref.rows;
	vectors = new Vector[rows];
	for (int i = 0; i < rows; ++i) vectors[i] = ref.vectors[i];
}

/* ------------- END OF MATRIX.CPP -------------- */

/* ----------- MAIN.CPP - PROGRAM CODE ---------- */

int main()
{
	int mem = 2;
	Vector a(4);
	Vector b(4);
	system("clear");
	cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
	cout << "Type the coords values:" << endl;
	cin >> a;
	cin >> b;
	cout << "Loaded vectors are:" << endl;
	cout << "Vector A: " << a;
	cout << "Vector B: " << b;
	/* Test of arithmetic operations */
	cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
	cout << "Arithmetic operations test:" << endl;
	cout << "Addition:" << endl << a << "+"
	<< endl << b << "=" << endl << (a + b) << endl;
	cout << "Substraction:" << endl << a << "-"
	<< endl << b << "=" << endl << (a - b) << endl;
	a += b;
	cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
	cout << "Addition with assignment: a += b" << endl << a << endl;
	b -= a;
	cout << "Substraction with assignment: b -= a" << endl << b << endl;
	cout << "Logic operations test:" << endl;
	cout << "A equal to B:      " << (a == b) << endl;
	cout << "A not equal to B:  " << (a != b) << endl << endl;
	cout << "Assignment:" << endl;
	a = b;
	cout << "We made vector a = b:" << endl;
	cout << a;
	cout << b;
	cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
	cout << "Type the dimension of new Vector:" << endl;
	cin >> mem;
	Vector *nv = new Vector(mem);
	Vector &c = *nv;
	cout << "Type the coords values:" << endl;
	cin >> c;
	cout << "Loaded vector is:" << endl;
	cout << c;
	cout << "Coord with index [1] has value: " << c[1] << endl << endl;
	/* Multiplication by scalar */
	cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
	cout << "Type a scalar:" << endl;
	cin >> mem;
	cout << "c * scalar = " << c * mem << endl;
	c *= mem;
	cout << "Again using same variable: c *= scalar" 
	<< endl << "c values are: " << c << endl;
	/* c object have been dynamically allocated
	in this block so I decided to delete it manually, because before the end of
	block main function returns 0 and only after that the block is ending. 
	So I cannot be sure that the memory will be released. */
	delete nv; 
	/* Everything is now fine. Output display information that 3 objects have been deleted. */
	return 0;
}
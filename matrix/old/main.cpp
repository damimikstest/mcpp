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
	int retdim();
	void input(int col, int value);

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
	cout << FG_DARK_GRAY << "(vector deleted)" << RST << endl;
}

/* Overloaded assignment operator */
void Vector::operator=(const Vector &ref){
	dim = ref.dim;
	fields = new int[dim];
	for (int i = 0; i < dim; ++i){ fields[i] = ref.fields[i];}
}

/* Overloaded out stream operator */ 
ostream& operator<<(ostream& os, const Vector &ref){
	cout << KGRN << "┃";
	for(int i = 0; i < ref.dim; i++)
	{
		os << ref.fields[i] << "\t";
		// if(i == (ref.dim - 1)) break;
		// os << ", ";
	}
	os << "┃" << RST << endl;
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
 /* dim return */
int Vector::retdim() {
	return dim;
}
/*  */
void Vector::input(int col, int value){
	if(col >= 0 and col < dim) {fields[col] = value;}
}

/* --------------- END OF VECTOR.CPP ------------ */

/* ----------------- HEADER.HPP ----------------- */

class Matrix
	: public Vector	
{
	int rows;
	Vector *vectors;
public:
	Matrix(int r = 2, int di = 2);
	Matrix(const Matrix &ref);
	~Matrix();
	
	/* Overloaded equality operator   
	   It simply rewrite values from right 
	   operand (ref) to left operand (this object) */
	void operator=(const Matrix &ref);
	/* Stream operators overloading */
	friend ostream& operator<<(ostream& os, const Matrix &ref);
	friend istream& operator>>(istream& is, Matrix &ref);
	Vector &operator[](unsigned int index);
	/* Overloaded arithmetic operator */
	Matrix operator+(Matrix &ref);
	Matrix operator-(Matrix &ref);
	Matrix operator*(Matrix &ref);
	Matrix operator*(int scalar);
	void operator+=(Matrix &ref);
	void operator-=(Matrix &ref);
	void operator*=(Matrix &ref);
	void operator*=(int scalar);
	bool operator==(const Matrix &ref);
	bool operator!=(const Matrix &ref);
	int retrows();
	int retdim();
	void input(int row, int col, int value);

};

/* ------------- END OF HEADER.HPP -------------- */

/* ----------------- MATRIX.CPP ----------------- */

Matrix::Matrix(int r, int di){
	rows = r;
	vectors = new Vector[r];
	for (int i = 0; i < r; ++i){ vectors[i] = *(new Vector(di)); }
}
Matrix::Matrix(const Matrix &ref){
	rows = ref.rows;
	vectors = new Vector[rows];
	for (int i = 0; i < rows; ++i) vectors[i] = ref.vectors[i];
}
Matrix::~Matrix(){
	cout << FG_DARK_GRAY << "(matrix deleted)" << RST << endl;
}
/* Overloaded assignment operator */
void Matrix::operator=(const Matrix &ref){
	rows = ref.rows;
	vectors = new Vector[rows];
	for (int i = 0; i < rows; ++i) vectors[i] = ref.vectors[i];
}
/* Overloaded out stream operator */
ostream& operator<<(ostream& os, const Matrix &ref){
	cout << endl << KGRN << "┏";
	for (int i = 0; i < (ref.vectors[0].retdim()); ++i) cout << "\t";
	cout << "┓" << endl;
	for(int i = 0; i < ref.rows; i++)
	{
		os << ref.vectors[i];
	}
	cout << KGRN << "┗";
	for (int i = 0; i < (ref.vectors[0].retdim()); ++i) cout << "\t";
	cout << "┛";
	os << RST << endl;
	return os;
}
/* Overloaded in stream operator */
istream& operator>>(istream& is, Matrix &ref){
	for (int i = 0; i < ref.rows; ++i) is >> ref.vectors[i];
	return is;
}
/* Overloaded index operator */
Vector &Matrix::operator[](unsigned int index){
	/* NOTICE: First [] point to row and second point to column for instance: M[row][col] */
	if(index >= 0 and index < rows) return vectors[index];
	else return vectors[0];
}
/* Overloaded arithmetic operators */
/* Operator + */
Matrix Matrix::operator+(Matrix &ref){
	int resrows = ref.rows;
	if(ref.rows > resrows) resrows = ref.rows;
	int cols = retdim();
	if((ref.retdim()) > cols) {cols = ref.retdim();}
	Matrix *result = new Matrix(resrows);
	for(int i = 0; i < resrows; i++){
		Vector nvv(cols);
		if(rows > i) {nvv += vectors[i];}
		if(ref.rows > i) {nvv += ref.vectors[i];}
		result->vectors[i] = nvv;
	}
	return *result;
}
/* Operator - */
Matrix Matrix::operator-(Matrix &ref){
	int resrows = ref.rows;
	if(ref.rows > resrows) resrows = ref.rows;
	int cols = retdim();
	if((ref.retdim()) > cols) {cols = ref.retdim();}
	Matrix *result = new Matrix(resrows);
	for(int i = 0; i < resrows; i++){
		Vector nvv(cols);
		if(rows > i) {nvv += vectors[i];}
		if(ref.rows > i) {nvv -= ref.vectors[i];}
		result->vectors[i] = nvv;
	}
	return *result;
}
/* Operator * */
Matrix Matrix::operator*(Matrix &ref){
	Matrix *M = new Matrix((*this).rows, ref.retdim());
	if(retdim() == ref.rows){
		cout << "Matrices sizes passes!" << endl;
		for(int i = 0; i < rows; i++){
			for(int c = 0; c < ref.retdim(); c++){
				int input = 0;
				for (int a = 0; a < retdim(); ++a)
				{
					input += (*this)[i][a] * ref[a][c];
				}
				M->input(c, i, input);
			}
			cout << endl;
		}
	}else cout << "Matrices sizes not passes!" << endl;
	return *M;
}
/* Operator * scalar */
Matrix Matrix::operator*(int scalar){
	/* NOTICE that the left operant must be of type Matrix and right operand of type int */
	Matrix *res = new Matrix((*this));
	for(int i = 0; i < rows; i++) res->vectors[i] = vectors[i] * scalar;
	return *res;
}


/* Add a matrix */
void Matrix::operator+=(Matrix &ref){
	(*this) = (*this) + ref;
}
/* Substract a matrix */
void Matrix::operator-=(Matrix &ref){
	(*this) = (*this) - ref;
}
/* Multiplicate by matrix */
void Matrix::operator*=(Matrix &ref){
	(*this) = (*this) * ref;
}
/* Multiplicate by scalar */
void Matrix::operator*=(int scalar){
	(*this) = (*this) * scalar;
}


int Matrix::retrows(){
	return rows;
}
int Matrix::retdim(){
	return vectors[0].retdim();
}
void Matrix::input(int row, int col, int value){
	if(row >= 0 and row < rows) vectors[row].input(col, value);
}

/* ------------- END OF MATRIX.CPP -------------- */

/* ----------- MAIN.CPP - PROGRAM CODE ---------- */

int main()
{
	int option = 1;
	system("clear");
	cout << "What do you want to test?" << endl << "(1) vectors" << endl 
	<< "(2) matrices" << endl
	<< "(3) matrices test" << endl;
	cin >> option;
	if(option == 1){
		int mem = 2;
		Vector a(4);
		Vector b(4);
		system("clear");
		cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
		cout << "▀▀▀▀▀▀▀▀▀▀ V  E  C  T  O  R  S     P  A  R  T ▀▀▀▀▀▀▀▀▀▀" << endl;
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
		/* Everything is now fine. Output display information that 3 objects 
		have been deleted. */
	}
	if(option == 2){
		system("clear");
		cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
		cout << "▀▀▀▀▀▀▀▀▀▀▀▀ M  A  T  R  I  X     P  A  R  T ▀▀▀▀▀▀▀▀▀▀▀" << endl;
		cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
		Matrix A(2, 3);
		cout << "Zero matrix (matrix A):" << endl << A;
		cout << "Fill matrix A with values" << endl;
		cin >> A;
		cout << "Filled matrix A:" << endl << A;
		Matrix B(3, 2);
		cout << "Fill matrix B with values" << endl;
		cin >> B;
		cout << "Filled matrix B:" << endl << B;
		cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;	
		cout << "A + B:" << endl;
		cout << A << "+" << B << "=" << A + B;
		cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
		cout << "A - B:" << endl;
		cout << A << "-" << B << "=" << A - B;
		cout << A;
		cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
		Matrix C = A * B;
		int scalar = 5;
		cout << "A * B:" << endl;
		cout << A << "*" << B << "=" << C;
		cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
		cout << "A * scalar:" << endl;
		cout << "Type scalar" << endl;
		cin >> scalar;
		cout << C << "*" << endl << scalar << endl << "=" << C * scalar;
		cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
		Matrix D;
		cout << "D += A:" << endl;
		D += A;
		cout << D << "+=" << A << "=" << D ;
		cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
		cout << "D -= B:" << endl;
		D -= B;
		cout << D << "-=" << B << "=" << D;
		cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
		cout << "D *= B:" << endl;
		D *= C;
		cout << D << "*=" << C << "=" << D;
	}
	if(option == 3){
		system("clear");
		cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
		cout << "▀▀▀▀▀▀▀▀▀▀▀▀ M  A  T  R  I  X     T  E  S  T ▀▀▀▀▀▀▀▀▀▀▀" << endl;
		cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
		int row = 2;
		int col = 2;
		cout << "Type number of columns:";
		cin >> col;
		cout << "Type number of rows:";
		cin >> row;
		Matrix E(row, col);
		cout << "Fill in matrix:";
	}	

	return 0;
}
/* not supported since program was splitted to modules */
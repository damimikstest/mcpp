#include "header.hpp"

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
	Matrix *M = new Matrix(rows, ref.retdim());
	if(retdim() == ref.rows){
		cout << "Matrices sizes passes!" << endl;
		for(int i = 0; i < rows; i++){
			for(int c = 0; c < ref.retdim(); c++){
				int input = 0;
				for (int a = 0; a < retdim(); ++a)
				{
					input += ((*this)[i][a] * ref[a][c]);
				}
				M->input(i, c, input);
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

/* Overloaded logic operators */
/* Comparison - Is equal */
bool Matrix::operator==(const Matrix &ref){
	if(rows == ref.rows){
		for(int i = 0; i < rows; i++){
			if( !(ref.vectors[i] == vectors[i]) ) return FALSE;
		}
		return TRUE;
	}
	else {
		return FALSE;
	}
}

/* Difference - Is not equal */
bool Matrix::operator!=(const Matrix &ref){
	return !((*this) == ref);
}

/* additional methods */
int Matrix::retrows(){
	return rows;
}
int Matrix::retdim(){
	return vectors[0].retdim();
}
void Matrix::input(int row, int col, int value){
	if(row >= 0 and row < rows) vectors[row].input(col, value); 
}

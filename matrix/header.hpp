#ifndef TRUE
#define TRUE 1
#define FALSE 0
#endif

#ifndef HEADER_HPP
#define HEADER_HPP

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include "colours.h"

/* ------------- VECTOR SECTION ---------------- */

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

/* ------------- MATRIX SECTION ---------------- */

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

#endif
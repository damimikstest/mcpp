#include "header.hpp"

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

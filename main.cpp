#include <iostream>

#define TRUE 1
#define FALSE 0

using namespace std;

class Vector{
	int dim;
	int *fields;
public:
	Vector(int d = 2);
	Vector(const Vector &ref);
	
	/* Overloaded equality operator   
	   It simply rewrite values from right 
	   operand (ref) to left operand (this object) */
	void operator=(const Vector &ref);
	/* Stream operators overloading */
	friend ostream& operator<<(ostream& os, const Vector &ref);
	friend istream& operator>>(istream& is, Vector &ref);

};


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


/* Overloaded assignment operator */
void Vector::operator=(const Vector &ref){
	dim = ref.dim;
	fields = new int[dim];
	for (int i = 0; i < dim; ++i){ fields[i] = ref.fields[i];}
}

/* Overloaded out stream operator */ 
ostream& operator<<(ostream& os, const Vector &ref){
	for(int i = 0; i < ref.dim; i++) os << ref.fields[i] << " ";
	os << endl;
	return os;
}

istream& operator>>(istream& is, Vector &ref){
	// cout << "Wpisz tekst" << endl;
	bool again = FALSE;
	do{
		//cout << "jestem w do:" << endl;
		again = FALSE;
		cout.flush(); // synchronize output with stream
		is >> ws; // ignore whitespaces
		int x = is.peek(); // get 
		for(int i = 0; i < ref.dim; i++){
			ref.fields[i] = 0;
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
				//cout << "Data other than numeric, try again!" << endl;
				break;
			}
			//cout << endl;
		}
	} while(again);
	return is;
}

int main()
{
	int mem = 2;
	Vector a;
	Vector b(4);
	cout << "Vector is:" << endl;
	cout << a;
	cout << b;
	a = b;
	cout << "We made vector a = b:" << endl;
	cout << a;
	cout << b;
	cout << "Wpisz wymiar wektora" << endl;
	cin >> mem;
	Vector *nv = new Vector(mem);
	Vector &c = *nv;
	cout << "Wpisz współrzędne wektora" << endl;
	cin >> c;
	cout << "Loaded vector is:" << endl;
	cout << c;
	return 0;
}
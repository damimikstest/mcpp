#include "header.hpp"

int main()
{
	char mainloop = 'y';
	do{
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
			cout << "c * scalar = " << endl << c * mem << endl;
			c *= mem;
			cout << "Again using same variable: c *= scalar" 
			<< endl << "c values are: " << endl << c << endl;
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
			/* input variables */
			int row = 2;
			int col = 2;
			int numeric;
			/* program loop controls */
			int operation = 0;
			char cont = 'y';
			cout << "Matrix A:" << endl;
			cout << "Type number of columns:" << endl;
			cin >> col;
			cout << "Type number of rows:" << endl;
			cin >> row;
			Matrix E(row, col);
			cout << "Fill in matrix:" << endl;
			cin >> E;
			cout << "Matrix B:" << endl;
			cout << "Type number of columns:" << endl;
			cin >> col;
			cout << "Type number of rows:" << endl;
			cin >> row;
			Matrix F(row, col);
			cout << "Fill in matrix:" << endl;
			cin >> F;
			cout << "Enter scalar:" << endl;
			cin >> numeric;
			Matrix G;
			
			do{
				system("clear");
				cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
				cout << "What do you want to do:" << endl
				<< "- 1 - Add A + B:" << endl
				<< "- 2 - Substract A - B:" << endl
				<< "- 3 - Multiply A * B:" << endl
				<< "- 4 - Compare A == B:" << endl
				<< "- 5 - Difference A != B:" << endl
				<< "- 6 - A * scalar:" << endl
				<< "- 7 - B * scalar:" << endl;
				cin >> operation;
				switch(operation)
				{
					case 1:
						system("clear");
						cout << "A + B:" << endl;
						cout << E << endl << "+" << endl << F << endl << "=" << endl << E + F;
						cout << "Do you want to continue with the same data? [y/n]:" << endl;
						cin >> cont;
						break;
					case 2:
						system("clear");
						cout << "A - B:" << endl;
						cout << E << endl << "-" << endl << F << endl << "=" << endl << E - F;
						cout << "Do you want to continue with the same data? [y/n]:" << endl;
						cin >> cont;
						break;					
					case 3:
						system("clear");
						cout << "A * B:" << endl;
						cout << E << endl << "*" << endl << F << endl << "=" << endl << E * F;
						cout << "Do you want to continue with the same data? [y/n]:" << endl;
						cin >> cont;
						break;					
					case 4:
						system("clear");
						cout << "A == B:" << endl;
						cout << E << endl << "==" << endl << F << endl << "=" << endl;
						if(E == F) {cout << "TRUE (matrices equal)" << endl;} else cout << "FALSE (matrices not equal)" << endl; 
						cout << "Do you want to continue with the same data? [y/n]:" << endl;
						cin >> cont;
						break;
					case 5:
						system("clear");
						cout << "A != B:" << endl;
						cout << E << endl << "!=" << endl << F << endl << "=" << endl;
						if(E != F) {cout << "TRUE (matrices not equal)" << endl;} else cout << "FALSE (matrices equal)" << endl; 
						cout << "Do you want to continue with the same data? [y/n]:" << endl;
						cin >> cont;
						break;
					case 6:
						system("clear");
						cout << "A * numeric:" << endl;
						cout << E << endl << "*" << endl << numeric << endl << "=" << endl << E * numeric;
						cout << "Do you want to continue with the same data? [y/n]:" << endl;
						cin >> cont;
						break;
					case 7:
						system("clear");
						cout << "B * numeric:" << endl;
						cout << F << endl << "*" << endl << numeric << endl << "=" << endl << F * numeric;
						cout << "Do you want to continue with the same data? [y/n]:" << endl;
						cin >> cont;
						break;
					default:
						system("clear");
						cout << "Do you want to continue program? [y/n]:" << endl;
						cin >> cont;
						break;

				}
			}while(cont != 'n' and cont != 'N');
		}
		system("clear");
		cout << "Do you want to start program again? [y/n]:" << endl;
		cin >> mainloop;
	}while(mainloop != 'n' and mainloop != 'N');
	return 0;
}
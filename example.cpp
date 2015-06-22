#include <iostream>     // std::cin, std::cout
#include <string>       // std::string
#include <cctype> 		// std::isdigit
#include <stdio.h>

using namespace std;

int main(){
	int count = 1;
	cout << "Wpisz ilość iteracji:" << endl;
	cin >> count;
	int *table = new int[count];
	cout << "Wpisz tekst" << endl;
	cout.flush();

	cin >> ws;
	int x = cin.peek();
	for(int i = 0; i < count; i++){
		table[i] = 0;
		if(isdigit(x))
		{
			int n;
			cin >> n;
			cout << "Wpisałeś liczbę: " << n;
			table[i] = n;
		}
		else
		{
			string ciag;
			cin >> ciag;
			cout << "Wpisałeś tekst: " << ciag;
		}
		cout << endl;
	}

	cout << "PROGRAM EXECUTED WELL" << endl;
	cout << "Output vector is:" << endl << "(";
	for (int i = 0; i < count; ++i)
	{
		cout << table[i];
		if(i == (count - 1)) break;
		cout << ", ";
	}
	cout << ")" << endl;

	return 0;
}
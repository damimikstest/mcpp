#include <fstream> 
#include <iostream>     // std::cin, std::cout
#include <string>       // std::string
#include <cctype> 		// std::isdigit
#include <stdio.h>

using namespace std;

int main(){
	int count = 0;
	cout << "Wpisz ilość iteracji:" << endl;
	cin >> count;
	cout << "Wpisz tekst" << endl;
	cout.flush(); // synchronize output with stream
	cin >> ws; // ignore whitespaces
	int x = cin.peek(); // get 
	while(x != EOF){
		if(isdigit(x))
		{
			int n;
			cin >> n;
			cout << "Wpisałeś liczbę: " << n;
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
	/* Vector display */

	return 0;
}
/*
Jerry Lau
Math-pro1
main.cpp

Base converision program

*/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	string inS;
	int periode;
	int baseO;
	int baseF;
	int prec;
	
	cout <<"Enter le numero de conversion: " << endl;
	cin >> inS;
	cout <<"Enter la periode du numero: " << endl;
	cin >> periode;
	cout << "Enter la base originale: " << endl;
	cin >> baseO;
	cout << "Enter la base finale: " << endl;
	cin >> baseF;
	cout << "Enter la precision du numero finale" << endl;
	cin >> perc;

	//test input
	cout << inS << " " << periode << " " << baseO << " " << baseF << " " << prec << endl;

	system("PAUSE");

	return 0;
}
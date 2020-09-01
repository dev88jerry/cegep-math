/*
Jerry Lau
Math-pro1
main.cpp

Base converision program

*/

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "Fonctions.h"

using namespace std;

int convCharInt(char c) {
	int ret = 0;

	if (c == '0')ret = 0;
	else if (c == '1') ret = 1;
	else if (c == '2') ret = 2; 
	else if (c == '3') ret = 3;
	else if (c == '4') ret = 4;
	else if (c == '5') ret = 5;
	else if (c == '6') ret = 6;
	else if (c == '7') ret = 7;
	else if (c == '8') ret = 8;
	else if (c == '9') ret = 9;
	else if (c == 'a') ret = 10;
	else if (c == 'b') ret = 11;
	else if (c == 'c') ret = 12;
	else if (c == 'd') ret = 13;
	else if (c == 'e') ret = 14;
	else if (c == 'f') ret = 15;
	else if (c == 'g') ret = 16;
	else if (c == 'h') ret = 17;
	else if (c == 'i') ret = 18;
	else if (c == 'j') ret = 19;
	else if (c == 'k') ret = 20;
	else if (c == 'l') ret = 21;
	else if (c == 'm') ret = 22;
	else if (c == 'n') ret = 23;
	else if (c == 'o') ret = 24;
	else if (c == 'p') ret = 25;
	else if (c == 'q') ret = 26;
	else if (c == 'r') ret = 27;
	else if (c == 's') ret = 28;
	else if (c == 't') ret = 29;
	else if (c == 'u') ret = 30;
	else if (c == 'v') ret = 31;
	else if (c == 'w') ret = 32;
	else if (c == 'x') ret = 33;
	else if (c == 'y') ret = 34;
	else if (c == 'z') ret = 35;
	
	return ret;
}

int convB10W(vector <char> inpV, int baseOri) 
{
	int ret = 0;

	for (int i = 0; i < inpV.size(); i++) {
		char c = inpV.at(i);		
		int con = convCharInt(c);
		ret += (con * pow(baseOri, inpV.size() - 1 - i));
		cout << ret << endl;
	}	
	
	/*
	int j = 0;
	vector<char>::reverse_iterator rit = inpV.rbegin();
	for (; rit != inpV.rend(); rit++) {
		*rit = j++;
	}

	for (vector<char>::iterator it = inpV.begin(); it != inpV.end(); it++) {
		char c = *it;
		cout << c << endl;
		int con = convCharInt(c);
		cout << con << endl;
	}
	
	for (int i = 0; i < inpV.size(); i++) {
		char c = inpV.at(i);
		cout << c << endl;
		int con = convCharInt(c);
		cout << con << endl;
		ret += con * pow(baseOri, i);		
	}	
	*/
	return ret;
}

int main()
{
	string inS;
	int periode;
	int baseO;
	int baseF;
	int prec;
	int base10whole;

	cout << "Enter le numero de conversion: " << endl;
	cin >> inS;
	cout << "Enter la periode du numero: " << endl;
	cin >> periode;
	cout << "Enter la base originale: " << endl;
	cin >> baseO;
	cout << "Enter la base finale: " << endl;
	cin >> baseF;
	cout << "Enter la precision du numero finale" << endl;
	cin >> prec;

	//test input
	cout << inS << " " << periode << " " << baseO << " " << baseF << " " << prec << endl;

	//place string to char
	vector<char> v(inS.begin(), inS.end());

	int sep = 0;
	//check comma seperator
	for (int i = 0; i < v.size(); i++) {
		if (v.at(i) == 44) {
			sep = i;
		}
	}

	vector<char> whole;
	vector<char> deci;
	if (sep != 0) {
		whole.resize(v.size());
		deci.resize(v.size());

		for (int i = 0; i < sep; i++) {
			whole.at(i) = v.at(i);
		}
		whole.shrink_to_fit();
		for (int i = 0; i < whole.size(); i++) {
			cout << whole.at(i) << " ";
		}
		cout << endl;

		for (int i = sep + 1, j = 0; i < v.size(); i++, j++) {
			deci.at(j) = v.at(i);
		}
		deci.shrink_to_fit();
		for (int i = 0; i < deci.size(); i++) {
			cout << deci.at(i) << " ";
		}
		cout << endl;
	}
	
	if (baseO != 10 && sep == 0) {

		base10whole = convB10W(v, baseO);		
	}
	
	

	system("PAUSE");

	return 0;
}
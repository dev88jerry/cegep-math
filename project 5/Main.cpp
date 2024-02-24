/*
Jerry
Math-pro5
main.cpp
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const int bMax = 25;
const int sMin = 16;

//code 1
int oddSum(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		//sum of n numbers
		//return n + oddSum(n - 1);
		if (n % 2 == 1) {
			return n + oddSum(n - 1);
		}
		else {
			return oddSum(n - 1);
		}
	}
}

//code 2
int itRec = 0;

int recBillets(const int max, int cmp) {
	
	int mb25 = 0, mb16 = 0, mb1 = 0;

	//1st call
	if (cmp == 0) {
		int res = max % bMax;
		if (res > sMin) {
			mb1 = res %sMin;
			mb16 = floor(res / sMin);
		}
		else {
			mb1 = res;
		}

		mb25 = floor(max / bMax);
		itRec = mb25 - 1;
		cmp = mb25 + mb16 + mb1;

		return recBillets(max, cmp);
	}

	if (itRec == 0) {
		return cmp;
	}
	else {
		int reste = max - (itRec*bMax);
		mb1 = reste % sMin;
		mb16 = floor(reste / sMin);
		int cmp2 = itRec + mb1 + mb16;
		if (cmp2 < cmp) {
			cmp = cmp2;
		}
		itRec--;
		return recBillets(max, cmp);
	}	
}

//code 3
int iterBillets(int max) {

	int mb25=0, mb16=0, mb1=0;

	//1st
	int res = max % bMax;
	
	if (res > sMin) {
		mb1 = res % sMin;
		mb16 = floor(res / sMin);
	}
	else {
		mb1 = res;
	}
	mb25 = floor(max / bMax);
	
	int cmp = mb25 + mb16 + mb1;

	//rest
	for (int i = mb25 - 1; i != 0; i--) {
		int reste = max - (i*bMax);
		mb1 = reste % sMin;
		mb16 = floor(reste / sMin);
		int cmp2 = i + mb1 + mb16;
		if (cmp2 < cmp) {
			cmp = cmp2;
		}
	}

	return cmp;
}

//code 4
double nRetN(double n) {
	return (2.0 / 3.0) * pow(4, n);
}


int printAP(int n) {
	if (n <= 1) {		
		return n + 1;
	}	
	return 2 * printAP(n - 1) + 8 * printAP(n - 2);
}

int pAP(int n) {
	if (n <= 1) {
		return n + 1;
	}
	int ret = 0;
	for (int i = 1; i <= 2; i++) {
		ret += pAP(n - 1);
	}
	for (int j = 1; j <= 8; j++) {
		ret += pAP(n - 2);
	}
	return ret;
}
int c = 0;
int ppp(int n) {
	if (n == 0) {
		c++;
		return 1;
	}
	else if (n == 1) {
		c++;
		return 2;
	}
	for (int i = 2; i <= n; i++) {
		c++;
		return 2 * ppp(n - 1) + 8 * ppp(n - 2);
	}
}

int main() {

	char inp;

	do
	{
		cout << "MENU" << endl;
		cout << "A: algo somme impair rec" << endl;
		cout << "B: billets minimum rec" << endl;
		cout << "C: billets minimum iter" << endl;
		cout << "D: N retour N" << endl;
		cout << "Q: quitter" << endl;
		cout << "Enter votre choix" << endl;
		cin >> inp;

		inp = tolower(inp);

		switch (inp)
		{
		case 'a': {
			int in;

			cout << "Combien de nombre pour la somme" << endl;
			cin >> in;

			cout << oddSum(in) << endl;

			break;
		}
		case 'b': {
			int in;

			cout << "Quel est le nombre" << endl;
			cin >> in;

			cout << recBillets(in, 0) << endl;

			break;
		}
		case 'c': {
			int in;

			cout << "Quel est le nombre" << endl;
			cin >> in;

			cout << iterBillets(in) << endl;

			break;
		}
		case 'd': {
			double in;
			cout << "Input please " << endl;
			cin >> in;

			cout << round(nRetN(in)) << endl;

			break;
		}
		case 'e': {
			int in;
			cout << "rec num please" << endl;
			cin >> in;

			
			cout << "1. " << printAP(in) << endl;
			cout << "2. " << pAP(in) << endl;
			cout << "3. " << ppp(in) << endl;
			cout << "Count 3 = " << c << endl;
			break;
		}
		default:
			break;
		}

	} while (inp != 'q');

	system("PAUSE");

	return 0;
}
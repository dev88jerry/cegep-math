/*
Jerry
Math-pro4
main.cpp
Extended Euclidean Algorithm
Fermat factorization
Mod power calc -> C^d mod n
*/

#include <iostream>
#include <cmath>
#include <string>
#include <stack>

using namespace std;

//Code 1
//Extended Euclidean Algorithm
//table and inverse mod
void gcdTab(const int a, const int b) {

	int q, r, x, y, r1, x1, y1;
	int sr1, sx1, sy1;

	r = a, r1 = b;

	x = 1, y = 0, x1 = 0, y1 = 1;

	cout << "q\tr\tx\ty\tr1\tx1\ty1" << endl;
	cout << "\t" << r << "\t" << x << "\t" << y << "\t" << r1 << "\t" << x1 << "\t" << y1 << endl;

	while (r1 != 0) {
		sr1 = r;
		sx1 = x;
		sy1 = y;

		q = floor(r / r1);

		r = r1;
		x = x1;
		y = y1;

		r1 = sr1 % r;
		x1 = sx1 - q*x;
		y1 = sy1 - q*y;

		cout << q << "\t" << r << "\t" << x << "\t" << y << "\t" << r1 << "\t" << x1 << "\t" << y1 << endl;
	}

	if (r == 1) {
		cout << r << " = " << x << " * " << a << " + " << y << " * " << b << endl;
		if (y < 0) {
			y += a;
			cout << y << " est l'inverse modulaire" << endl;
		}
		else {
			cout << y << " est l'inverse modulaire" << endl;
		}
	}
}

//Code 2
//fermat factorization
//n = p*q as n = a^2-b^2
int fermat(const int n) {

	int a = ceil(sqrt(n));
	int b2 = a*a - n;
	int b = round(sqrt(b2));
	int c = 0;
	while (b * b != b2) {
		a = a + 1;
		b2 = a*a - n;
		b = round(sqrt(b2));
		c++;
	}
	cout << "Etapes: " << c << endl;

	return a - b;
}

//Code 3
//convert to base2
string base2(const int base10Num) {

	string s;
	stack<char> mod;
	char c;
	int modRes;
	int divRes = base10Num;

	while (divRes != 0) {
		modRes = divRes % 2;

		if (modRes == 1) {
			c = '1';
		}
		else {
			c = '0';
		}
		mod.push(c);
		divRes = divRes / 2;
	}

	while (!mod.empty())
	{
		s += mod.top();
		mod.pop();
	}

	return s;
}

//Code 3
//base2 string pow with mod table
int expModCalc(const string b2, const int modN, const int cN) {

	string s = b2;

	int i = 0;

	long long int bk = 1;
	long long int lv = 1;

	string::reverse_iterator ri = s.rbegin();
	for (string::reverse_iterator rit = s.rbegin(); rit != s.rend(); ++rit) {
		if (i != 0) {
			lv = (lv*lv) % modN;
		}
		else {
			lv *= cN % modN;
		}
		//cout << lv << endl;
		if (*rit == '1') {
			bk = (bk*lv) % modN;
		}
		i++;
	}

	return bk;
}

//code pour executer le programme
int main() {

	char inp;

	do
	{
		cout << "MENU" << endl;
		cout << "A: algo Euclide etendu" << endl;
		cout << "B: factorisation" << endl;
		cout << "C: calcule modulaire" << endl;
		cout << "Q: quitter" << endl;
		cout << "Enter votre choix" << endl;
		cin >> inp;

		inp = tolower(inp);

		switch (inp)
		{
		case 'a': {
			int a, b;
			cout << "Enter les nombres pour a et b" << endl;
			cin >> a;
			cin >> b;

			if (b > a) {
				gcdTab(b, a);
			}
			else {
				gcdTab(a, b);
			}
			break;
		}
		case 'b': {
			int x;
			cout << "Enter le nombre pour factoriser" << endl;
			cin >> x;
			int y = fermat(x);
			int z = x / y;
			cout << x << " facotrise en " << y << " x " << z << endl;
			break;
		}
		case 'c': {
			int c, d, n;
			cout << "Calcule de expoentiel modulaire C^d mod n" << endl;
			cout << "Enter les nombres en ordre C, d, n" << endl;
			cin >> c;
			cin >> d;
			cin >> n;
			string b2 = base2(d);

			cout << c << " ^ " << d << " mod " << n << " = " << expModCalc(b2, n, c) << endl;

			break;
		}
		default:
			break;
		}

	} while (inp != 'q');

	system("PAUSE");

	return 0;
}
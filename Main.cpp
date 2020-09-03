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
#include <stack>
#include <iomanip>

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

char convIntChar(int i) {
	char ret;

	if (i == 0)ret = '0';
	else if (i == 1) ret = '1';
	else if (i == 2) ret = '2';
	else if (i == 3) ret = '3';
	else if (i == 4) ret = '4';
	else if (i == 5) ret = '5';
	else if (i == 6) ret = '6';
	else if (i == 7) ret = '7';
	else if (i == 8) ret = '8';
	else if (i == 9) ret = '9';
	else if (i == 10) ret = 'a';
	else if (i == 11) ret = 'b';
	else if (i == 12) ret = 'c';
	else if (i == 13) ret = 'd';
	else if (i == 14) ret = 'd';
	else if (i == 15) ret = 'f';
	else if (i == 16) ret = 'g';
	else if (i == 17) ret = 'h';
	else if (i == 18) ret = 'i';
	else if (i == 19) ret = 'j';
	else if (i == 20) ret = 'k';
	else if (i == 21) ret = 'l';
	else if (i == 22) ret = 'm';
	else if (i == 23) ret = 'n';
	else if (i == 24) ret = 'o';
	else if (i == 25) ret = 'p';
	else if (i == 26) ret = 'q';
	else if (i == 27) ret = 'r';
	else if (i == 28) ret = 's';
	else if (i == 29) ret = 't';
	else if (i == 30) ret = 'u';
	else if (i == 31) ret = 'v';
	else if (i == 32) ret = 'w';
	else if (i == 33) ret = 'x';
	else if (i == 34) ret = 'y';
	else if (i == 35) ret = 'z';

	return ret;
}

//convert whole to base 10
int convB10W(vector<char> inpV, const int baseOri) 
{
	int ret = 0;

	for (int i = 0; i < inpV.size(); i++) {
		char c = inpV.at(i);
		int con = convCharInt(c);
		ret += (con * pow(baseOri, inpV.size() - 1 - i));		
	}	

	return ret;
}

//convert deci to base 10, no periode
double convB10Deci(vector<char> inpV, const int baseOri) {
	double ret = 0.0;
	
	for (int i = 0; i < inpV.size(); i++) {
		char c = inpV.at(i);
		int con = convCharInt(c);
		ret += (con * pow(baseOri, (i + 1) * -1));
	}
	
	return ret;
}

//special conv deci to base 10 with periode
double specConv(vector<char> inpV, const int baseOri, const int pos) {
	double ret = 0.0;

	for (int i = 0; i < inpV.size(); i++) {
		char c = inpV.at(i);
		int con = convCharInt(c);
		ret += (con * pow(baseOri, (i + pos) * -1));
	}

	return ret;
}

//convert deci num with periode to base 10
double convDeciPeri(vector<char> inpV, const int peri, const int baseOri) {
	double ret = 0.0;
	stack<char> s;
	vector<char> v;
	double dec;
	double konst;

	//get a0 into stack
	for (int i = 0; i < peri; i++) {
		s.push(inpV.back());
		inpV.pop_back();
	}

	//a0
	while (!s.empty()) {
		v.push_back(s.top());
		s.pop();
		
	}

	konst = convB10Deci(inpV, baseOri);
	dec = specConv(v, baseOri, v.size());
	//cout << konst << endl;
	//cout << dec << endl;
	ret = konst + (dec / (1.0 - pow(baseOri, (-1.0*peri))));
	//cout << fixed;
	//cout << setprecision(10);
	//cout << ret << endl;
	return ret;
}

//convert whole part base10 num to base N
string convBaseN(const int base10Num, const int baseFin) {

	string s;
	stack<char> mod;
	char c;
	int modRes;
	int divRes = base10Num;

	while (divRes != 0) {
		modRes = divRes % baseFin;
		c = convIntChar(modRes);
		mod.push(c);
		divRes = divRes / baseFin;		
	}

	while (!mod.empty())
	{
		s += mod.top();
		mod.pop();
	}

	return s;
}

//convert deci part base10 num to base N
string convDeciBaseN(const double base10Deci, const int baseFin, const int pres) {
	string s;
	double whole, fract, start;	
	start = base10Deci;
	char c;
	
	for (int i = 0; i < pres; i++) {
		start *= baseFin * 1.0;
		whole = floor(start);
		fract = start - whole;		
		int x = int (whole);		
		c = convIntChar(x);		
		s += c;
		start = fract;
	}

	return s;
}

int main()
{
	string inS;
	int periode;
	int baseO;
	int baseF;
	int prec;
	int base10whole;
	string finOut;
	double b10Deci;

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
	//cout << inS << " " << periode << " " << baseO << " " << baseF << " " << prec << endl;

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
	//split into whole and decimal parts
	if (sep != 0) {
		for (int i = 0; i < sep; i++) {
			whole.push_back(v.at(i));
		}
		for (int i = sep + 1; i < v.size(); i++) {
			deci.push_back(v.at(i));
		}
	}

	if (periode != 0 && sep != 0) {
		if (baseO != 10) {
			b10Deci = convDeciPeri(deci, periode, baseO);
			baseO = 10;
		}
		else {
			b10Deci = convDeciPeri(deci, periode, baseO);
		}
	}
	
	//no decimal & not base10
	if (baseO != 10 && sep == 0) {		
		//input convert to b10
		base10whole = convB10W(v, baseO);
		if (baseF != 10) {
			//base 10 to final base
			finOut = convBaseN(base10whole, baseF);
		}
	}
	//decimal & not base10
	else if (baseO != 10) {		
		base10whole = convB10W(whole, baseO);		
		b10Deci = convB10Deci(deci, baseO);
		if (baseF != 10) {
			//base 10 to final base
			finOut = convBaseN(base10whole, baseF);
			finOut += ",";
			finOut += convDeciBaseN(b10Deci, baseF, prec);			
		}
		else {
			double total = base10whole + b10Deci;
			cout << total << endl;
		}
	}
	//no decimal & base 10
	else if(sep == 0){
		int i = stoi(inS);
		finOut = convBaseN(i, baseF);
	}
	//decimal & base 10
	else {
		string s;
		for (int i = 0; i < whole.size(); i++) {
			s += whole.at(i);
		}
		int w = stoi(s);
		
		string sd = "0.";
		for (int i = 0; i < deci.size(); i++) {
			sd += deci.at(i);
		}
		double d = stod(sd);

		finOut = convBaseN(w, baseF);
		finOut += ",";
		finOut += convDeciBaseN(d, baseF, prec);
		cout << finOut << endl;
	}
	
	/*
	round part
	calc prec+1 
	if val at prec+1/baseF > 0.5 round up
	else leave as is
	*/



	/*******************
	Final print section
	*/

	if (baseF == 10 && sep == 0) {
		if (prec == 0) {
			cout << "Conversion de " << inS << " en base " << baseO << " est egale a " << base10whole << " en base 10" << endl;
		}
		else {
			//todo -> place into string select # in ? to round.
		}
	}
	else if (sep == 0) {
		if (prec == 0) {
			cout << "Conversion de " << inS << " en base " << baseO << " est egale a " << finOut << " en base " << baseF << endl;
		}
		else
		{
			//todo -> rounding
			
		}
	}
	else if (baseF == 10) {

	}

	system("PAUSE");

	return 0;
}
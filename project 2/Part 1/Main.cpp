/*
Jerry
Math-pro2
main.cpp

Enumeration
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

//dispo^choix
int ordANDrep(int choix, int dispo) {
	int ret = 1;
	
	ofstream myFile;
	myFile.open("possibility.txt", ofstream::trunc);

	int temp, temp2;
	vector<int> a;

	for (temp2 = 1; temp2 <= choix + 1; temp2++) {
		a.push_back(1);
	}
	a.at(choix) = 0;
	temp = choix;

	while (true)
	{
		if (a.at(temp) == dispo) {
			temp--;
			if (temp == 0) {
				break;
			}
		}
		else {
			a.at(temp)++;
			while (temp < choix) {
				temp++;
				a.at(temp) = 1;
			}

			//cout << ret << ". ";
			myFile << ret << ". ";
			for (temp2 = 1; temp2 <= choix; temp2++) {
				//cout << a.at(temp2) << ", ";
				myFile << a.at(temp2) << ", ";
			}
			//cout << endl;
			myFile << "\n";
			ret++;
		}
	}		
	
	myFile.close();

	return ret;
}

//dispo!/(dispo-choix)! - permu
int ordANDnoRep(int choix, int dispo) {
	int ret = 1;

	ofstream myFile;
	myFile.open("possibility.txt", ofstream::trunc);
	
	vector<int> d(dispo);
	iota(d.begin(), d.end(), 1);

	do {		
		myFile << ret << ". ";
		//cout << ret << ". ";

		for (int i = 0; i < choix; ++i) {			
			//cout << d[i] << ", ";
			myFile << d.at(i) << ", ";
		}
		myFile << "\n";
		//cout << "\n";
		ret++;
		reverse(d.begin() + choix, d.end());
	} while (next_permutation(d.begin(), d.end()));


	myFile.close();

	return ret;
}

//(n+r-1)!/r!(n-1)!
int noOrdANDrep(int choix, int dispo) {
	int ret = 1;

	ofstream myFile;
	myFile.open("possibility.txt", ofstream::trunc);

	vector<string> op;

	for (int i = 1; i <= dispo; i++) {
		op.push_back(to_string(i));
	}

	dispo--;
	vector<int> v(choix + 1, 0);
	while (true) {
		for (int i = 0; i < choix; i++) {
			if (v[i] > dispo) {
				v.at(i + 1) += 1;
				for (int j = i; j >= 0; --j) {
					v.at(j) = v.at(i + 1);
				}
			}
		}

		if (v.at(choix) > 0)break;

		//cout << ret << ". ";
		myFile << ret << ". ";

		for (int i = 0; i < choix; i++) {
			//cout << op[v[i]].c_str() << ", ";
			myFile << op[v[i]].c_str() << ", ";
		}
		//cout << endl;
		myFile << "\n";
		
		v.at(0) += 1;
		ret++;
	}

	myFile.close();
	
	return ret;
}

//combination
int noOrdANDnoRep(int choix, int dispo) {
	int ret = 1;

	ofstream myFile;
	myFile.open("possibility.txt", ofstream::trunc);

	vector<bool> v(dispo);
	fill(v.begin(), v.begin() + choix, true);

	do {
		myFile << ret << ". ";
		//cout << ret << ". ";
		for (int i = 0; i < dispo; ++i)
		{
			if (v.at(i)) {
				//cout << i + 1 << ", ";
				myFile << i + 1 << ",";
			}
		}
		//cout << endl;
		myFile << "\n";
		ret++;
	} while (prev_permutation(v.begin(), v.end()));

	myFile.close();

	return ret;
}

int main()
{

	bool ord, rep;
	int oChoisir, oDispo;

	cout << "Enter s'il y a une ordre: " << endl;
	cin >> ord;
	cout << "Enter s'il y a une repetition: " << endl;
	cin >> rep;
	cout << "Enter le nombre d'objet a choisir: " << endl;
	//r
	cin >> oChoisir;
	cout << "Enter le nombre d'objet disponibles: " << endl;
	//n
	cin >> oDispo;

	//test input
	cout << "Enumeration (" << ord << " " << rep << " " << oChoisir << " " << oDispo << ")" << endl;

	int pos;

	if (ord && rep) {
		auto start = chrono::high_resolution_clock::now();
		ios_base::sync_with_stdio(false);

		pos = ordANDrep(oChoisir, oDispo);
		cout << "On a trouve : " << pos - 1 << " possibilite" << endl;		

		auto end = chrono::high_resolution_clock::now();
		double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-9;
		cout << "Time taken by function is : ";
		cout << fixed << time_taken << setprecision(9);
		cout << " sec" << endl;
	}
	else if (ord && !rep) {
		auto start = chrono::high_resolution_clock::now();
		ios_base::sync_with_stdio(false);

		pos = ordANDnoRep(oChoisir, oDispo);
		cout << "On a trouve : " << pos - 1 << " possibilite" << endl;

		auto end = chrono::high_resolution_clock::now();
		double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-9;
		cout << "Time taken by function is : ";
		cout << fixed << time_taken << setprecision(9);
		cout << " sec" << endl;
	}
	else if (!ord && rep) {
		auto start = chrono::high_resolution_clock::now();
		ios_base::sync_with_stdio(false);

		pos = noOrdANDrep(oChoisir, oDispo);
		cout << "On a trouve : " << pos - 1 << " possibilite" << endl;

		auto end = chrono::high_resolution_clock::now();
		double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-9;
		cout << "Time taken by function is : ";
		cout << fixed << time_taken << setprecision(9);
		cout << " sec" << endl;
	}
	else if (!ord && !rep) {
		auto start = chrono::high_resolution_clock::now();
		ios_base::sync_with_stdio(false);

		pos = noOrdANDnoRep(oChoisir, oDispo);		
		cout << "On a trouve : " << pos - 1 << " possibilite" << endl;
		
		auto end = chrono::high_resolution_clock::now();
		double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		time_taken *= 1e-9;
		cout << "Time taken by function is : ";
		cout << fixed << time_taken << setprecision(9);
		cout << " sec" << endl;
	}
	else {
		cout << "Enter non valid" << endl;
	}

	system("PAUSE");

	return 0;
}

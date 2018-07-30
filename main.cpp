#include <iostream>
#include <string>
#include <vector>
#include "Momenta.h"
using namespace std;

int main() {

	Momenta momenta;

	//int n;
	//cin >> n;
	//char A('A'), B('B'), C('C');

	//momenta.Recursion(2, A, B, C);
	
	string input;
	cin >> input;
	momenta.Expression(input);

	getchar();
	getchar();
}
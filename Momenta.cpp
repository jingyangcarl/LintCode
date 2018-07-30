#include "Momenta.h"

Momenta::Momenta() {

}

void Momenta::Move(char A, char C) {
	cout << A << "->" << C << endl;
}

void Momenta::Recursion(int n, char A, char B, char C) {

	if (n == 1) {
		Move(A, C);
		return;
	}
	else {
		Recursion(n - 1, A, C, B);
		Move(A, C);
		Recursion(n - 1, B, A, C);
	}

}

void Momenta::Expression(string input) {

	stack<char> operatorStack;
	// Carl: operators, which should be outputed according to their priority
	// Carl: the priority of * and / are higher than + and -
	for (string::iterator iter = input.begin(); iter != input.end(); iter++) {
		if (*iter >= 'a' && *iter <= 'z') {
			// Carl: operand, which should be outputed directly
			cout << *iter;
		}
		else if (*iter == '+' || *iter == '-') {
			// Carl: operaters with lower priority
			if (operatorStack.empty())
				operatorStack.push(*iter);
			else if (!operatorStack.empty() && (operatorStack.top() == '+' || operatorStack.top() == '-')) {
				cout << operatorStack.top();
				operatorStack.pop();
				operatorStack.push(*iter);
			}
			else if (!operatorStack.empty() && (operatorStack.top() == '*' || operatorStack.top() == '/')) {
				while (!operatorStack.empty()) {
					cout << operatorStack.top();
					operatorStack.pop();
				}
				operatorStack.push(*iter);
			}
		}
		else if (*iter == '*' || *iter == '/') {
			// Carl: operaters with higher priority
			if (operatorStack.empty())
				operatorStack.push(*iter);
			else {
				while (!operatorStack.empty() && (operatorStack.top() == '*' || operatorStack.top() == '/')) {
					cout << operatorStack.top();
					operatorStack.pop();
				}
				operatorStack.push(*iter);
			}
		}
	}
	while (operatorStack.size()) {
		cout << operatorStack.top();
		operatorStack.pop();
	}

}
#include "Solution_37.h"

int Solution_37::reverseInteger(int number) {
	// write your code

	int reverseNumber(0);
	int digit(0);

	while (number) {
		digit = number % 10;
		reverseNumber = reverseNumber * 10 + digit;
		number /= 10;
	}

	return reverseNumber;
}

void Solution_37::test() {
	// Carl: input
	int num;
	cin >> num;

	// Carl: Algorithm and output;
	cout << reverseInteger(num) << endl;

}

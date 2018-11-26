#include <iostream>
#include <Windows.h>
#include "Solution_2.h"
using namespace std;

long long Solution_2::trailingZeros(long long n) {

	// Carl: calculate factorial;
	long long factorial(1);
	while (n) {
		factorial *= n;
		n--;
	}

	// Carl: count trailing zeros;
	long long count(0);
	while (factorial > 10) {
		count += factorial % 10 == 0 ? 1 : 0;
		factorial /= 10;
	}

	return count;

	// Carl: error when input 105
}

long long Solution_2::trailingZeros_2(long long n) {

	// Carl: the zeros can only created by factors group of (1, 10) and (2, 5),
	// Carl: factors group of (1, 10) can also be represented into (2, 5)
	// Carl: so the number of zeros is equal to the pairs of (2, 5)
	// Carl: which is the least amount of 2 or 5
	long long count2(0), count5(0);

	while (n) {

		long long tempN(n);

		// Carl: skip odd factors
		switch (tempN % 10) {
		case 1: 
		case 3:
		case 7: 
		case 9: 
			n--;
			continue;
		}

		// Carl: count 2s in the current N
		while (tempN % 2 == 0) {
			count2++;
			tempN /= 2;
		}

		// Carl: count 5s in the current N
		while (tempN % 5 == 0) {
			count5++;
			tempN /= 5;
		}

		n--;
	}

	return count2 < count5 ? count2 : count5;

	// Carl: error when input 1001171717
}

long long Solution_2::trailingZeros_3(long long n) {
	// Carl: the zeros can only created by factors group of (1, 10) and (2, 5),
	// Carl: factors group of (1, 10) can also be represented into (2, 5)
	// Carl: so the number of zeros is equal to the pairs of (2, 5)
	// Carl: which is the least amount of 2 or 5

	// Carl: if we list out the first 20 factorization, we will have
	/*
	 * 1 
	 * 2 2^1*1
	 * 3
	 * 4 2^2*1
	 * 5 		5^1*1
	 * 6 2^1*3
	 * 7
	 * 8 2^3
	 * 9
	 * 10 		5^1*2^1
	 * 11
	 * 12 2^2*3
	 * 13
	 * 14 2*7
	 * 15 		5^1*3
	 * 16 2^4*1
	 * 17
	 * 18 2*9
	 * 19
	 * 20 		5^1*2^2
	 * 21
	 * 22 2*11
	 * 23
	 * 24 2^3*3
	 * 25		5^2*1
	 * 30		5^1*2^1*3
	 */
	// Carl: which means the number of 2 and 5 is a function of the given number
	// Carl: and the number of 5 is always less than 2
	// Carl: so the problem is to get the factorization of last number which is able to be divided by 5
	// Carl: and sum from 1 to it;

	long long count(0);
	for (long long i = 5; i <= n; i += 5) {
		long long temp(i);
		// Carl: count how many factors of 5 in the current number;
		while (temp % 5 == 0) {
			count++;
			temp /= 5;
		}
	}

	return count;
	
}

long long Solution_2::trailingZeros_4(long long n) {
	// Carl: the zeros can only created by factors group of (1, 10) and (2, 5),
	// Carl: factors group of (1, 10) can also be represented into (2, 5)
	// Carl: so the number of zeros is equal to the pairs of (2, 5)
	// Carl: which is the least amount of 2 or 5
	// Carl: the number of 5 is far less than that of 2
	// Carl: the question is to count how many factors of 5 are there in all multiples

	if (n < 5) return 0;
	else {
		while (n % 5 != 0) n--;
		return trailingZeros_4(n/5) + n / 5;
	}
}

long long Solution_2::trailingZeros_5(long long n) {
	// Carl: this is the same as Solution_2::trailingZeros_4
	// Carl: the difference between is that trailingZeros_4 is a recursion version and trailingZeros_5 is non-recursive

	long long count(0);
	while (n > 5) {
		count += n / 5;
		n /= 5;
	}

	return count;
}

long long Solution_2::runningTest(long long n) {
	// Carl: test all the methods with n = 1001171717

	LARGE_INTEGER startTime;
	LARGE_INTEGER endTime;
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);


	QueryPerformanceCounter(&startTime);
	cout << trailingZeros(n) << endl;
	QueryPerformanceCounter(&endTime);
	cout << "Running time 1: " << (double)(endTime.QuadPart - startTime.QuadPart) / frequency.QuadPart << endl;

	QueryPerformanceCounter(&startTime);
	cout << trailingZeros_2(n) << endl;
	QueryPerformanceCounter(&endTime);
	cout << "Running time 2: " << (double)(endTime.QuadPart - startTime.QuadPart) / frequency.QuadPart << endl;

	QueryPerformanceCounter(&startTime);
	cout << trailingZeros_3(n) << endl;
	QueryPerformanceCounter(&endTime);
	cout << "Running time 3: " << (double)(endTime.QuadPart - startTime.QuadPart) / frequency.QuadPart << endl;

	QueryPerformanceCounter(&startTime);
	cout << trailingZeros_4(n) << endl;
	QueryPerformanceCounter(&endTime);
	cout << "Running time 4: " << (double)(endTime.QuadPart - startTime.QuadPart) / frequency.QuadPart << endl;

	QueryPerformanceCounter(&startTime);
	cout << trailingZeros_5(n) << endl;
	QueryPerformanceCounter(&endTime);
	cout << "Running time 5: " << (double)(endTime.QuadPart - startTime.QuadPart) / frequency.QuadPart << endl;

	/*
	* input: 1001171717
	* output:
	* 0
	* Running time 1: 11.0006
	* 250292920
	* Running time 2: 125.601
	* 250292920
	* Running time 3: 16.2693
	* 250292920
	* Running time 4: 0.000299156
	* 250292920
	* Running time 5: 0.000293
	*/
	return 0;
}

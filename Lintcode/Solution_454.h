#pragma once
#include <iostream>
using namespace std;

class Rectangle {
private:
	/*
	 * Define two public attributes width and height of type int.
	 */
	 // write your code here
	double width;
	double height;

public:
	/*
	* Define a constructor which expects two parameters width and height here.
	*/
	// write your code here
	Rectangle(double width, double height);

	/*
	* Define a public method `getArea` which can calculate the area of the
	* rectangle and return.
	*/
	// write your code here
	double getArea();
};

class Solution_454 {
public:
	void test();
};

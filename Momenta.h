#pragma once
#include <iostream>
#include <stack>
using namespace std;

class Momenta {

public:
	Momenta();

	void Move(char A, char C);

	void Recursion(int n, char A, char B, char C);

	/*
	* param a: An integer
	* param b: An integer
	* return: The sum of a and b
	*/
	void Expression(string input);

private:


};
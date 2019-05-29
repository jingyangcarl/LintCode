#include "Solution_454.h"

Rectangle::Rectangle(double width, double height) {
	this->width = width;
	this->height = height;
}

double Rectangle::getArea() {
	return width * height;
}

void Solution_454::test() {
	// input;
	double width(0), height(0);
	cin >> width >> height;

	// algorithm and output;
	Rectangle rectangle(width, height);
	cout << rectangle.getArea() << endl;
}

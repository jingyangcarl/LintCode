#include "Solution_496.h"

void Solution_496::test() {

	ToyFactory factory = ToyFactory();
	string type = "Dog";
	Toy *toy = factory.getToy(type);
	toy->talk();
}

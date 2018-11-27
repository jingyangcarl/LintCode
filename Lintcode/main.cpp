#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<int> vec;
	for (int i = 0; i < 5; i++) vec.push_back(i);
	vector<int>::iterator iterVec = vec.begin()+1;
	for (int i = 0; i < 2; i++) {
		iterVec = vec.erase(iterVec);
	}

	vec;

	getchar();
	getchar();

}
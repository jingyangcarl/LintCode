#include "Solution_227.h"

Tower::Tower(int i) {
	// create three towers
}

void Tower::add(int d) {
	// Add a disk into this tower
	if (!disks.empty() && disks.top() <= d) {
		printf("Error placing disk %d", d);
	}
	else {
		disks.push(d);
	}
}

void Tower::moveTopTo(Tower & t) {
	// Move the top disk of this tower to the top of t.
}

void Tower::moveDisks(int n, Tower & destination, Tower & buffer) {
	// Move n Disks from this tower to destination by buffer tower
}

stack<int> Tower::getDisks() {
	// write your code here
	return disks;
}

void Tower::test() {
	// write your test here
	vector<Tower> towers;
	for (int i = 0; i < 3; i++)
		towers.push_back(Tower(i));

	// input
	int n;
	cin >> n;
	for (int i = n - 1; i >= 0; i--)
		towers[0].add(i);
	towers[0].moveDisks(n, towers[2], towers[1]);

}

#pragma once
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

class Tower {
private:
	stack<int> disks;
public:
	/*
	* @param i: An integer from 0 to 2
	*/
	Tower(int i);

	/*
	 * @param d: An integer
	 * @return: nothing
	 */
	void add(int d);

	/*
	 * @param t: a tower
	 * @return: nothing
	 */
	void moveTopTo(Tower &t);

	/*
	 * @param n: An integer
	 * @param destination: a tower
	 * @param buffer: a tower
	 * @return: nothing
	 */
	void moveDisks(int n, Tower &destination, Tower &buffer);

	/*
	 * @return: Disks
	 */
	stack<int> getDisks();

	void test();
};

/**
 * Your Tower object will be instantiated and called as such:
 * vector<Tower> towers;
 * for (int i = 0; i < 3; i++) towers.push_back(Tower(i));
 * for (int i = n - 1; i >= 0; i--) towers[0].add(i);
 * towers[0].moveDisks(n, towers[2], towers[1]);
 * print towers[0], towers[1], towers[2]
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution_128 {
public:
	/**
	 * @param key: A string you should hash
	 * @param HASH_SIZE: An integer
	 * @return: An integer
	 */
	int hashCode(string &key, int HASH_SIZE);
	int hashCode_2(string &key, int HASH_SIZE);
	void test();
};
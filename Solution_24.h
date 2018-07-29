#pragma once
#include <map>
#include <list>
using namespace std;

class LFUCache {
public:
	/*
	* @param capacity: An integer
	*/
	LFUCache(int capacity);

	/*
	* @param key: An integer
	* @param value: An integer
	* @return: nothing
	*/
	void set(int key, int value);

	/*
	* @param key: An integer
	* @return: An integer
	*/
	int get(int key);

private:
	int capacity;
	map<int, int> mapValue;
	map<int, int> mapFrequency;
};
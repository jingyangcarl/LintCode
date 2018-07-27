#pragma once
#include <string>
#include <algorithm>
using namespace std;

class Solution_13 {
public:
	/*
	* @param source: source string to be scanned.
	* @param target: target string containing the sequence of characters to match
	* @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
	*/
	int strStr(const char *source, const char *target);
};
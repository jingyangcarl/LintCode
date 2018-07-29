#include "Solution_22.h"

vector<int> Solution_22::flatten(vector<NestedInteger>& nestedList) {
	// Write your code here

	vector<int> result, temp;
	for (vector<NestedInteger>::iterator iter = nestedList.begin(); iter != nestedList.end(); iter++) {

		flatten(temp, *iter);
		for (vector<int>::iterator iter = temp.begin(); iter != temp.end(); iter++) {
			result.push_back(*iter);
		}
	}

	return result;
}

void Solution_22::flatten(vector<int>& result, NestedInteger& nestedList) {

	if (nestedList.isInteger()) result.push_back(nestedList.getInteger());
	else {
		vector<NestedInteger> lists = nestedList.getList();
		for (vector<NestedInteger>::iterator iter = lists.begin(); iter != lists.end(); iter++) {
			flatten(result, *iter);
		}
	}
}

bool NestedInteger::isInteger() const
{
	return false;
}

int NestedInteger::getInteger() const
{
	return 0;
}

const vector<NestedInteger>& NestedInteger::getList() const
{
	// TODO: 在此处插入 return 语句

	vector<NestedInteger> result;
	return result;
}

#pragma once
#include <iostream>
#include <vector>
using namespace std;

// Definition of singly - linked - list:
class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

class Solution_167 {
public:
	/**
	 * @param l1: the first list
	 * @param l2: the second list
	 * @return: the sum list of l1 and l2
	 */
	ListNode * addLists(ListNode * l1, ListNode * l2);
	void test();
};
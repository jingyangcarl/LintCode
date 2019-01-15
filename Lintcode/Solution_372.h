#pragma once
#include <iostream>
using namespace std;

// Definition of ListNode
class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

class Solution_372 {
public:
	/*
	 * @param node: the node in the list should be deletedt
	 * @return: nothing
	 */
	void deleteNode(ListNode * node);
	void deleteNode_2(ListNode * node);
	void test();
};
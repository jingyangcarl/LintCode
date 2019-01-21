#pragma once
#include <iostream>
using namespace std;

// Definition of singly-linked-list:
class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

class Solution_451 {
public:
	/**
	 * @param head: a ListNode
	 * @return: a ListNode
	 */
	ListNode * swapPairs(ListNode * head);
	void test();
};
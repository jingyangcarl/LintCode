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

class Solution_452 {
public:
	/**
	 * @param head: a ListNode
	 * @param val: An integer
	 * @return: a ListNode
	 */
	ListNode * removeElements(ListNode * head, int val);
	void test();
};
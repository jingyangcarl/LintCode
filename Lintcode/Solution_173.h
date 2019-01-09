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

class Solution {
public:
	/**
	 * @param head: The first node of linked list.
	 * @return: The head of linked list.
	 */
	ListNode * insertionSortList(ListNode * head);
	void test();
};
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

class Solution_112 {
public:
	/**
	 * @param head: head is the head of the linked list
	 * @return: head of linked list
	 */
	ListNode * deleteDuplicates(ListNode * head);
	void test();
};
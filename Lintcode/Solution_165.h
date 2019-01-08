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

class Solution_165 {
public:
	/**
	 * @param l1: ListNode l1 is the head of the linked list
	 * @param l2: ListNode l2 is the head of the linked list
	 * @return: ListNode head of linked list
	 */
	ListNode * mergeTwoLists(ListNode * l1, ListNode * l2);
	void test();
};
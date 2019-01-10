#pragma once
#include <iostream>
#include <vector>
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

class Solution_174 {
public:
	/**
	 * @param head: The first node of linked list.
	 * @param n: An integer
	 * @return: The head of linked list.
	 */
	ListNode * removeNthFromEnd(ListNode * head, int n);
	void test();
};
#pragma once
#include <iostream>
#include <vector>
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

class Solution_166 {
public:
	/*
	 * @param head: The first node of linked list.
	 * @param n: An integer
	 * @return: Nth to last node of a singly linked list.
	 */
	ListNode * nthToLast(ListNode * head, int n);
	void test();
};
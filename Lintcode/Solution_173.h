#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
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

class Solution_173 {
public:
	/**
	 * @param head: The first node of linked list.
	 * @return: The head of linked list.
	 */
	ListNode * insertionSortList(ListNode * head);
	static bool cmp(const ListNode a, const ListNode b);
	void test();
};
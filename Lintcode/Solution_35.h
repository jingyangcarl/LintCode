#pragma once
#include <iostream>
#include <stack>
using namespace std;
/**
 * Definition of singly-linked-list:
 */
class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

class Solution_35 {
public:
	/**
	 * @param head: n
	 * @return: The new head of reversed linked list.
	 */
	void test();
	ListNode * reverse(ListNode * head);
};
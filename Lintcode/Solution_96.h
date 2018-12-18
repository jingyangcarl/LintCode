#pragma once
#include <iostream>
#include <queue>
using namespace std;

// Definition of singly - linked - list:
class ListNode {
public:
	int val;
	ListNode *next;
	ListNode(int val) {
		this->val = val;
		this->next = NULL;
	}
};

class Solution_96 {
public:
	/**
	 * @param head: The first node of linked list
	 * @param x: An integer
	 * @return: A ListNode
	 */
	ListNode * partition(ListNode * head, int x);
	ListNode * partition_2(ListNode * head, int x);
	void create(ListNode * &head);
	void test();

};
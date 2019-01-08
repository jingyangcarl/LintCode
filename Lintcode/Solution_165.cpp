#include "Solution_165.h"

ListNode * Solution_165::mergeTwoLists(ListNode * l1, ListNode * l2) {
	// write your code here

	ListNode *l3 = new ListNode(0);
	ListNode *p1(l1), *p2(l2), *p3(l3);

	while (p1 && p2) {
		if (p1->val <= p2->val) {
			l3->next = p1;
			p1 = p1->next;
			l3 = l3->next;
		}
		else {
			l3->next = p2;
			p2 = p2->next;
			l3 = l3->next;
		}
	}

	if (!p1) l3->next = p2;
	if (!p2) l3->next = p1;

	return p3->next;
}

void Solution_165::test() {
	// write your test here

	// input;
	ListNode *l1 = new ListNode(0);
	ListNode *l2 = new ListNode(0);
	ListNode *l3, *p;

	int n;
	cin >> n;
	p = l1;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		p->next = new ListNode(num);
		p = p->next;
	}
	l1 = l1->next;
	cin >> n;
	p = l2;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		p->next = new ListNode(num);
		p = p->next;
	}
	l2 = l2->next;

	// algorithm
	l3 = mergeTwoLists(l1, l2);

	// output
	ListNode *iter = l3;
	while (iter) {
		cout << iter->val << ' ';
		iter = iter->next;
	}
}

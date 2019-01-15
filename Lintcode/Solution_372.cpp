#include "Solution_372.h"

void Solution_372::deleteNode(ListNode * node) {
	// write your code here

	ListNode *pre(node), *p(node->next);
	while (p) {
		pre->val = p->val;
		p = p->next;
		if (!p) pre->next = NULL;
		else pre = pre->next;
	}
}

void Solution_372::test() {
	// write your test here
	int n;
	cin >> n;
	ListNode *head = new ListNode(0);
	ListNode *p(head);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		p->next = new ListNode(num);
		p = p->next;
	}
	head = head->next;

	// algorithm
	deleteNode(head);

	// output
	p = head;
	while (p) {
		cout << p->val << ' ';
		p = p->next;
	}
}


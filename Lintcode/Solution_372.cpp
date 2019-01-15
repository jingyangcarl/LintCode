#include "Solution_372.h"

void Solution_372::deleteNode(ListNode * node) {
	// write your code here
	ListNode *p(node);
	while (p->next) {
		p->val = p->next->val;
		p = p->next;
	}
	p->next = NULL;
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


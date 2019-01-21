#include "Solution_451.h"

ListNode * Solution_451::swapPairs(ListNode * head) {
	// write your code here

	if (!head) return head;
	ListNode *newHead = new ListNode(0);
	newHead->next = head;
	ListNode *pre(newHead), *p(head), *q(head->next);
	while (p && q) {
		// swap
		p->next = q->next;
		q->next = p;
		pre->next = q;

		// move
		pre = p;
		p = pre->next;
		if(p) q = p->next;
	}

	return newHead->next;
}

void Solution_451::test() {
	// write your test here

	// input
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
	head = swapPairs(head);

	// output
	p = head;
	while (p) {
		cout << p->val << ' ';
		p = p->next;
	}
}

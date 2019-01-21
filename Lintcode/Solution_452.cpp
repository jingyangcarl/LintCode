#include "Solution_452.h"

ListNode * Solution_452::removeElements(ListNode * head, int val) {
	// write your code here

	ListNode *newHead = new ListNode(0);
	newHead->next = head;
	ListNode *pre(newHead), *p(head);
	while (p) {
		if (p->val == val) {
			pre->next = p->next;
			p = pre->next;
		}
		else {
			pre = p;
			p = p->next;
		}
	}

	return newHead->next;
}

void Solution_452::test() {
	// write your test here
	
	// input
	int n;
	cin >> n;
	ListNode * head = new ListNode(0);
	ListNode *p(head);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		p->next = new ListNode(num);
		p = p->next;
	}
	head = head->next;
	int val;
	cin >> val;

	// algorithm
	head = removeElements(head, val);

	// output;
	p = head;
	while (p) {
		cout << p->val << ' ';
		p = p->next;
	}
}

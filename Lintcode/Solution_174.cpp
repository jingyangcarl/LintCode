#include "Solution_174.h"

ListNode * Solution_174::removeNthFromEnd(ListNode * head, int n) {
	// write your code here

	vector<ListNode *> nodeVec;
	ListNode *p(head);
	while (p) {
		nodeVec.push_back(p);
		p = p->next;
	}

	nodeVec[nodeVec.size() - n - 1]->next = nodeVec[nodeVec.size() - n + 1];

	return head;
}

void Solution_174::test() {
	// write your test here

	// input
	int n;
	cin >> n;
	ListNode *head = new ListNode(0);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		head->next = new ListNode(num);
	}
	head = head->next;
	cin >> n;

	// algorithm
	head = removeNthFromEnd(head, n);

	// output;
	ListNode *p(head);
	while (p) {
		cout << p->val << ' ';
		p = p->next;
	}
}

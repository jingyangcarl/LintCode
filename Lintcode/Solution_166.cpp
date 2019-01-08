#include "Solution_166.h"

ListNode * Solution_166::nthToLast(ListNode * head, int n) {
	// write your code here

	static vector<ListNode> nodeVector;
	ListNode *p(head);
	while (p) {
		nodeVector.push_back(*p);
		p = p->next;
	}

	return &nodeVector[nodeVector.size() - n];
}

void Solution_166::test() {
	// write your test here

	// input
	int n;
	cin >> n;
	ListNode *l = new ListNode(0);
	ListNode *p(l);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		p->next = new ListNode(num);
		p = p->next;
	}
	l = l->next;
	cin >> n;

	// algorithm
	ListNode * node = nthToLast(l, n);

	// output;
	cout << node->val;
}

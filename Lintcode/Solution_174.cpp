#include "Solution_174.h"

ListNode * Solution_174::removeNthFromEnd(ListNode * head, int n) {
	// write your code here

	// add head
	ListNode *newHead = new ListNode(0);
	newHead->next = head;

	// save pointers in the vector with a NULL at the end
	vector<ListNode *> nodeVec;
	ListNode *p(newHead);
	while (p) {
		nodeVec.push_back(p);
		p = p->next;
	}
	nodeVec.push_back(NULL);

	nodeVec[nodeVec.size() - n - 2]->next = nodeVec[nodeVec.size() - n];

	return newHead->next;
}

void Solution_174::test() {
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
	cin >> n;

	// algorithm
	head = removeNthFromEnd(head, n);

	// output;
	p = head;
	while (p) {
		cout << p->val << ' ';
		p = p->next;
	}
}

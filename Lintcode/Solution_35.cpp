#include "Solution_35.h"

void Solution_35::test() {
	// write your test here

	// Carl: initialization
	int n;
	cin >> n;
	ListNode *listNode = new ListNode(0);
	ListNode *temp = listNode;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		temp->next = new ListNode(val);
		temp = temp->next;
	}
	listNode = listNode->next;

	// Carl: reverse
	listNode = reverse(listNode);

	// Carl: output
	if (listNode) {
		while (listNode->next) {
			cout << listNode->val << "->";
			listNode = listNode->next;
		}
		cout << listNode->val;
	}
}

ListNode * Solution_35::reverse(ListNode * head) {
	// write your code here

	static ListNode *rvsNode = new ListNode(0);
	static stack<ListNode> nodeStack;
	ListNode *temp(NULL);

	temp = head;
	while (temp) {
		ListNode node = *temp;
		node.next = NULL;
		nodeStack.push(node);
		temp = temp->next;
	}

	temp = rvsNode;
	while (!nodeStack.empty()) {
		temp->next = &(nodeStack.top());
		nodeStack.pop();
		temp = temp->next;
	}
	rvsNode = rvsNode->next;

	return rvsNode;
}
#include "Solution_112.h"

ListNode * Solution_112::deleteDuplicates(ListNode * head) {
	// write your code here
	ListNode *headedList = new ListNode(0);
	headedList->next = head;
	ListNode *pre(headedList), *current(headedList->next);
	int currentValue(-1);
	while (current) {
		if (current->val == currentValue) {
			pre->next = current->next;
			current = pre->next;
		}
		else {
			currentValue = current->val;
			pre = pre->next;
			current = current->next;
		}
	}
	return headedList->next;
}

void Solution_112::test() {
	// input;
	int n;
	cin >> n;
	ListNode *head = new ListNode(0);
	ListNode *temp = head;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		temp->next = new ListNode(val);
		temp = temp->next;
	}
	head = head->next;

	// algorithm
	head = deleteDuplicates(head);

	// output
	temp = head;
	while (temp) {
		cout << temp->val << " ";
		temp = temp->next;
	}
}

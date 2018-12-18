#include "Solution_96.h"

ListNode * Solution_96::partition(ListNode * head, int x) {
	// write your code here

	// Carl:
	// Idea:
	// do a loop and pick up the nodes larger or equal than the given value into a queue
	// with other nodes remaining order unchanged and saving in another queue

	ListNode *iter(head);
	queue<ListNode> smaller, larger;
	while (iter) {
		if (iter->val < x) smaller.push(*iter);
		else larger.push(*iter);
		iter = iter->next;
	}

	ListNode *newList = new ListNode(0);
	iter = newList;
	while (!smaller.empty()) {
		smaller.front().next = NULL;
		iter->next = &smaller.front();
		smaller.pop();
		iter = iter->next;
	}
	while (!larger.empty()) {
		larger.front().next = NULL;
		iter->next = &larger.front();
		larger.pop();
		iter = iter->next;
	}

	return newList->next;
}

ListNode * Solution_96::partition_2(ListNode * head, int x) {
	// write your code here

	// Carl:
	// Idea:
	// the same idea but without queue

	ListNode *headedList = new ListNode(0), *pickupedList = new ListNode(0);
	headedList->next = head;
	ListNode *previous(headedList), *current(headedList->next), *pickups(pickupedList);
	while (current) {
		if (current->val >= x) {
			// remove the current node from headedList
			previous->next = current->next;
			// add the current node into pickupedList
			current->next = NULL;
			pickups->next = current;
			pickups = pickups->next;
			// relocate the current node
			current = previous->next;
		}
		else {
			current = current->next;
			previous = previous->next;
		}
	}
	previous->next = pickupedList->next;
	return headedList->next;
}

void Solution_96::create(ListNode * &head) {
	int n;
	cin >> n;
	head = new ListNode(0);
	ListNode *iter(head);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		iter->next = new ListNode(num);
		iter = iter->next;
	}
	head = head->next;
}

void Solution_96::test() {
	// input
	ListNode * head(NULL);
	create(head);

	// algorithm
	int n;
	cin >> n;
	head = partition_2(head, n);

	// output
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
}
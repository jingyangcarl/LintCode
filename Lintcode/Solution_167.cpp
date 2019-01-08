#include "Solution_167.h"

ListNode * Solution::addLists(ListNode * l1, ListNode * l2) {
	// write your code here

	long long num1(0), num2(0), sum(0);
	vector<int> digits;
	ListNode *p;
	p = l1;
	while (p) {
		digits.push_back(p->val);
		p = p->next;
	}
	while (!digits.empty()) {
		num1 += digits.back();
		digits.pop_back();
		num1 *= 10;
	}
	num1 /= 10;
	p = l2;
	while (p) {
		digits.push_back(p->val);
		p = p->next;
	}
	while (!digits.empty()) {
		num2 += digits.back();
		digits.pop_back();
		num2 *= 10;
	}
	num2 /= 10;

	sum = num1 + num2;

	ListNode *result = new ListNode(0);
	p = result;
	while (sum != 0) {
		int digit = sum % 10;
		sum /= 10;
		p->next = new ListNode(digit);
		p = p->next;
	}
}

void Solution::test() {
	// write your test here

	// input
	ListNode *l1 = new ListNode(0);
	ListNode *l2 = new ListNode(0);
	ListNode *p;
	int n;
	cin >> n;
	p = l1;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		p->next = new ListNode(num);
		p = p->next;
	}
	l1 = l1->next;
	cin >> n;
	p = l2;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		p->next = new ListNode(num);
		p = p->next;
	}
	l2 = l2->next;

	// algorithm
	ListNode *l3 = addLists(l1, l2);

	// output
	p = l3;
	while (p) {
		cout << p->val << ' ';
		p = p->next;
	}
}

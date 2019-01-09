#include "Solution_167.h"

ListNode * Solution_167::addLists(ListNode * l1, ListNode * l2) {
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
	if (sum == 0) return result;
	while (sum != 0) {
		int digit = sum % 10;
		sum /= 10;
		p->next = new ListNode(digit);
		p = p->next;
	}

	return result->next;

	// ERROR: cannot deal with really large number
}

ListNode * Solution_167::addLists_2(ListNode * l1, ListNode * l2) {
	// write your code here

	ListNode *l3 = new ListNode(0);
	ListNode *p1(l1), *p2(l2), *p3(l3);
	bool carry(false);

	while (p1 && p2) {
		p3->next = new ListNode(p1->val + p2->val + carry ? 1 : 0);
		p1 = p1->next;
		p2 = p2->next;
		p3 = p3->next;
		if (p3->val >= 10) {
			carry = true;
			p3->val /= 10;
		}
		else carry = false;
	}
	if (p1) p3->next = p2;
	if (p2) p3->next = p1;
	p3 = p3->next;
	while (p3) {
		p3->val += carry ? 1 : 0;
		if (p3->val >= 10) {
			carry = true;
			p3->val /= 10;
		}
		else carry = false;
	}

	return l3->next;
}

void Solution_167::test() {
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
	ListNode *l3 = addLists_2(l1, l2);

	// output
	p = l3;
	while (p) {
		cout << p->val << ' ';
		p = p->next;
	}
}

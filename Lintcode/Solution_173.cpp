#include "Solution_173.h"

ListNode * Solution_173::insertionSortList(ListNode * head) {
	// write your code here

	static vector<ListNode> NodeList;
	ListNode *p(head);
	while (p) {
		ListNode current = *p;
		current.next = NULL;
		NodeList.push_back(current);
		p = p->next;
	}

	sort(NodeList.begin(), NodeList.end(), cmp);

	ListNode *result = new ListNode(0);
	p = result;
	for (int i = 0; i < NodeList.size(); i++) {
		p->next = &NodeList[i];
		p = p->next;
	}

	return result->next;
}

ListNode * Solution_173::insertionSortList_2(ListNode * head) {
	// write your code here

	ListNode *result = new ListNode(0);
	ListNode *origin = new ListNode(0);
	origin->next = head;
	ListNode *pRes(result), *pOri(origin), *pParent(origin);
	pOri = pOri->next;
	while (pOri) {
		long long min(LONG_MAX);
		ListNode *pCurrent(NULL), *pCurPar(NULL);
		while (pOri) {
			if (pOri->val < min) {
				min = pOri->val;
				pCurPar = pParent;
				pCurrent = pOri;
			}
			pParent = pOri;
			pOri = pOri->next;
		}

		// remove the node from origin to the result;
		pCurPar->next = pCurrent->next;
		pCurrent->next = NULL;
		pRes->next = pCurrent;
		pRes = pRes->next;
		
		// initialization
		pOri = origin->next;
		pParent = origin;
	}

	return result->next;
}

bool Solution_173::cmp(const ListNode a, const ListNode b) {
	return a.val < b.val;
}

void Solution_173::test() {
	// write your test here

	// input
	ListNode *head = new ListNode(0);
	ListNode *p(head);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		p->next = new ListNode(num);
		p = p->next;
	}
	head = head->next;

	// algorithm
	head = insertionSortList_2(head);

	// output
	p = head;
	while (p) {
		cout << p->val << ' ';
		p = p->next;
	}


}


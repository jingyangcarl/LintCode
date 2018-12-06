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

	// Carl: 
	// C++ cannot return the pointer without the declaration of STATIC
	// the runtime memory consists of heap and stack, where
	// the heap lives with the main function
	// the stack lives with its funtions
	// if the nodeStack (stack<ListNode>) are not denoted as static, the variables will be collected when the funtion finished
	// so as the rvsNode (ListNode),
	// leading to the random result back to the calling function
	// for details: see Onenote/Computer/CPP/QA - 函数能否返回局部指针变量
	static ListNode *rvsNode = new ListNode(0);
	static stack<ListNode> nodeStack;
	ListNode *temp(NULL);

	// Carl: push elements
	temp = head;
	while (temp) {
		ListNode node = *temp;
		node.next = NULL;
		nodeStack.push(node);
		temp = temp->next;
	}

	// Carl: reverse elements
	temp = rvsNode;
	while (!nodeStack.empty()) {
		temp->next = &(nodeStack.top());
		nodeStack.pop();
		temp = temp->next;
	}

	// Carl: return
	return rvsNode->next;
}
#include "Solution_5.h"
#include <vector>
#include <queue>
#include <algorithm>
#include <Windows.h>
#include <iostream>
using namespace std;

int Solution_5::kthLargestElement(int n, vector<int> &nums) {

	// Carl: sort elements in vector
	sort(nums.begin(), nums.end());
	
	vector<int>::iterator iter = nums.end();
	for (int i = 0; i < n; i++) iter--;

	return *iter;
}

int Solution_5::kthLargestElement_2(int n, vector<int> &nums) {

	// Carl: priority_queue
	priority_queue<int> queue(nums.begin(), nums.end());
	for (int i = 0; i < n-1; i++) queue.pop();

	return queue.top();
}

int Solution_5::kthLargestElement_3(int n, vector<int>& nums) {

	// Carl: quick sort methodology
	int left = 0, right = nums.size() - 1;
	while (1) {
		int position = partitionLarge(nums, left, right);
		if (position == n - 1) return nums.at(position);
		else if (position > n - 1) right = position - 1;
		else left = position + 1;
	}

	return 0;
}

int Solution_5::partitionLarge(vector<int>& nums, int left, int right) {

	// Carl: find out the kth large element
	int tag = nums.at(left), l = left + 1, r = right;
	while (l <= r) {
		if (nums.at(l) < tag && nums.at(r) > tag) swap(nums.at(l++), nums.at(r--));
		else if (nums.at(l) >= tag) l++;
		else if (nums.at(r) <= tag) r--;
	}
	swap(nums.at(left), nums.at(r));

	return r;
}

int Solution_5::partitionSmall(vector<int>& nums, int left, int right) {

	// Carl: find out the kth small element
	int tag = nums.at(left), l = left + 1, r = right;
	while (l <= r) {
		if (nums.at(l) > tag && nums.at(r) < tag) swap(nums.at(l++), nums.at(r--));
		else if (nums.at(l) <= tag) l++;
		else if (nums.at(r) >= tag) r--;
	}
	swap(nums.at(left), nums.at(r));

	return r;
}

int Solution_5::runningTest(int n, vector<int>& nums) {
	
	LARGE_INTEGER startTime;
	LARGE_INTEGER endTime;
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);

	QueryPerformanceCounter(&startTime);
	cout << kthLargestElement(n, nums) << endl;
	QueryPerformanceCounter(&endTime);
	cout << "Running time 1: " << (double)(endTime.QuadPart - startTime.QuadPart) / frequency.QuadPart << endl;

	QueryPerformanceCounter(&startTime);
	cout << kthLargestElement_2(n, nums) << endl;
	QueryPerformanceCounter(&endTime);
	cout << "Running time 2: " << (double)(endTime.QuadPart - startTime.QuadPart) / frequency.QuadPart << endl;

	return 0;
}

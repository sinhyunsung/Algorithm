#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>
#include <bitset>
#include <queue>
#include <unordered_map>

using namespace std;

int li[100001];
int n;

void heapify(int idx) {
	int left = idx * 2;
	int right = idx * 2 + 1;
	int target = idx;
	if (left <= n && li[left] < li[target]) {
		target = left;
	}
	if (right <= n && li[right] < li[target]) {
		target = right;
	}
	if (target != idx) {
		swap(li[target], li[idx]);
		heapify(target);
	}
}

int pop() {
	swap(li[1], li[n]);
	int temp = li[n];
	n -= 1;
	heapify(1);
	return temp;
}

void push(int target) {
	n++;
	li[n] = target;
	int idx = n;
	while (idx > 1 && li[idx] < li[idx / 2]) {
		swap(li[idx], li[idx / 2]);
		idx /= 2;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> li[i];
	}

	int result = 0;

	for (int i = n / 2; i >= 1; i--) {
		heapify(i);
	}

	while (n != 1) {
		int a = pop();
		int b = pop();
		result += a + b;
		push(a + b);
	}
	cout << result;

}
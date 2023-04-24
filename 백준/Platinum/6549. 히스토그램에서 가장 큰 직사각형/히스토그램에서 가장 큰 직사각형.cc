#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <cmath>

using namespace std;

#define ll long long

int n;
long long v[100000];
long long tree[400000];
long long result;

int init(int idx, int start, int end) {
	if (start == end) {
		tree[idx] = start;
		return tree[idx];
	}
	int mid = (start + end) / 2;
	int left= init(idx * 2, start, mid);
	int right= init(idx * 2+1, mid+1, end);
	if (v[left] < v[right]) {
		tree[idx] = left;
	}
	else {
		tree[idx] = right;
	}
	return tree[idx];
}

int query(int idx, int start, int end, int left, int right) {
	if (start > right || end < left) {
		return -1;
	}
	if (left <= start && right >= end) {
		return tree[idx];
	}

	int mid = (start + end) / 2;
	int l = query(idx * 2, start, mid,left,right);
	int r = query(idx * 2 + 1, mid + 1, end,left,right);
	if (l == -1) {
		return r;
	}
	if (r == -1) {
		return l;
	}
	if (v[l] < v[r]) {
		return l;
	}
	else {
		return r;
	}
}

void search(int start, int end) {
	int min_idx = query(1, 0, n - 1, start, end);
	result = max(result, v[min_idx] * (end - start + 1));
	if (start < min_idx) {
		search(start, min_idx - 1);
	}
	if (end > min_idx) {
		search(min_idx+1, end);
	}
}


void solve() {
	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		init(1, 0, n - 1);
		result = 0;
		search(0, n - 1);
		cout << result << "\n";
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	
}
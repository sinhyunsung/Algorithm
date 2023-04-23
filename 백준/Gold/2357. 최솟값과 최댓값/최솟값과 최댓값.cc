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

int n, m;
int v[100000];
pair<int, int> tree[300000];

int init_max(int idx, int start, int end) {
	if (start == end) {
		tree[idx].first = v[start];
		return tree[idx].first;
	}
	int mid = (start + end) / 2;
	tree[idx].first = max(init_max(idx * 2, start, mid), init_max(idx * 2 + 1, mid + 1, end));
	return tree[idx].first;
}

int init_min(int idx, int start, int end) {
	if (start == end) {
		tree[idx].second = v[start];
		return tree[idx].second;
	}
	int mid = (start + end) / 2;
	tree[idx].second = min(init_min(idx * 2, start, mid), init_min(idx * 2 + 1, mid + 1, end));
	return tree[idx].second;
}

int get_max(int idx, int start, int end, int ts, int te) {
	if (start >= ts && end <= te) {
		return tree[idx].first;
	}
	if (start > te || end < ts) {
		return 0;
	}
	int mid = (start + end) / 2;
	return max(get_max(idx * 2, start, mid, ts, te), get_max(idx * 2 + 1, mid + 1, end, ts, te));
}

int get_min(int idx, int start, int end, int ts, int te) {
	if (start >= ts && end <= te) {
		return tree[idx].second;
	}
	if (start > te || end < ts) {
		return 1000000001;
	}
	int mid = (start + end) / 2;
	return min(get_min(idx * 2, start, mid, ts, te), get_min(idx * 2 + 1, mid + 1, end, ts, te));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	init_max(1, 0, n - 1);
	init_min(1, 0, n - 1);

	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		cout << get_min(1, 0, n - 1, a-1, b-1) << " " << get_max(1, 0, n - 1, a-1, b-1) << "\n";
	}
	
}
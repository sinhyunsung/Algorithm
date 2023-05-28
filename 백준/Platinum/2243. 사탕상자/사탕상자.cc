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
#include <string>

using namespace std;

#define ll long long

int n;
int tree[4000000] = { 0 };

void update(int node, int target, int value, int start, int end) {
	if (target<start || target> end) {
		return;
	}
	tree[node] += value;
	if (start != end) {
		int mid = (start + end) / 2;
		update(node * 2, target, value, start, mid);
		update(node * 2+1, target, value, mid+1, end);
	}
}

int query(int node, int target, int start, int end) {
	if (start == end) {
		return start;
	}
	int mid = (start + end) / 2;
	if (tree[node*2] >= target) {
		return query(node * 2, target, start, mid);
	}
	else {
		return query(node * 2+1, target - tree[node*2], mid+1, end);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int a, b, c;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a == 2) {
			cin >> c;
			update(1, b, c, 1, 1000000);
			continue;
		}
		int result = query(1, b, 1, 1000000);
		cout << result << "\n";
		update(1, result, -1, 1, 1000000);

	}
	

}
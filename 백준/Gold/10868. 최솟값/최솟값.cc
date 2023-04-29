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

ll n,m;
ll arr[100000];
ll tree[400000];
ll result = 0;

ll init(ll node, ll start, ll end) {
	if (start == end) {
		tree[node] = arr[start];
		return tree[node];
	}
	ll mid = (start + end) >> 1;
	tree[node] = min(init(node * 2, start, mid) , init(node * 2 + 1, mid + 1, end));
	return tree[node];
}

ll query(ll node, ll start, ll end, ll left, ll right) {
	if (left <= start && right >= end) {
		return tree[node];
	}
	if (start > right || end < left) {
		return 1000000001;
	}
	ll mid = (start + end) >> 1;
	return min(query(node * 2, start, mid, left, right) , query(node * 2 + 1, mid + 1, end, left, right));
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(1, 0, n - 1);
	ll a, b;
	for (ll i = 0; i < m; i++) {
		cin >> a >> b;
		cout << query(1, 0, n - 1, a-1, b-1)<<"\n";
	}
	
}
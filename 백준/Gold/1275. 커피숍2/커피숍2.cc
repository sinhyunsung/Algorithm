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

ll n, q;
ll v[100000];
ll tree[400000];

ll init(ll node, ll start, ll end) {
	if (start == end) {
		tree[node] = v[start];
		return tree[node];
	}
	ll mid = (start + end) / 2;
	tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
	return tree[node];
}

void update(ll node,ll idx, ll value, ll start, ll end) {
	if (idx<start || idx>end) {
		return;
	}
	tree[node] += value;
	if (start != end) {
		ll mid = (start + end) / 2;
		update(node * 2, idx, value, start, mid);
		update(node * 2 + 1, idx, value, mid + 1, end);
	}
}

ll query(ll node, ll s_v, ll e_v, ll start, ll end) {
	if (e_v<start || s_v>end) {
		return 0;
	}
	if (s_v <= start && e_v >= end) {
		return tree[node];
	}
	ll mid = (start + end) / 2;
	return query(node * 2, s_v, e_v, start, mid) + query(node * 2 + 1, s_v, e_v, mid+1, end);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	init(1, 0, n - 1);
	ll x, y, a, b;
	for (int i = 0; i < q; i++) {
		cin >> x >> y >> a >> b;
		if (x > y) {
			swap(x, y);
		}
		cout << query(1, x-1, y-1, 0, n - 1) << "\n";
		update(1,a-1, b-v[a-1], 0, n - 1);
		v[a-1] = b;
	}


	

}
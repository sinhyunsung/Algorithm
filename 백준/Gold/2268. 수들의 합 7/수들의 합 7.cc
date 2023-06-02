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

ll tree[4000000] = { 0 };
ll n, m;

void update(ll node, ll target, ll value, ll start, ll end) {
	if (target<start || target>end) {
		return;
	}
	if (start != end) {
		ll mid = (start + end) / 2;
		update(node * 2, target, value, start, mid);
		update(node * 2+1, target, value, mid+1, end);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
		return;
	}
	if(start==target){
		tree[node] = value;
	}
}

ll sum(ll node, ll v_s, ll v_e, ll start, ll end) {
	if (v_e<start || v_s>end) {
		return 0;
	}
	if (v_s <= start && v_e >= end) {
		return tree[node];
	}
	ll mid = (start + end) / 2;
	return sum(node * 2, v_s, v_e, start, mid)+ sum(node * 2+1, v_s, v_e, mid+1, end);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	ll a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, b - 1, c, 0, n - 1);
		}
		else {
			if (b > c) {
				swap(b, c);
			}
			cout << sum(1, b - 1, c - 1, 0, n - 1) << "\n";
		}
	}

}
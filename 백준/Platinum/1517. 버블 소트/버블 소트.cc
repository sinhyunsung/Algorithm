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

vector<pair<ll, ll>> arr;
ll n;
ll tree[2000000];
ll result = 0;

ll init(ll node, ll start, ll end) {
	if (start == end) {
		tree[node] = 1;
		return 1;
	}
	ll mid = (start + end) >> 1;
	tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
	return tree[node];
}

ll query(ll node, ll start, ll end, ll left, ll right) {
	if (left <= start && right >= end) {
		return tree[node];
	}
	if (start > right || end < left) {
		return 0;
	}
	ll mid = (start + end) >> 1;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

void update(ll node, ll start, ll end, ll target) {


	if (start <= target && end >= target) {

		if (start == end) {
			tree[node] -= 1;
			return;
		}
		tree[node] -= 1;
		ll mid = (start + end) >> 1;
		update(node * 2, start, mid, target);
		update(node * 2+1, mid+1, end, target);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	ll temp;
	for (ll i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(make_pair(temp, i+1));
	}
	sort(arr.begin(), arr.end());
	init(1, 1, n);
	for (ll i = 0; i < n; i++) {
		result += query(1,1,n, 1, arr[i].second)-1;
		update(1, 1, n, arr[i].second);
	}
	cout << result;
}
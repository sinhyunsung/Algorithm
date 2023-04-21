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

vector<ll> arr;
vector<ll> tree;

ll n, m, k;

ll init(ll node,ll start,ll end) {
	if (start == end) {
		return tree[node] = arr[start];
	}
	ll mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}
void update( ll node, ll start, ll end, ll index, ll diff)
{
	if (!(start <= index && index <= end))
		return;

	tree[node] += diff;

	if (start != end)
	{
		ll mid = (start + end) / 2;
		update( node * 2, start, mid, index, diff);
		update( node * 2 + 1, mid + 1, end, index, diff);
	}

}

ll sum(ll node, ll start, ll end, ll left, ll right)
{
	if (left > end || right < start)
		return 0;

	if (left <= start && end <= right)
		return tree[node];

	ll mid = (start + end) / 2;
	return sum( node * 2, start, mid, left, right) + sum( node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	ll num;
	arr.push_back(0);
	for (ll i = 0; i < n; i++) {
		cin >> num;
		arr.push_back(num);
	}

	ll h = (ll)ceil(log2(arr.size()));
	ll tree_size = (1 << (h + 1));

	for (ll i = 0; i <= tree_size; i++) {
		tree.push_back(0);
	}

	init(1, 1, arr.size()-1);
	
	ll a, b, c;


	for (ll i = 0; i < m + k; i++) {
		cin >> a >> b >> c;
		if (a == 1) {
			update(1, 1, n, b, c-arr[b]);
			arr[b] = c;
		}
		else {
			cout << sum(1, 1, n, b, c) << "\n";
		}
	}

	
	
}
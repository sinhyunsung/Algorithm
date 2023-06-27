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

ll n;
deque<pair<ll, ll>> q;
ll v[200001];


ll find(ll x) {
	if (v[x] == x) {
		return v[x];
	}
	v[x] = find(v[x]);
	return v[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	ll a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		q.push_back(make_pair(b, a));
	}
	for (int i = 0; i < 200001; i++) {
		v[i] = i;
	}

	sort(q.begin(), q.end());

	ll result = 0;

	while (!q.empty()) {
		b = q.back().first;
		a = q.back().second;
		int idx = find(a);
		if (idx != 0) {
			result += b;
			v[idx] -= 1;
		}
		q.pop_back();
	}
	cout << result;

}
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

ll n, k;

ll cnt(ll num) {
	ll result = 0;
	for (ll i = 1; i <= n; i++) {
		result += min(n, num / i);
	}
	return result;
}

ll binary_search(ll target) {
	ll left = 1;
	ll right = n * n;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (cnt(mid) < target) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return left;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;

	cout << binary_search(k);

}
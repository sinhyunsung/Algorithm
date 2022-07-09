#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define ll long long

unordered_map<ll, ll> dp;

ll n, p, q;

ll solve(ll x) {
	if (dp.find(x)==dp.end()) {
		dp[x] = solve(x / p) + solve(x / q);
		return dp[x];
	}
	else {
		return dp[x];
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	cin >> n >> p >> q;
	dp[0] = 1;
	cout << solve(n);


	
}
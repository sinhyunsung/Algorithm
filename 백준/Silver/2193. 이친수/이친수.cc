#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll dp[91][2];
	ll n;
	cin >> n;

	dp[1][1] = 1;
	dp[1][0] = 0;

	for (int i = 2; i <= n; i++) {
		dp[i][1] = dp[i - 1][0];
		dp[i][0] = dp[i - 1][0]+ dp[i - 1][1];
	}

	cout << dp[n][0] + dp[n][1];



}
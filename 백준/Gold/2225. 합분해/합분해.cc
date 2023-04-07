#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

#define ll long long


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	int dp[201][201] = { 0 };

	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
	}

	for (int k_idx = 2; k_idx <= k; k_idx++) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= i; j++) {
				dp[k_idx][i] += dp[k_idx - 1][j];
				dp[k_idx][i] %= 1000000000;
			}
		}
	}

	cout << dp[k][n];
}
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

	int n;
	cin >> n;

	int t[15];
	int p[15];

	int dp[15] = { 0 };

	for (int i = 0; i < n; i++) {
		cin >> t[i] >> p[i];

		dp[i] = max(dp[i - 1], dp[i]);
		if (i + t[i]-1 < n) {
			if (i != 0) {
				dp[i + t[i]-1] = max(dp[i + t[i]-1], dp[i - 1] + p[i]);
			}
			else {
				dp[i + t[i]-1] = max(dp[i + t[i]-1],  p[i]);
			}
		}
	}

	cout << dp[n - 1];


}
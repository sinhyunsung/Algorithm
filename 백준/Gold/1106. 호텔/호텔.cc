#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define ll long long


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	int c, n;

	cin >> c >> n;

	int dp[100001] = { 0 };
	int city[20][2];

	for (int i = 0; i < n; i++) {
		cin >> city[i][0] >> city[i][1];
	}
	
	dp[0] = 0;
	for (int i = 0; i < 100001; i++) {
		for (int j = 0; j < n; j++) {
			int prev_idx = i - city[j][0];
			if (prev_idx < 0) {
				continue;
			}
			dp[i] = max(dp[i], dp[prev_idx] + city[j][1]);
		}
	}

	int result = 100000000;

	for (int i = 0; i < 100001; i++) {
		if (dp[i] >= c && dp[i] > 0) {
			result = min(result, i);
			break;
		}
	}

	cout << result;
	
}
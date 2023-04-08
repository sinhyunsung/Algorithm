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

	int n;
	cin >> n;

	int dp[31][8] = { 0 };
	// 0 / 1 1 / 2 2 / 3 3 / 4 1,2 / 5 2,3 / 6 1,3 / 7 1,2,3
	dp[1][4] = 1;
	dp[1][5] = 1;
	dp[1][0] = 1;

	for (int i = 2; i < 31; i++) {
		dp[i][0] = dp[i - 1][7];
		dp[i][1] = dp[i - 1][5];
		dp[i][2] = dp[i - 1][6];
		dp[i][3] = dp[i - 1][4];
		dp[i][4] = dp[i - 1][3]+ dp[i - 1][7];
		dp[i][5] = dp[i - 1][1] + dp[i - 1][7];
		dp[i][6] = dp[i - 1][2];
		dp[i][7] = dp[i - 1][0] + dp[i - 1][5] + dp[i - 1][4];
	}

	cout << dp[n][7];

}
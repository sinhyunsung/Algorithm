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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int dp[100000][3] = { 0 };
	dp[0][0] = 1;
	dp[0][1] = 1;
	dp[0][2] = 1;

	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3];
		dp[i][1] = dp[i - 1][0] +  dp[i - 1][2] ;
		dp[i][2] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][0] %= 9901;
		dp[i][1] %= 9901;
		dp[i][2] %= 9901;
	}
	cout << (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % 9901;

}
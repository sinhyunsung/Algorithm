#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

#define ll long long


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	int n,l,r;

	cin >> n >> l >> r;

	ll dp[101][101][101] = { 0 };

	dp[1][1][1] = 1;
	
	for (int height = 2; height <= 100; height++) {
		for (int left = 1; left <= height; left++) {
			for (int right = 1; right <= height; right++) {
				dp[height][left][right] = (dp[height - 1][left - 1][right] + dp[height - 1][left][right - 1] + dp[height - 1][left][right] * (height - 2))% 1000000007;
			}
		}
	}

	cout << dp[n][l][r];



}
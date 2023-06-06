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

int n;
int v[100][100];
ll dp[100][100] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}

	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == n - 1 && j == n - 1) {
				break;
			}
			if (i + v[i][j] < n) {
				dp[i + v[i][j]][j] += dp[i][j];
			}
			if (j + v[i][j] < n) {
				dp[i][j + v[i][j]] += dp[i][j];
			}
		}
	}

	cout << dp[n-1][n-1];
}
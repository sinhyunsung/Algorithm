#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>
#include <bitset>
#include <queue>
#include <unordered_map>

using namespace std;

int n, m;
int v[1000][1000];
int dp[1000][1000] = { 0 };




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for(int j=0; j<m; j++){
			cin >> v[i][j];
		}
	}
	
	dp[0][0] = v[0][0];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (i + 1 < n) {
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + v[i + 1][j]);
			}
			if (j + 1 < m) {
				dp[i][j+1] = max(dp[i][j+1], dp[i][j] + v[i][j+1]);
			}
			if (j + 1 < m&& i + 1 < n) {
				dp[i+1][j + 1] = max(dp[i+1][j + 1], dp[i][j] + v[i+1][j + 1]);
			}
		}
	}
	
	cout << dp[n-1][m-1];


}
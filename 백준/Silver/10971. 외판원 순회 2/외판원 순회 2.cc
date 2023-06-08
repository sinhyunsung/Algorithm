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

int v[10][10];
int dp[10][1 << 10];


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

	for (int i = 0; i < n; i++) {
		fill_n(dp[i], (1 << 10), 100000000);
		if (v[0][i] != 0) {
			dp[i][1 << i] = v[0][i];
		}
	}

	for (int i = 1; i < (1 << 10); i++) {
		for (int cur = 0; cur < n; cur++) {
			if (i & (1 << cur)) {
				for (int pre = 0; pre < n; pre++) {
					if (dp[pre][i & !(1 << cur)] != 0 && v[pre][cur] != 0 && i | (1 << pre)) {
						dp[cur][i] = min(dp[cur][i], dp[pre][i & ~(1 << cur)] + v[pre][cur]);
					}
				}
			}
		}
	}
		
	cout << dp[0][(1 << n)-1];
}
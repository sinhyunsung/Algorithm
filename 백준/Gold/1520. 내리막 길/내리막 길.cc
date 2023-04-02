#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>

using namespace std;

#define ll long long

int my, mx;
int v[500][500];
int dp[500][500] = { 0 };

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


int dfs(int ty, int tx) {
	if (dp[ty][tx] == -1) {
		return 0;
	}
	if (dp[ty][tx] != 0) {
		return dp[ty][tx];
	}
	for (int i = 0; i < 4; i++) {
		int ddx = tx + dx[i];
		int ddy = ty + dy[i];
		if (ddx >= 0 && ddy >= 0 && ddx < mx && ddy < my) {
			if (v[ty][tx] > v[ddy][ddx]) {
				dp[ty][tx] += dfs(ddy, ddx);
			}
		}
	}
	if (dp[ty][tx] == 0) {
		dp[ty][tx] = -1;
		return 0;
	}
	return dp[ty][tx];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> my >> mx;

	for (int i = 0; i < my; i++) {
		for (int j = 0; j < mx; j++) {
			cin >> v[i][j];
		}
	}

	dp[my - 1][mx - 1] = 1;

	int result = dfs(0, 0);
	cout << result;


}
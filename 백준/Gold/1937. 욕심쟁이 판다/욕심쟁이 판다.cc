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
int v[500][500];
int dp[500][500] = { 0 };

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int move(int y, int x) {
	if (dp[y][x]!=0) {
		return dp[y][x];
	}

	dp[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ddx = x + dx[i];
		int ddy = y + dy[i];
		if (ddx >= 0 && ddy >= 0 && ddx < n && ddy < n && v[y][x] < v[ddy][ddx]) {
			dp[y][x] = max(dp[y][x], move(ddy, ddx) + 1);
		}
	}
	return dp[y][x];
}

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
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			result = max(result, move(i,j));
		}
	}
	cout << result;
}
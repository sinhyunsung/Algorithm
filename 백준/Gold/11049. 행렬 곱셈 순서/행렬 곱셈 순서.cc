#include <iostream> 
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n;

pair<int, int> li[501];
int dp[501][501] = { 0 };
pair<int, int> dpli[501][501];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n;
	int a, b;
	for (int i = 1; i <= n; i++) {
		
		cin >> a>>b;
		li[i] = make_pair(a, b);
		dpli[i][i] = li[i];
	}

	for (int i = 1; i < n; i++) {
		for (int x = 1; x+i <= n; x++) {
			dp[x][x+i] = 210000000;
			for (int mid = 0; mid <= i; mid++) {
				dp[x][x+i] = min(dp[x][x+i], dp[x ][x+mid] + dp[x+mid+1][x+i] + dpli[x][x+mid].first* dpli[x][x+mid].second * dpli[x+mid+1][x+i].second);
			}
			dpli[x][x+i].first = dpli[x][x].first;
			dpli[x][x+i].second = dpli[x+i][x+i].second;
		}
	}

	cout << dp[1][n];
}

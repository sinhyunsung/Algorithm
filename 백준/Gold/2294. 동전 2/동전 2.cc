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

	int n, m;
	int l[100];
	cin >> n >> m;

	int dp[10001];
	fill_n(dp, 10001, 100000000);

	int c;
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	sort(l,l+n);
	for (int i = 0; i < n; i++) {
		c = l[i];
		for (int j = c; j <= m; j ++) {
			dp[j] = min(dp[j], 1 + dp[j - c]);
		}
	}

	cout << (dp[m]!= 100000000 ?dp[m]:-1);

}
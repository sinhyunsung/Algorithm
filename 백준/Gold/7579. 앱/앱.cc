#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int n, m;
int a[100];
int b[100];
int dp[100][10001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	for (int j = 0; j < 10001; j++) {
		if (j >= b[0]) {
			dp[0][j] = a[0];
		}
		else {
			dp[0][j] = 0;
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10001; j++) {
			if (j >= b[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - b[i]] + a[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	for (int j = 0; j < 10001; j++) {
		if (dp[n-1][j] >= m) {
			cout << j;
			break;
		}
	}

}
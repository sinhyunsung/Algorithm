#include <iostream> 
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, m;

int circle[100001][2];
int dp[100001][3];

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> circle[i][0];
	}
	for (int i = 1; i <= n; i++) {
		cin >> circle[i][1];
	}

	int result = 200001;

	for (int k = 0; k < 4; k++) {

		fill_n(dp[0], 300003, 200001);

		bool a, b, c;
		if (circle[1][0] + circle[n][0] <= m) {
			a = true;
		}
		else {
			a = false;
		}
		if (circle[1][1] + circle[n][1] <= m) {
			b = true;
		}
		else {
			b = false;
		}

		if (k == 0) {
			dp[1][0] = 1;
			dp[1][1] = 1;
			if (circle[1][0] + circle[1][1] <= m) {
				dp[1][2] = 1;
			}
			else {
				dp[1][2] = 2;
			}
		}

		if (k == 1) {
			if (a) {
				dp[1][0] = 0;
				dp[1][1] = 1;
				dp[1][2] = 1;
			}
			else {
				continue;
			}
			
		}


		if (k == 2) {
			if (b) {
				dp[1][0] = 1;
				dp[1][1] = 0;
				dp[1][2] = 1;
			}
			else {
				continue;
			}

		}

		if (k == 3) {
			if (a&&b) {
				dp[2][0] = 1;
				dp[2][1] = 1;
				if (circle[2][0] + circle[2][1] <= m) {
					dp[2][2] = 1;
				}
				else {
					dp[2][2] = 2;
				}
			}
			else {
				continue;
			}

		}
		


		for (int i = 2; i <= n; i++) {
			if (circle[i][0] + circle[i - 1][0] <= m) {
				a = true;
			}
			else {
				a = false;
			}
			if (circle[i][1] + circle[i - 1][1] <= m) {
				b = true;
			}
			else {
				b = false;
			}
			if (circle[i][0] + circle[i][1] <= m) {
				c = true;
			}
			else {
				c = false;
			}

			if (a) {
				dp[i][0] = min(dp[i][0], dp[i - 1][1] + 1);
			}
			dp[i][0] = min(dp[i][0], dp[i - 1][2] + 1);

			if (b) {
				dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
			}
			dp[i][1] = min(dp[i][1], dp[i - 1][2] + 1);

			if (a && b && i > 2) {
				dp[i][2] = min(dp[i][2], dp[i - 2][2] + 2);
			}
			else if (a && b) {
				dp[i][2] = min(dp[i][2], 2);
			}

			if (c) {
				dp[i][2] = min(dp[i][2], dp[i - 1][2] + 1);
			}
			dp[i][2] = min(dp[i][2], dp[i][0] + 1);
			dp[i][2] = min(dp[i][2], dp[i][1] + 1);

		}

		if (k == 0) {
			result = min(result, dp[n][2]);
		}
		if (k == 1) {
			result = min(result, dp[n][1]+1);
		}
		if (k == 2) {
			result = min(result, dp[n][0]+1);
		}
		if (k == 3) {
			result = min(result, dp[n-1][2]+2);
		}
	}

	cout << result << "\n";

}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	int cs;
	cin >> cs;
	while (cs) {
		cs--;
		solve();
	}
}

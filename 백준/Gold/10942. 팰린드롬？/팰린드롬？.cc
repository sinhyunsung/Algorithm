#include <iostream> 
#include <string>


using namespace std;

int n;
int m[2001];

bool dp[2001][2001] = { 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; i + j < n; j++) {
			if (i == 0) {
				dp[j][i+j] = true;
				continue;
			}

			if (m[j] == m[j+i] && (dp[j + 1][j - 1 + i]|| i==1)) {
				dp[j][i+j] = true;
			}

		}
	}
	
	int cs;
	cin >> cs;

	int a, b;

	for (int i = 0; i < cs; i++) {
		cin >> a >> b;
		cout << dp[a - 1][b - 1] << "\n";
	}
}

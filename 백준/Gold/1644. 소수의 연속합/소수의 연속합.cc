#include <iostream> 
#include <string>
#include <vector>

using namespace std;

int n;
bool m[4000001] = { false };

vector<int> p;
int* dp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n;

	m[1] = true;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j * i <= n; j++) {
			m[j * i] = true;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (!m[i]) {
			p.push_back(i);
		}
	}

	int start =  0;
	int result = 0;
	if (!p.empty()) {

		dp = new int[p.size()];

		dp[0] = p[0];

		if (dp[0] == n) {
			result += 1;
		}

		for (int i = 1; i < p.size(); i++) {
			dp[i] = dp[i - 1] + p[i];
			if (dp[i] == n) {
				result += 1;
			}
			else if (dp[i] - dp[start] >= n) {
				while (dp[i] - dp[start] >= n) {
					if (dp[i] - dp[start] == n) {
						result += 1;
					}
					start += 1;
				}
			}
		}
	}
	cout << result;

}

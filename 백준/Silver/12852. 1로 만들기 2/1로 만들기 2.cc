#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int n;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();

	cin >> n;
	
	int dp[1000001];

	for (int i = 0; i < 1000001; i++) {
		dp[i] = i-1;
	}
	for (int i = 1; i < n+1; i++) {
		if (i * 2 < n+1 && dp[i*2]>dp[i]+1) {
			dp[i * 2] = dp[i] + 1;
		}
		if (i * 3 < n+1 && dp[i * 3] > dp[i] + 1) {
			dp[i * 3] = dp[i] + 1;
		}
		if (i + 1 < n+1 && dp[i +1] > dp[i] + 1) {
			dp[i +1] = dp[i] + 1;
		}
	}

	cout << dp[n] << "\n";

	deque<int> a;

	while (n != 1) {
		a.push_back(n);
		if (n % 3 == 0 && dp[n / 3] == dp[n] - 1) {
			n /= 3;
			continue;
		}
		if (n % 2 == 0 && dp[n / 2] == dp[n] - 1) {
			n /= 2;
			continue;
		}
		if ( dp[n - 1] == dp[n] - 1) {
			n -= 1;
			continue;
		}
	}
	
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << 1;
	





	
	
}
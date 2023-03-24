#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;

#define ll long long 


int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;

	int dp[100001];
	for (int i = 0; i <= n; i++) {
		dp[i] = i;
	}

	for (int i = 2; i * i <= n; i++) {
		for (int j = i * i; j <= n; j++) {
			dp[j] = min(dp[j], dp[j - i * i] + 1);
		}
	}

	cout << dp[n];

}



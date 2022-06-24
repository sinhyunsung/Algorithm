#include <iostream> 
#include <string>
#include <vector>
#include <queue>

using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	int cs;

	long long dp[30][30];

	int a, b;

	cin >> cs;


	fill_n(dp[0], 900, 0);

	for (int i = 0; i < 30; i++) {
		dp[i][i] = 1;
		dp[1][i] = i;
	}

	for (int i = 2; i < 30; i++) {
		for (int j = i + 1; j < 30; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j-1];
		}
	}


	while(cs) {
		cs--;


		cin >> a >> b;

		cout << dp[a][b]<<"\n";
		
	}

}

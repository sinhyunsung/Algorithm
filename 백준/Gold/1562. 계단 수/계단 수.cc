#include <iostream> 
#include <string>


using namespace std;

int n;
int*** dp;
int bit_in(int x, int b) {
	if (b == 0) {
		b = 10;
	}
	return x | (1 << (b-1));
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	
	cin >> n;
	dp = new int**[n];
	for (int i = 0; i < n; i++) {
		dp[i] = new int* [10];
		for (int j = 0; j < 10; j++) {
			dp[i][j] = new int[1024]{0};
		}
	}

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			for (int j = 1; j < 10; j++) {
				dp[i][j][bit_in(0, j)] = 1;
			}
			continue;
		}
		
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 1024; k++) {
				if (j != 0) {
					dp[i][j - 1][bit_in(k, j - 1)] += dp[i-1][j][k];
					dp[i][j - 1][bit_in(k, j - 1)] %= 1000000000;
				}
				if (j != 9) {
					dp[i][j + 1][bit_in(k, j + 1)] += dp[i-1][j][k];
					dp[i][j + 1][bit_in(k, j + 1)] %= 1000000000;
				}
			}
		}
	}

	int result = 0;
	for (int i = 0; i < 10; i++) {
		result += dp[n - 1][i][1023];
		result %= 1000000000;
	}
	cout << result;
	
}

#include <iostream>
#include <queue>
#include <vector>
#include <time.h>

#define ll long long

using namespace std;

int dp[51][51][51]={0};

int w(int a, int b, int c) {

	
	if (a <= 0 || b <= 0 || c <= 0) {
		
		return 1;
	}
	
	if (dp[a][b][c]) {
		return dp[a][b][c];
	}


	if (a > 20 || b > 20 || c > 20) {
		dp[20][20][20] = w(20, 20, 20);
		return dp[20][20][20];
	}

	if (a < b && b < c ) {
		dp[a][b][c - 1] = w(a, b, c - 1);
		dp[a][b-1][c - 1] = w(a, b-1, c - 1);
		dp[a-1][b-1][c - 1] = w(a-1, b-1, c - 1);

		return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a , b - 1, c );
	}
	dp[a-1][b][c] = w(a-1, b, c);
	dp[a-1][b - 1][c] = w(a-1, b - 1, c);
	dp[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);
	dp[a - 1][b][c - 1] = w(a - 1, b, c - 1);
	return w(a - 1, b, c-1) + w(a-1, b, c) + w(a-1, b - 1, c) - w(a - 1, b - 1, c - 1);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b, c;

	cin >> a >> b >> c;

	while (!(a == -1 && b == -1 && c == -1)) {
		cout <<"w("<<a<<", "<<b<<", "<<c<<") = "<< w(a, b, c) << "\n";
		cin >> a >> b >> c;
	}
}
#include <iostream>
#include <queue>
#include <vector>
#include <map>

#define ll long long

using namespace std;

int n;
int p[10];
int k;
int dp[51][10] = { 0 };

bool cn(int* prev,int* next,int target) {
	int prev_total = 0;
	int next_total = 1;

	bool prev_zero = true, next_zero = true;

	for (int i = 1; i <= 9; i++) {
		if (prev[i]) {
			prev_total += prev[i];
			prev_zero = false;
		}
		if (next[i]) {
			next_total += next[i];
			next_zero = false;
		}
	}
	if (target > 0) {
		next_zero = false;
	}

	prev_total += prev[0];
	next_total += next[0];

	if (prev_zero) {
		prev_total = 0;
		next_total = 0;
	}

	if (next_zero) {
		prev_total = 0;
		next_total = 0;
	}

	if (next_total > prev_total) {
		return true;
	}
	if (next_total < prev_total) {
		return false;
	}

	for (int i = 9; i >= 0; i--) {
		if (next[i] + (i == target) > prev[i]) {
			return true;
		}
		if (next[i] + (i == target) < prev[i]) {
			return false;
		}
	}

	return true;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	cin >> k;

	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < n; j++) {
			if (i >= p[j]) {
				if (cn(dp[i], dp[i - p[j]], j)) {
					for (int o = 0; o <= 9; o++) {
						dp[i][o] = dp[i - p[j]][o];
						if (o == j) {
							dp[i][o]++;
						}
					}
				}
			}
		}
	}

	bool only_zero = true;

	for (int i = 9; i >= 0; i--) {
		for (int j = dp[k][i]; j > 0; j--) {
			if (i>0 && only_zero) {
				only_zero = false;
			}
			if (i == 0 && only_zero) {
				cout << i;
				break;
			}
			cout << i;
		}
	}
	
}
#include <iostream>

using namespace std;

#define ll long long

int n;
int l[1000];
int result[1000];


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}

	int solve = 0;

	for (int i = 0; i < n; i++) {
		result[i] = l[i];
		for (int j = 0; j < i; j++) {
			if (l[i] > l[j]) {
				result[i] = max(result[i], result[j] + l[i]);
			}
		}
		solve = max(solve, result[i]);
	}
	cout << solve;
	

}
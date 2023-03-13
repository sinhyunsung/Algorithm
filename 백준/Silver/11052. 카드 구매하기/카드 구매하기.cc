#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

#define ll long long


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;

	int* m = new int[n+1];
	m[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> m[i];
	}

	int* money = new int[n+1];
	money[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j >= 1; j--) {
			money[i] = max(money[i], money[i - j] + m[j]);
		}
	}
	cout << money[n];
}
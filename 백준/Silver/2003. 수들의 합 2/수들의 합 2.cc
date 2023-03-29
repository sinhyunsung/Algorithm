#include <string>
#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
using namespace std;

#define ll long long

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;

	int k[10001];
	k[0] = 0;
	int b;
	for (int i = 1; i <= n; i++) {
		cin >> b;
		k[i] = k[i - 1] + b;
	}

	
	int result = 0;
	
	for (int i = 1; i <= n; i++) {
		if (k[i] < m) {
			continue;
		}
		for (int j = 0; j < i; j++) {
			if (k[i] - k[j] < m) {
				break;
			}
			if (k[i] - k[j] == m) {
				result++;
				continue;
			}

		}
	}

	cout << result;
}
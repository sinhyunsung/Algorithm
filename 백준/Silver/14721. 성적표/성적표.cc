#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <set>

using namespace std;

#define ll long long


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	ll x[100], y[100];
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	ll a, b;
	ll min_result = 100000000000;
	ll result;

	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {

			result = 0;
			for (int k = 0; k < n; k++) {
				result += pow(i * x[k] + j - y[k], 2);
			}
			if (min_result > result) {
				min_result = result;
				a = i;
				b = j;
			}

		}
	}

	cout << a << " " << b;
	
}

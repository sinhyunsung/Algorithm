#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <string>

using namespace std;

#define ll long long

int n;
int v[10000];
int sum[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		if (i == 0) {
			sum[i] = v[i];
			continue;
		}
		sum[i] = sum[i - 1] + v[i];
	}
	int result = 0;

	for (int i = 1; i < n - 1; i++) {
		result = max(result, 2 * sum[n - 1] - sum[0] - sum[i]-v[i]);
		result = max(result, sum[n - 2] + sum[i-1] - v[i]);
		result = max(result, sum[i]-v[0]+sum[n-2]-sum[i-1]);
	}

	cout << result;



}
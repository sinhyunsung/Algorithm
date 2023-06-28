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

void solve() {
	float n;
	cin >> n;
	float v[1000];
	float sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		sum += v[i];
	}
	sum /= n;

	float cnt = 0;
	for (int i = 0; i < n; i++) {
		if (sum < v[i]) {
			cnt++;
		}
	}

	cout << cnt / n * 100 << "%\n";

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int cs;
	cin >> cs;

	while (cs--) {
		solve();
	}

}
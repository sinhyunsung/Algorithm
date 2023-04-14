#include <vector>
#include <iostream>
#include <deque>
#include <algorithm>
#include <set>
#include <stack>
#include <bitset>
#include <queue>
#include <unordered_map>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> k;
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		k.push_back(make_pair(a, b));
	}

	sort(k.begin(), k.end());
	int min = 100001;
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (k[i].second < min) {
			result++;
			min = k[i].second;
		}
	}

	cout << result << "\n";
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
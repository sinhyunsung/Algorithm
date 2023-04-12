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

int n, m;
int v[200000];



int cnt(int dist) {
	int target = v[0];
	int count = 1;
	for (int i = 1; i < n; i++) {
		if (target + dist <= v[i]) {
			count++;
			target = v[i];
		}
	}
	return count;
}

void solve() {
	int left = 0;
	int right = (v[n - 1] - v[0]) / (m-1);

	while (left <= right) {
		int mid = (left + right) / 2;
		if (cnt(mid) >= m) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout<< right;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	sort(v, v + n);
	solve();

}
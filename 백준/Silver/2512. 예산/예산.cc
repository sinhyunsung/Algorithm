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

using namespace std;

#define ll long long

int n,m;
int v[10000];

int cal(int target) {
	int result = 0; 
	for (int i = 0; i < n; i++) {
		if (target >= v[i]) {
			result += v[i];
		}
		else {
			result += target;
		}
	}
	return result;
}

void solve() {
	int left = 0;
	int right = 1000000000/10000;
	while (left <= right) {
		int mid = (left + right) / 2;
		int result = cal(mid);
		if (m >= result) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	if (right == 100000) {
		int out = 0;
		for (int i = 0; i < n; i++) {
			out = max(out, v[i]);
		}
		cout << out;
		return;
	}
	cout << right;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cin >> m;
	solve();
	
	

	
}
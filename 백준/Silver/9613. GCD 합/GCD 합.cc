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

int n;
int v[100];
ll result;

int gcd(int x, int y) {
	while (y != 0) {
		int temp = x % y;
		x = y;
		y = temp;
	}
	return x;
}

void solve() {
	result = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			result += gcd(v[i], v[j]);
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
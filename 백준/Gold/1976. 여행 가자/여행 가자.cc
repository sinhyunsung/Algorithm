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

int n,m;
int v[200][200];
int conn[200];

int find(int target) {
	if (conn[target] == target) {
		return target;
	}
	else {
		conn[target] = find(conn[target]);
		return conn[target];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
		conn[i] = i;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j] == 1) {
				int a = find(i);
				int b = find(j);
				if (a != b) {
					conn[a] = min(a, b);
					conn[b] = min(a, b);
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		find(i);
	}
	int a,b;
	cin >> a;
	for (int i = 1; i < m; i++) {
		cin >> b;
		if (conn[a-1] != conn[b-1]) {
			cout << "NO";
			return 0;
		}
		a = b;
	}
	cout << "YES";
	


}
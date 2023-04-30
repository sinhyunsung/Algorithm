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

int v[7];
int n, m;

vector<int> q;

void dfs(int depth) {
	if (m == depth) {
		for (int i = 0; i < m; i++) {
			cout << q[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		q.push_back(v[i]);
		dfs(depth + 1);
		q.pop_back();
	}
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

	dfs(0);
	
}
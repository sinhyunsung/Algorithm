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
int v[8];
int visit[8] = { 0 };
void dfs(int depth,int idx) {
	if (depth == m) {
		for (int i = 0; i < n; i++) {
			if (visit[i]) {
				cout << v[i] << " ";
			}
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i + (m-depth) <= n; i++) {
		visit[i] = true;
		dfs(depth + 1,i+1);
		visit[i] = false;
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
	dfs(0,0);
}
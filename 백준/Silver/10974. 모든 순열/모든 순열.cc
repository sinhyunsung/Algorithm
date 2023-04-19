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

bool visit[8] = { 0 };
int n;
vector<int> q;

void dfs(int depth) {
	if (depth == n) {
		for (int i = 0; i < n; i++) {
			cout << q[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i - 1]) {
			q.push_back(i);
			visit[i - 1] = 1;
			dfs(depth + 1);
			q.pop_back();
			visit[i - 1] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	dfs(0);

}